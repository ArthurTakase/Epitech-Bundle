/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** HostHandler
*/

#pragma once
#include <NetworkLib/ISocket.hpp>
#include <string_view>
#include <vector>

/**
 * @brief get infos about the host from argc and argv
 *
 */
class HostHandler
{
  public:
    HostHandler() noexcept                         = delete;
    HostHandler(const HostHandler& other) noexcept = delete;
    HostHandler(HostHandler&& other) noexcept      = delete;
    ~HostHandler() noexcept                        = delete;

    HostHandler& operator=(const HostHandler& rhs) noexcept = delete;
    HostHandler& operator=(HostHandler&& rhs) noexcept      = delete;

    static Address       getHostAddress(std::vector<std::string>& av);
    static Address::Port getClientPort(std::vector<std::string>& av);
    static Address::Ip   getIp(std::string_view hostname);

  protected:
  private:
};
