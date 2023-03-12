/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#include <Client/UdpClient.hpp>
#include <Error/Error.hpp>
#include <NetworkLib/SocketFactory.hpp>
#include <NetworkLib/SocketSelectorFactory.hpp>
#include <Tools/Keyboard.hpp>
#include <iostream>
#include <memory>

/**
 * Constructor for my UDP client's class.
 * It initializes its socket, a deserializer, a game object, and two threads for its execution.
 * @param serverAddress The address of the server to connect to.
 * @param clientPort The port that the client will use to communicate with the
 * server.
 */
[[nodiscard]] UdpClient::UdpClient(Address serverAddress, Address::Port clientPort)
    : socket_(SocketFactory::createSocket(clientPort))
    , selector_(SocketSelectorFactory::createSocketSelector())
    , game_(dataReceived_, mutexForPacket_)
    , looping_(true)
{
    selector_->add(*socket_, true, true, false);
    serverInfos_.address = serverAddress;

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });
}

/**
 * Constructor for my UDP client's class.
 * It initializes its socket, a deserializer, a game object, and two threads for its execution.
 * @param clientPort The port that the client will use to communicate with the
 * server.
 */
[[nodiscard]] UdpClient::UdpClient(Address::Port clientPort)
    : socket_(SocketFactory::createSocket(clientPort))
    , selector_(SocketSelectorFactory::createSocketSelector())
    , game_(dataReceived_, mutexForPacket_)
    , looping_(false)
{
    selector_->add(*socket_, true, true, false);
    serverInfos_.address.port = 0;
    serverInfos_.address.ip   = 0;

    gameThread_    = std::thread([&]() { gameLoop(); });
    networkThread_ = std::thread([&]() { communicate(); });
}

/**
 * It stops the looping_ variable from being true.
 */
void UdpClient::stop() noexcept
{
    looping_ = false;
}

/**
 * It resets the looping_ variable to true.
 */
void UdpClient::reset() noexcept
{
    looping_ = true;
}

/**
 * The run function joins the game and network threads
 */
void UdpClient::run()
{
    networkThread_.join();
    gameThread_.join();
}

/**
 * It waits for data to be received or sent, and then calls the appropriate
 * function
 */
void UdpClient::communicate() noexcept
{
    if (serverInfos_.address.ip == 0 || serverInfos_.address.port == 0) {
        std::unique_lock<std::mutex> lock(mutexForNetworkThread_);
        cv_.wait(lock);
    }

    dataToSend_.push({PING});
    while (looping_) {
        try {
            selector_->select(true, true, false);
        } catch (const NetworkError& message) {
            std::cerr << message.what() << std::endl;
        }
        if (selector_->isSet(*socket_, SocketSelector::Operation::READ)) { receive(); }
        if (selector_->isSet(*socket_, SocketSelector::Operation::WRITE)) { send(); }

        checkServerConnection();
    }
}

/**
 * It runs the game loop, and when the user presses the escape key, it sends a
 * CLOSE_VALUE to the server
 */
void UdpClient::gameLoop() noexcept
{
    auto& lib = game_.getLib();
    lib.getWindow().open(WIDTH_WINDOW, HEIGHT_WINDOW, WINDOW_NAME.data());

    if (serverInfos_.address.ip == 0 || serverInfos_.address.port == 0) {
        try {
            serverInfos_.address = menu_.run(lib.getWindow());
            reset();
            cv_.notify_all();
        } catch (const Error& e) {
            std::cerr << e.what() << std::endl;
            stop();
            cv_.notify_all();
            isFirstConnection_ = false;
        }
    }

    while (isFirstConnection_) {
        std::unique_lock<std::mutex> lock(mutexForGameThread_);
        cvGame_.wait(lock);
    }

    while (looping_) {
        auto input = lib.getWindow().getKeyPressed();
        if (input == Input::Exit) {
            stop();
            break;
        }
        if (input != 0) { dataToSend_.push({static_cast<uint8_t>(input)}); }
        game_.run();
    }

    dataToSend_.push({CLOSE_VALUE});
    lib.getWindow().close();
}

/**
 * It receives data from the socket and handles it
 */
void UdpClient::receive()
{
    try {
        ReceivedInfos infoReceived = socket_->receive();
        handleData(infoReceived);
    } catch (const NetworkError& e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * If there's data to send, send it
 */
void UdpClient::send()
{
    if (dataToSend_.size() != 0) {
        auto blob = getDataFromQueue();
        try {
            socket_->send(blob.data(), blob.size(), serverInfos_.address);
        } catch (const NetworkError& e) {
            std::cerr << e.what() << std::endl;
            dataToSend_.push(blob);
        }
    }
}

/**
 * It returns the first element of the queue and removes it from the queue.
 *
 * @return A RawData object.
 */
RawData UdpClient::getDataFromQueue() noexcept
{
    RawData blob = dataToSend_.front();
    dataToSend_.pop();
    return (blob);
}

/**
 * It takes a vector of bytes, and if the size of the vector is a multiple of 12,
 * it will create a GamePacket for each 12 bytes, and push it into a queue
 *
 * @param infos the data received
 *
 * @return A vector of bytes
 */
void UdpClient::handleData(ReceivedInfos infos) noexcept
{
    serverInfos_.lastPing = clock_.getActualTime();

    if (infos.data.size() == 0) { return; }
    if (infos.data.size() == 1) {
        int value = infos.data[0];
        if (value == Input::Exit) {
            stop();
            auto& lib = game_.getLib();
            lib.getWindow().close();
        }
        if (value == PING) { dataToSend_.push({PONG}); }
        if (value == PONG) {
            if (isFirstConnection_) {
                cvGame_.notify_all();
                isFirstConnection_ = false;
                std::cout << "Connected to server" << std::endl;
            }
            serverInfos_.isPingSent = false;
        }

    } else {
        if (infos.data.size() >= MUSIC_NB && (infos.data.size() - MUSIC_NB) % PACKET_SIZE == 0) {
            auto& manager = game_.getManager();

            for (int m = 0; m < MUSIC_NB; m++) {
                if (infos.data[m]) {
                    auto sound = manager.getEntity(m)->getComponent<SoundComponent>();
                    if (sound) sound->setPlayed(true);
                }
            }

            for (int i = MUSIC_NB; i < infos.data.size(); i += PACKET_SIZE) {
                GamePacket packet;
                packet.x         = infos.data[i + PacketName::X1] | (infos.data[i + PacketName::X2] << 8);
                packet.y         = infos.data[i + PacketName::Y1] | (infos.data[i + PacketName::Y2] << 8);
                packet.x         = infos.data[i + PacketName::XPOSITIVE] ? packet.x : -packet.x;
                packet.y         = infos.data[i + PacketName::YPOSITIVE] ? packet.y : -packet.y;
                packet.idSprite  = infos.data[i + PacketName::ID_SPRITE];
                packet.width     = infos.data[i + PacketName::WIDTH];
                packet.height    = infos.data[i + PacketName::HEIGHT];
                packet.scaleX    = infos.data[i + PacketName::SCALE_X] / 10;
                packet.scaleY    = infos.data[i + PacketName::SCALE_Y] / 10;
                packet.offsetX   = infos.data[i + PacketName::OFFSET_X];
                packet.offsetY   = infos.data[i + PacketName::OFFSET_Y];
                packet.id        = infos.data[i + PacketName::ID1] | (infos.data[i + PacketName::ID2] << 8);
                packet.destroyed = infos.data[i + PacketName::DESTROYED];
                {
                    std::lock_guard<std::mutex> lock(mutexForPacket_);
                    dataReceived_.push(packet);
                }
            }
        }
    }
}

/**
 * It checks if the server is still connected to the client
 */
void UdpClient::checkServerConnection() noexcept
{
    clock_.setActualTime(std::chrono::high_resolution_clock::now());

    auto timelapse = std::chrono::duration_cast<std::chrono::seconds>(clock_.getActualTime() - serverInfos_.lastPing);
    if (timelapse >= std::chrono::seconds(MAX_TIMEOFF)) {
        if (serverInfos_.isPingSent) {
            std::cout << "Connection to the server failed" << std::endl;
            cvGame_.notify_all();
            stop();
            isFirstConnection_ = false;
        } else {
            std::cout << "Trying to connect to the server" << std::endl;
            serverInfos_.isPingSent = true;
            serverInfos_.lastPing   = clock_.getActualTime();
            dataToSend_.push({PING});
        }
    }
}
