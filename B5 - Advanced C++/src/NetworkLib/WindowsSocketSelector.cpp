/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WindowsSocketSelector
*/

#ifdef WIN32
#include <Error/Error.hpp>
#include <NetworkLib/WindowsSocketSelector.hpp>

/**
 * Initialize the windows fd_set structure to contain no file descriptors.
 */
WindowsFdSet::WindowsFdSet() noexcept
{
    FD_ZERO(&fdSet_);
}

/**
 * This function returns a reference to the underlying fd_set object.
 *
 * @return A reference to the fdSet_ member variable.
 */
fd_set& WindowsFdSet::get() noexcept
{
    return (fdSet_);
}

/**
 * Add the given file descriptor to the set.
 *
 * @param fd The file descriptor to add to the set.
 */
void WindowsFdSet::add(int fd) noexcept
{
    FD_SET(fd, &fdSet_);
}

/**
 * If the given file descriptor is in the set, remove it.
 *
 * @param fd The file descriptor to add to the set.
 */
void WindowsFdSet::remove(int fd) noexcept
{
    FD_CLR(fd, &fdSet_);
}

/**
 * If the file descriptor is set, return true, otherwise return false.
 *
 * @param fd The file descriptor to check.
 *
 * @return A reference to the fd_set object.
 */
bool WindowsFdSet::isSet(int fd) const noexcept
{
    return (FD_ISSET(fd, &fdSet_));
}

/**
 * Clear the fd_set structure.
 */
void WindowsFdSet::clear() noexcept
{
    FD_ZERO(&fdSet_);
}

/**
 * It adds a socket to the selector
 *
 * @param socket The socket to add to the selector.
 * @param isRead If true, the socket will be checked for readability.
 * @param isWrite If true, the socket will be checked for writability.
 * @param isExcept This parameter is not used on Windows.
 */
void WindowsSocketSelector::add(ISocket& socket, bool isRead, bool isWrite, bool isExcept)
{
    auto windowsSocket = dynamic_cast<WindowsSocket*>(&socket);
    if (windowsSocket == nullptr) throw NetworkError("Error while using the socket with select.");

    if (isRead) readFds_.add(windowsSocket->getSocketFd());
    if (isWrite) writeFds_.add(windowsSocket->getSocketFd());
    if (isExcept) exceptFds_.add(windowsSocket->getSocketFd());

    sockets_.push_back(*windowsSocket);
    if (nfds_ < windowsSocket->getSocketFd() + 1) nfds_ = windowsSocket->getSocketFd() + 1;
}

/**
 * It removes the socket from the list of sockets to be monitored by the selector
 *
 * @param socket The socket to be added to the selector.
 * @param isRead If true, the socket will be checked for readability.
 * @param isWrite If true, the socket will be checked for writability.
 * @param isExcept If true, the socket will be checked for exceptional conditions.
 *
 * @return A reference to the socket.
 */
void WindowsSocketSelector::remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept)
{
    auto windowsSocket = dynamic_cast<WindowsSocket*>(&socket);
    if (windowsSocket == nullptr) throw NetworkError("Error while using the socket with select.");

    if (isRead) readFds_.remove(windowsSocket->getSocketFd());
    if (isWrite) writeFds_.remove(windowsSocket->getSocketFd());
    if (isExcept) exceptFds_.remove(windowsSocket->getSocketFd());

    auto it = std::find_if(sockets_.begin(), sockets_.end(), [&windowsSocket](auto& socket) {
        return (socket.get().getSocketFd() == windowsSocket->getSocketFd());
    });
    if (it != sockets_.end()) {
        sockets_.erase(it);
        it = std::max_element(sockets_.begin(), sockets_.end(), [](auto& socket1, auto& socket2) {
            return (socket1.get().getSocketFd() < socket2.get().getSocketFd());
        });
        if (it != sockets_.end()) nfds_ = it->get().getSocketFd() + 1;
    }
}

/**
 * It checks if the socket is set in the corresponding set of sockets
 *
 * @param socket The socket to check.
 * @param type The type of operation to check for.
 *
 * @return A boolean value.
 */
bool WindowsSocketSelector::isSet(ISocket& socket, Operation type) const
{
    auto windowsSocket = dynamic_cast<WindowsSocket*>(&socket);
    if (windowsSocket == nullptr) throw NetworkError("Error while using the socket with select.");

    if (type == Operation::READ) return (readyReadFds_.isSet(windowsSocket->getSocketFd()));
    if (type == Operation::WRITE) return (readyWriteFds_.isSet(windowsSocket->getSocketFd()));
    if (type == Operation::EXCEPTION) return (readyExceptFds_.isSet(windowsSocket->getSocketFd()));
    return (false);
}

/**
 * It clears the specified sets of sockets
 *
 * @param isRead If true, the readFds_ set will be cleared.
 * @param isWrite If true, the writeFds_ set will be cleared.
 * @param isExcept Whether to clear the exception set.
 */
void WindowsSocketSelector::clear(bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.clear();
    if (isWrite) writeFds_.clear();
    if (isExcept) exceptFds_.clear();
}

void WindowsSocketSelector::select(bool isRead, bool isWrite, bool isExcept)
/**
 * It takes the read, write, and exception file descriptors and checks if they are
 * ready to be read, written to, or have an exception
 *
 * @param isRead If true, the select function will check if the socket is ready to
 * read.
 * @param isWrite If true, the select function will check if the socket is ready to
 * write.
 * @param isExcept If true, the exceptFds_ will be checked for exceptions.
 */
{
    readyReadFds_   = readFds_;
    readyWriteFds_  = writeFds_;
    readyExceptFds_ = exceptFds_;

    int status = ::select(nfds_,
        (isRead ? &readyReadFds_.get() : nullptr),
        (isWrite ? &readyWriteFds_.get() : nullptr),
        (isExcept ? &readyExceptFds_.get() : nullptr),
        nullptr);
    if (status < 0) { throw NetworkError("Error while using the socket with select."); }
}

#endif
