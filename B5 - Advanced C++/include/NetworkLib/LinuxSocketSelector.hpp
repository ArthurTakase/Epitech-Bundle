/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxSocketSelector
*/

#pragma once

#include <NetworkLib/SocketSelector.hpp>

#ifdef __linux__
#include <sys/select.h>

#include <NetworkLib/LinuxSocket.hpp>
#include <functional>

/**
 * @brief Encapsulate a fd_set for Linux and handle manipulations
 *
 */
class LinuxFdSet
{
  public:
    LinuxFdSet() noexcept;
    LinuxFdSet(const LinuxFdSet& other) noexcept = default;
    LinuxFdSet(LinuxFdSet&& other) noexcept      = default;
    ~LinuxFdSet() noexcept                       = default;

    LinuxFdSet& operator=(const LinuxFdSet& rhs) noexcept = default;
    LinuxFdSet& operator=(LinuxFdSet&& rhs) noexcept      = default;

    fd_set& get() noexcept;
    void    add(int fd) noexcept;
    void    remove(int fd) noexcept;
    bool    isSet(int fd) const noexcept;
    int     select() noexcept;
    void    clear() noexcept;

  protected:
  private:
    fd_set fdSet_;
};

/**
 * @brief Encapsulate a select for Linux and handle manipulations
 *
 */
class LinuxSocketSelector : public SocketSelector
{
  public:
    LinuxSocketSelector() noexcept                                 = default;
    LinuxSocketSelector(const LinuxSocketSelector& other) noexcept = delete;
    LinuxSocketSelector(LinuxSocketSelector&& other) noexcept      = default;
    ~LinuxSocketSelector() noexcept                                = default;

    LinuxSocketSelector& operator=(const LinuxSocketSelector& rhs) noexcept = delete;
    LinuxSocketSelector& operator=(LinuxSocketSelector&& rhs) noexcept      = default;

    void add(ISocket& socket, bool isRead, bool isWrite, bool isExcept) final;
    void remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept) final;
    bool isSet(ISocket& socket, Operation type) const final;
    void select(bool isRead, bool isWrite, bool isExcept) final;
    void clear(bool isRead, bool isWrite, bool isExcept) noexcept final;

  protected:
  private:
    int        nfds_ = 0;
    LinuxFdSet readFds_;
    LinuxFdSet writeFds_;
    LinuxFdSet exceptFds_;
    LinuxFdSet readyReadFds_;
    LinuxFdSet readyWriteFds_;
    LinuxFdSet readyExceptFds_;

    std::vector<std::reference_wrapper<LinuxSocket>> sockets_;
};
#endif
