/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** main_client
*/

#include <Client/Menu.hpp>
#include <Client/UdpClient.hpp>
#include <Error/Error.hpp>
#include <NetworkLib/HostHandler.hpp>
#include <cstdlib>
#include <iostream>

/**
 * It takes the command line arguments and returns a vector of strings
 *
 * @param ac The number of arguments passed to the program.
 * @param av The array of arguments passed to the program.
 *
 * @return A vector of strings.
 */
std::vector<std::string> checkArgs(int ac, const char* const av[])
{
    if (ac == 1) return {};
    if (ac == 4) return {av[1], av[2], av[3]};
    else
        throw InitError("Error: Invalid number of arguments");
}

/**
 * It checks the arguments, then it creates a client and runs it
 *
 * @param ac the number of arguments
 * @param av the arguments passed to the program
 *
 * @return The return value of the main function is an integer.
 */
int main(int ac, const char* const av[])
{
    try {
        std::vector<std::string> infos = checkArgs(ac, av);
        if (infos.size() == 0) {
            UdpClient client((Address::Port(0)));
            client.run();
        } else {
            Address::Port clientPort    = HostHandler::getClientPort(infos);
            Address       serverAddress = HostHandler::getHostAddress(infos);
            UdpClient     client(serverAddress, clientPort);
            client.run();
        }
    } catch (Error const& error) {
        std::cerr << error.what() << std::endl;
        return (84);
    }
    return (0);
}