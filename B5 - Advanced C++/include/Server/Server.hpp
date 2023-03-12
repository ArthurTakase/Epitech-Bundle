/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server
*/

#pragma once

#include <NetworkLib/ISocket.hpp>
#include <NetworkLib/SocketSelector.hpp>
#include <Serializer/BitSize.hpp>
#include <Serializer/Serializer.hpp>
#include <Server/RType.hpp>
#include <Time/Clock.hpp>
#include <memory>
#include <thread>
#include <vector>

/**
 * @brief struct that contains the client's address and a vector of entities' id relative to each player.
 *
 */
typedef struct Player {
    Address          address;
    std::vector<int> entities_id;
} Player;

/**
 * @brief Server class using UDP protocol
 *
 */
class Server
{
  public:
    static constexpr unsigned int SERVER_PORT = 4242;

  public:
    Server() noexcept = delete;
    explicit Server(Address::Port port);

    Server(const Server& other) noexcept = delete;
    Server(Server&& other) noexcept      = delete;
    ~Server() noexcept                   = default;

    Server& operator=(const Server& rhs) noexcept = delete;
    Server& operator=(Server&& rhs) noexcept      = delete;

    void run();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    // attributes
    bool                            looping_ = true;
    unsigned int                    tickrate_ = 60;
    std::vector<Client>             clients_ = {};
    std::unique_ptr<ISocket>        socket_;
    std::unique_ptr<SocketSelector> selector_;
    std::thread                     gameThread_;
    std::thread                     networkThread_;
    RType                           gameInstance_;
    std::vector<Player>             players_;
    Clock                           clock_;

    // methods
    void                  receive();
    void                  send() noexcept;
    void                  sendToClient(Client& client, RawData blob);
    bool                  isKnownClient(Address address) const;
    void                  removeClient(Address& clientAddress) noexcept;
    void                  addClient(Address address, std::chrono::high_resolution_clock::time_point ping) noexcept;
    void                  updateClientState(Address& clientAddress, bool isPing) noexcept;
    void                  areClientsConnected() noexcept;
    void                  handleData(ReceivedInfos infos) noexcept;
    [[nodiscard]] RawData getDataFromQueue(Client& client) noexcept;

    // thread methods
    void communicate() noexcept;
    void gameLoop() noexcept;
};
