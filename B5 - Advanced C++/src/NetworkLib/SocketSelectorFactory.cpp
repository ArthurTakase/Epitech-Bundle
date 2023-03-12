/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** SocketSelectorFactory
*/

#include <NetworkLib/LinuxSocketSelector.hpp>
#include <NetworkLib/SocketSelectorFactory.hpp>
#include <NetworkLib/WindowsSocketSelector.hpp>

/**
 * If the OS is Windows, return a WindowsSocketSelector, otherwise return a
 * LinuxSocketSelector.
 *
 * @return A unique pointer to a SocketSelector object.
 */
std::unique_ptr<SocketSelector> SocketSelectorFactory::createSocketSelector()
{
#ifdef WIN32
    return std::make_unique<WindowsSocketSelector>();
#elif __linux__
    return std::make_unique<LinuxSocketSelector>();
#else
    static_assert(false, "OS not supported");
#endif
}
