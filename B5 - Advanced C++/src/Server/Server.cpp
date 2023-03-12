/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#include <ECS/Components/InputComponent.hpp>
#include <ECS/Components/SoundComponent.hpp>
#include <Error/Error.hpp>
#include <NetworkLib/ISocket.hpp>
#include <NetworkLib/SocketFactory.hpp>
#include <NetworkLib/SocketSelectorFactory.hpp>
#include <Server/Server.hpp>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <locale>

/**
 * It creates a socket and a selector, adds the socket to the selector, and starts
 * the game and network threads
 *
 * @param port The port to listen on.
 */
[[nodiscard]] Server::Server(Address::Port port)
    : socket_(SocketFactory::createSocket(port))
    , selector_(SocketSelectorFactory::createSocketSelector())
{
    selector_->add(*socket_, true, true, false);

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });
}

/**
 * It stops the server
 */
void Server::stop() noexcept
{
    looping_ = false;
    gameInstance_.stop();
}

/**
 * It resets the server to its initial state.
 */
void Server::reset() noexcept
{
    looping_ = true;
}

/**
 * The run function joins the game and network threads.
 */
void Server::run()
{
    gameThread_.join();
    networkThread_.join();
}

/**
 * It waits for a client to connect, then it waits for a client to send a message,
 * then it sends a message to the client, then it checks if the client is still
 * connected
 */
void Server::communicate() noexcept
{
    while (looping_) {
        try {
            selector_->select(true, true, false);
        } catch (const NetworkError& message) {
            std::cerr << message.what() << std::endl;
        }
        if (selector_->isSet(*socket_, SocketSelector::Operation::READ)) { receive(); }
        if (selector_->isSet(*socket_, SocketSelector::Operation::WRITE)) { send(); }

        areClientsConnected();
    }
}

/**
 * It runs the game loop, and sends the data to the clients
 */
void Server::gameLoop() noexcept
{
    gameInstance_.init();

    while (looping_) {
        clock_.setEnd(std::chrono::high_resolution_clock::now());
        if (std::chrono::duration_cast<std::chrono::milliseconds>(clock_.getEnd() - clock_.getStart()).count()
            >= tickrate_) {
            clock_.setStart(std::chrono::high_resolution_clock::now());

            if (clients_.size() == 0 && gameInstance_.getManager().getEntities().size() == 0) {
                stop();
            } else {
                auto&   entities = gameInstance_.getManager().getEntities();
                RawData dataToSend;
                dataToSend.reserve(entities.size() * PACKET_SIZE);
                for (auto& entity : entities) {
                    if (entity->hasComponents<DrawableComponent, TransformComponent>()) {
                        RawData serializedData = Serializer::serialize(entity);
                        dataToSend.insert(dataToSend.end(), serializedData.begin(), serializedData.end());
                    } else if (entity->hasComponent<SoundComponent>()) {
                        RawData serializedData = Serializer::serializeMusic(entity);
                        dataToSend.insert(dataToSend.end(), serializedData.begin(), serializedData.end());
                    }
                }

                if (dataToSend.size() == 0) { dataToSend.emplace_back(CLOSE_VALUE); }
                for (auto& client : clients_) { client.dataToSend.push(dataToSend); }

                gameInstance_.run();
            }
        }
    }
}

/**
 * It receives data from the client, checks if the client is known, if it is not,
 * it adds it to the list of clients, and then handles the data received from it
 *
 * @return A reference to the player with the given address.
 */
void Server::receive()
{
    clock_.setLastPing(std::chrono::high_resolution_clock::now());
    try {
        ReceivedInfos infoReceived = socket_->receive();
        if (!isKnownClient(infoReceived.address)) {
            if (players_.size() >= MAX_PLAYERS) { return; }
            addClient(infoReceived.address, clock_.getLastPing());
        }
        for (auto& client : clients_) {
            if (client.address == infoReceived.address) { client.lastPing = clock_.getLastPing(); }
        }
        handleData(infoReceived);
    } catch (const Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * If there's data to send, send it
 */
void Server::send() noexcept
{
    for (auto& client : clients_) {
        if (client.dataToSend.size() != 0) { sendToClient(client, getDataFromQueue(client)); }
    }
}

/**
 * It sends a blob of data to a client
 *
 * @param client the client to send the data to
 * @param blob the data to send
 */
void Server::sendToClient(Client& client, RawData blob) // blob : binary large object
{
    try {
        socket_->send(blob.data(), blob.size(), client.address);
    } catch (const Error& e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Get the first element of the queue and return it.
 *
 * @param client The client to get the data from.
 *
 * @return A reference to the client object.
 */
RawData Server::getDataFromQueue(Client& client) noexcept
{
    RawData blob = client.dataToSend.front();
    client.dataToSend.pop();
    return (blob);
}

/**
 * It handles the data received from the client
 *
 * @param infos a struct containing the address of the client and the data received
 *
 * @return A reference to the player with the given address.
 */
void Server::handleData(ReceivedInfos infos) noexcept
{
    if (infos.data.size() == 0) { return; }

    if (infos.data[0] == CLOSE_VALUE) { removeClient(infos.address); }
    if (infos.data[0] == PING) { updateClientState(infos.address, true); }
    if (infos.data[0] == PONG) { updateClientState(infos.address, false); }
    for (auto& player : players_) {
        if (player.address != infos.address) continue;
        for (auto& ent : player.entities_id) {
            auto entity = gameInstance_.getManager().getEntity(ent);
            if (!entity) {
                player.entities_id.erase(
                    std::remove(player.entities_id.begin(), player.entities_id.end(), ent), player.entities_id.end());
                break;
            }
            if (!entity->hasComponent<InputComponent>()) continue;
            auto input = entity->getComponent<InputComponent>();
            for (auto& i : infos.data) { input->addInput(static_cast<int>(i)); }
        }
    }

    infos.data.clear();
}

/**
 * Return true if the given address is known to the server.
 *
 * @param address The address of the client to check.
 *
 * @return A reference to the client with the given address.
 */
bool Server::isKnownClient(Address address) const
{
    auto iterator = std::find_if(
        clients_.begin(), clients_.end(), [&address](const Client& client) { return (address == client.address); });
    return (iterator != clients_.end());
}

/**
 * It adds a new client to the server
 *
 * @param address The address of the client
 * @param ping The time the client sent the ping
 */
void Server::addClient(Address address, std::chrono::high_resolution_clock::time_point ping) noexcept
{
    Client client{.address = address, .lastPing = ping};
    clients_.push_back(client);

    int    size   = players_.size();
    Player player = {.address = address, .entities_id = {gameInstance_.createPlayer(20, 70 + (30 * size), size + 1)}};
    players_.emplace_back(player);

    std::cout << "New client connected" << std::endl;
}

/**
 * It removes a client from the server
 *
 * @param clientAddress The address of the client to remove.
 *
 * @return A reference to the client.
 */
void Server::removeClient(Address& clientAddress) noexcept
{
    auto iterator = std::find_if(clients_.begin(), clients_.end(), [&clientAddress](const Client& client) {
        return (clientAddress == client.address);
    });
    if (iterator != clients_.end()) {
        clients_.erase(iterator);
        for (auto& player : players_) {
            if (player.address != clientAddress) continue;
            for (auto& ent : player.entities_id) {
                auto entity = gameInstance_.getManager().getEntity(ent);
                if (!entity->hasComponent<DestroyableComponent>()) continue;
                entity->getComponent<DestroyableComponent>()->destroy();
            }
            player.entities_id.clear();
        }
        players_.erase(std::remove_if(players_.begin(),
                           players_.end(),
                           [&clientAddress](const Player& player) { return (clientAddress == player.address); }),
            players_.end());
    }
}

/**
 * If a client hasn't sent a ping in a while, send a ping to the client. If the
 * client doesn't respond to the ping, disconnect the client
 */
void Server::areClientsConnected() noexcept
{
    clock_.setActualTime(std::chrono::high_resolution_clock::now());

    for (auto& client : clients_) {
        auto timelapse = std::chrono::duration_cast<std::chrono::seconds>(clock_.getActualTime() - client.lastPing);
        if (timelapse >= std::chrono::seconds(MAX_TIMEOFF)) {
            if (client.isPingSent) {
                std::cout << "Client disconnected" << std::endl;
                removeClient(client.address);
            } else {
                std::cout << "Trying to send ping to client" << std::endl;
                client.isPingSent = true;
                client.lastPing   = clock_.getActualTime();
                client.dataToSend.push({PING});
            }
        }
    }
}

/**
 * If the client is found in the clients_ vector, set the isPingSent flag to false
 * and if the client sent a ping, send a pong back
 *
 * @param clientAddress The address of the client that sent the message.
 * @param isPing true if the packet is a ping, false if it's a pong
 *
 * @return A reference to the client's data to send.
 */
void Server::updateClientState(Address& clientAddress, bool isPing) noexcept
{
    auto iterator = std::find_if(clients_.begin(), clients_.end(), [&clientAddress](const Client& client) {
        return (clientAddress == client.address);
    });
    if (iterator != clients_.end()) { iterator->isPingSent = false; }
    if (isPing) { iterator->dataToSend.push({PONG}); }
}
