/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Socket
*/

#pragma once

#ifdef WIN32
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <NetworkLib/ISocket.hpp>
#include <string_view>

class WindowsSocketSelector;

/**
 * @brief UDP Socket for windows
 *
 */
class WindowsSocket : public ISocket
{
    friend class WindowsSocketSelector;

  public:
    explicit WindowsSocket(Address::Port port);

    WindowsSocket(const WindowsSocket& other) noexcept = delete;
    WindowsSocket(WindowsSocket&& other) noexcept      = default;
    ~WindowsSocket() noexcept;

    WindowsSocket& operator=(const WindowsSocket& rhs) noexcept = delete;
    WindowsSocket& operator=(WindowsSocket&& rhs) noexcept      = default;

    [[nodiscard]] Address       getAddress() const noexcept final;
    void                        send(const void* data, int data_size, Address client_address) const final;
    [[nodiscard]] ReceivedInfos receive() final;

  protected:
    Fd getSocketFd() const noexcept;

  private:
    SOCKET            socketFd_;
    SOCKADDR_IN       address_;
    std::vector<char> receivedBuffer_;

    static constexpr std::size_t MAX_RECEIVED_BUFFER_SIZE = 1024;

    static Address     winAddressToAddress(SOCKADDR_IN address) noexcept;
    static SOCKADDR_IN addressToWinAddress(Address address) noexcept;
};

#endif
