/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ISocket
*/

#pragma once
#include <chrono>
#include <cstdint>
#include <memory>
#include <queue>

/**
 * @brief Encapsulate an address
 *
 */
struct Address {
    using Port = std::uint16_t;
    using Ip   = std::uint32_t;

    Port port;
    Ip   ip;
};

/**
 * @brief Compare two Address
 *
 * @param lhs
 * @param rhs
 * @return true
 * @return false
 */
inline bool operator==(const Address& lhs, const Address& rhs) noexcept
{
    return (lhs.port == rhs.port && lhs.ip == rhs.ip);
}

using RawData = std::vector<std::uint8_t>;

/**
 * @brief Encapsulate a received data and the address of the sender
 *
 */
struct ReceivedInfos {
    RawData data;
    Address address;
};

/**
 * @brief Encapsulate a client address and the data to send
 *
 */
struct Client {
    Address                               address;
    std::queue<RawData>                   dataToSend = {};
    std::chrono::high_resolution_clock::time_point lastPing   = {};
    bool                                  isPingSent = false;
};

/**
 * @brief Encapsulate a server address and the last time a ping was sent
 *
 */
struct ServerInfos {
    Address                               address;
    std::chrono::high_resolution_clock::time_point lastPing   = {};
    bool                                  isPingSent = false;
};

/**
 * @brief Interface for an UDP socket
 *
 */
class ISocket
{
  public:
    using Fd = std::int32_t;

  public:
    ISocket() noexcept                     = default;
    ISocket(const ISocket& other) noexcept = delete;
    ISocket(ISocket&& other) noexcept      = default;
    virtual ~ISocket() noexcept            = default;

    ISocket& operator=(const ISocket& rhs) noexcept = delete;
    ISocket& operator=(ISocket&& rhs) noexcept      = default;

    virtual Address       getAddress() const noexcept                                         = 0;
    virtual void          send(const void* data, int data_size, Address client_address) const = 0;
    virtual ReceivedInfos receive()                                                           = 0;

  protected:
  private:
};
