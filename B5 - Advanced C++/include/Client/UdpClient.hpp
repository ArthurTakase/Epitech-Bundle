/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** UdpClient
*/

#pragma once

#include <Client/Game.hpp>
#include <Client/Menu.hpp>
#include <NetworkLib/ISocket.hpp>
#include <NetworkLib/SocketSelector.hpp>
#include <Serializer/BitSize.hpp>
#include <Time/Clock.hpp>
#include <condition_variable>
#include <memory>
#include <thread>

/**
 * @brief Client class using UDP protocol
 *
 */
class UdpClient
{
  public:
    UdpClient() noexcept = delete;
    explicit UdpClient(Address serverAddress, Address::Port clientPort);
    explicit UdpClient(Address::Port clientPort);

    UdpClient(const UdpClient& other) noexcept = delete;
    UdpClient(UdpClient&& other) noexcept      = delete;
    ~UdpClient() noexcept                      = default;

    UdpClient& operator=(const UdpClient& rhs) noexcept = delete;
    UdpClient& operator=(UdpClient&& rhs) noexcept      = delete;

    void run();
    void stop() noexcept;
    void reset() noexcept;

  protected:
  private:
    // attributes
    bool                            looping_;
    bool                            isFirstConnection_ = true;
    std::unique_ptr<ISocket>        socket_;
    std::unique_ptr<SocketSelector> selector_;
    std::thread                     gameThread_;
    std::thread                     networkThread_;
    std::queue<RawData>             dataToSend_            = {};
    std::queue<GamePacket>          dataReceived_          = {};
    std::mutex                      mutexForPacket_        = {};
    std::mutex                      mutexForNetworkThread_ = {};
    std::mutex                      mutexForGameThread_    = {};
    std::condition_variable         cv_;
    std::condition_variable         cvGame_;
    Game                            game_;
    Menu                            menu_;
    Clock                           clock_;
    ServerInfos                     serverInfos_ = {};

    static constexpr int              CLOSE_VALUE   = 255;
    static constexpr int              WIDTH_WINDOW  = 256;
    static constexpr int              HEIGHT_WINDOW = 256;
    static constexpr std::string_view WINDOW_NAME   = "Client R-Type";

    // methods
    void    receive();
    void    send();
    void    handleData(ReceivedInfos infos) noexcept;
    RawData getDataFromQueue() noexcept;
    void    checkServerConnection() noexcept;
    void    firstConnection() noexcept;
    void    communicate() noexcept;
    void    gameLoop() noexcept;
};
