/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxSocketSelector
*/

#ifdef __linux__
#include <Error/Error.hpp>
#include <NetworkLib/LinuxSocketSelector.hpp>

/**
 * Initialize the fd_set to contain no file descriptors.
 */
LinuxFdSet::LinuxFdSet() noexcept
{
    FD_ZERO(&fdSet_);
}

/**
 * This function returns a reference to the underlying fd_set object.
 *
 * @return A reference to the fd_set object.
 */
fd_set& LinuxFdSet::get() noexcept
{
    return (fdSet_);
}

/**
 * Add the given file descriptor to the set.
 *
 * @param fd The file descriptor to add to the set.
 */
void LinuxFdSet::add(int fd) noexcept
{
    FD_SET(fd, &fdSet_);
}

/**
 * Remove the given file descriptor from the set.
 *
 * @param fd The file descriptor to add to the set.
 */
void LinuxFdSet::remove(int fd) noexcept
{
    FD_CLR(fd, &fdSet_);
}

/**
 * If the file descriptor is set, return true, otherwise return false.
 *
 * @param fd The file descriptor to check.
 *
 * @return A boolean of the fd_set state.
 */
bool LinuxFdSet::isSet(int fd) const noexcept
{
    return (FD_ISSET(fd, &fdSet_));
}

/**
 * Clear the fd_set structure.
 */
void LinuxFdSet::clear() noexcept
{
    FD_ZERO(&fdSet_);
}

/**
 * It adds a socket to the list of sockets that the selector will monitor
 *
 * @param socket The socket to add to the selector.
 * @param isRead If true, the socket will be checked for readability.
 * @param isWrite If true, the socket will be checked for writability.
 * @param isExcept This is a flag that indicates whether the socket should be
 * checked for exceptional conditions.
 */
void LinuxSocketSelector::add(ISocket& socket, bool isRead, bool isWrite, bool isExcept)
{
    auto linuxSocket = dynamic_cast<LinuxSocket*>(&socket);
    if (linuxSocket == nullptr) throw NetworkError("Error while using the socket with select.");

    if (isRead) readFds_.add(linuxSocket->getSocketFd());
    if (isWrite) writeFds_.add(linuxSocket->getSocketFd());
    if (isExcept) exceptFds_.add(linuxSocket->getSocketFd());

    sockets_.push_back(*linuxSocket);
    if (nfds_ < linuxSocket->getSocketFd() + 1) nfds_ = linuxSocket->getSocketFd() + 1;
}

/**
 * It removes the socket from the list of sockets to be monitored by the selector
 *
 * @param socket The socket to remove from the selector.
 * @param isRead if true, the socket will be added to the readFds_ set.
 * @param isWrite if true, the socket will be added to the writeFds_ set.
 * @param isExcept If true, the socket will be checked for exceptions.
 *
 * @return A reference to the socket.
 */
void LinuxSocketSelector::remove(ISocket& socket, bool isRead, bool isWrite, bool isExcept)
{
    auto linuxSocket = dynamic_cast<LinuxSocket*>(&socket);
    if (linuxSocket == nullptr) throw NetworkError("Error while using the socket with select.");

    if (isRead) readFds_.remove(linuxSocket->getSocketFd());
    if (isWrite) writeFds_.remove(linuxSocket->getSocketFd());
    if (isExcept) exceptFds_.remove(linuxSocket->getSocketFd());

    auto it = std::find_if(sockets_.begin(), sockets_.end(), [&linuxSocket](auto& socket) {
        return (socket.get().getSocketFd() == linuxSocket->getSocketFd());
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
 * It checks if the socket is set in the corresponding set of file descriptors
 *
 * @param socket The socket to check.
 * @param type The type of operation to check for.
 *
 * @return A reference to the set of sockets that are ready for the given
 * operation.
 */

bool LinuxSocketSelector::isSet(ISocket& socket, Operation type) const
{
    auto linuxSocket = dynamic_cast<LinuxSocket*>(&socket);
    if (linuxSocket == nullptr) throw NetworkError("Error while using the socket with select.");

    if (type == Operation::READ) return (readyReadFds_.isSet(linuxSocket->getSocketFd()));
    if (type == Operation::WRITE) return (readyWriteFds_.isSet(linuxSocket->getSocketFd()));
    if (type == Operation::EXCEPTION) return (readyExceptFds_.isSet(linuxSocket->getSocketFd()));
    return (false);
}

/**
 * Clear the specified set of file descriptors.
 *
 * @param isRead If true, the readFds_ set will be cleared.
 * @param isWrite If true, the writeFds_ set will be cleared.
 * @param isExcept If true, the exceptFds_ set will be cleared.
 */
void LinuxSocketSelector::clear(bool isRead, bool isWrite, bool isExcept) noexcept
{
    if (isRead) readFds_.clear();
    if (isWrite) writeFds_.clear();
    if (isExcept) exceptFds_.clear();
}

/**
 * It takes in a set of file descriptors, and returns a set of file descriptors
 * that are ready for reading, writing, or exception
 *
 * @param isRead If true, the select function will check if the socket is ready to
 * read.
 * @param isWrite If true, the writeFds_ will be checked for writability.
 * @param isExcept If true, the function will check for exceptions on the sockets.
 */
void LinuxSocketSelector::select(bool isRead, bool isWrite, bool isExcept)
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
