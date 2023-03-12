/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SocketSelector class to encapsulate fd_set and select
*/

#pragma once

#include <NetworkLib/ISocket.hpp>

/**
 * @brief Interface for SocketSelector
 *
 */
class SocketSelector
{
  public:
    enum class Operation { READ, WRITE, EXCEPTION };

  public:
    SocketSelector() noexcept                            = default;
    SocketSelector(const SocketSelector& other) noexcept = default;
    SocketSelector(SocketSelector&& other) noexcept      = default;
    virtual ~SocketSelector() noexcept                   = default;

    SocketSelector& operator=(const SocketSelector& rhs) noexcept = default;
    SocketSelector& operator=(SocketSelector&& rhs) noexcept      = default;

    virtual void add(ISocket& socket, bool isRead, bool isWrite, bool isExcept)    = 0;
    virtual void remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept) = 0;
    virtual bool isSet(ISocket& socket, Operation type) const                      = 0;
    virtual void select(bool isRead, bool isWrite, bool isExcept)                  = 0;
    virtual void clear(bool isRead, bool isWrite, bool isExcept) noexcept          = 0;

  protected:
  private:
};