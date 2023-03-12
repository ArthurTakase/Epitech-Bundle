/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** ISocket
*/

#include <NetworkLib/LinuxSocket.hpp>
#include <NetworkLib/SocketFactory.hpp>
#include <NetworkLib/WindowsSocket.hpp>

/**
 * If the OS is Windows, create a WindowsSocket, otherwise create a LinuxSocket.
 *
 * @param port The port to bind the socket to.
 *
 * @return A unique pointer to an ISocket object.
 */
std::unique_ptr<ISocket> SocketFactory::createSocket(Address::Port port)
{
#ifdef WIN32
    return std::make_unique<WindowsSocket>(port);
#elif __linux__
    return std::make_unique<LinuxSocket>(port);
#else
    static_assert(false, "OS not supported");
#endif
}
