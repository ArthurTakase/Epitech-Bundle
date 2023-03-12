/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SocketFactory
*/

#pragma once
#include <NetworkLib/ISocket.hpp>

/**
 * @brief Factory for socket
 *
 */
class SocketFactory
{
  public:
    SocketFactory() noexcept                           = delete;
    SocketFactory(const SocketFactory& other) noexcept = delete;
    SocketFactory(SocketFactory&& other) noexcept      = delete;
    ~SocketFactory() noexcept                          = delete;

    SocketFactory& operator=(const SocketFactory& rhs) noexcept = delete;
    SocketFactory& operator=(SocketFactory&& rhs) noexcept      = delete;

    static std::unique_ptr<ISocket> createSocket(Address::Port port);

  protected:
  private:
};