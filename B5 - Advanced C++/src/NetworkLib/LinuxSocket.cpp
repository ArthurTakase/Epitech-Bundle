/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** LinuxSocket
*/

#ifdef __linux__

#include <Error/Error.hpp>
#include <NetworkLib/LinuxSocket.hpp>

/**
 * It creates an UDP socket for Linux machines, binds it to a port, and reserves memory for the received
 * buffer
 *
 * @param port the port to listen to
 */
LinuxSocket::LinuxSocket(Address::Port port)
{
    socketFd_ = socket(AF_INET, SOCK_DGRAM, 0);

    if (socketFd_ < 1) { throw InitError("Socket initialization failed."); }

    // make the socket listen to a port passed in parameter
    address_.sin_port        = htons(port);
    address_.sin_addr.s_addr = htonl(INADDR_ANY);
    address_.sin_family      = AF_INET;

    if (bind(socketFd_, reinterpret_cast<sockaddr*>(&address_), sizeof(address_)) != 0)
        throw InitError("Socket binding to port failed.");

    receivedBuffer_.reserve(MAX_RECEIVED_BUFFER_SIZE);
}

/**
 * The destructor closes the socket file descriptor.
 */
LinuxSocket::~LinuxSocket() noexcept
{
    close(socketFd_);
}

/**
 * This function returns the socket file descriptor.
 *
 * @return The socket file descriptor.
 */
ISocket::Fd LinuxSocket::getSocketFd() const noexcept
{
    return (socketFd_);
}

/**
 * It converts a Linux socket address to a generic address
 *
 * @param address The address to convert.
 *
 * @return A sockaddr_in struct.
 */
Address LinuxSocket::linuxAddressToAddress(sockaddr_in address) noexcept
{
    Address converted{.port = ntohs(address.sin_port), .ip = ntohl(address.sin_addr.s_addr)};
    return converted;
}

/**
 * It converts an Address object into a sockaddr_in object
 *
 * @param address The address to convert.
 *
 * @return A sockaddr_in struct.
 */
sockaddr_in LinuxSocket::addressToLinuxAddress(Address address) noexcept
{
    sockaddr_in converted;
    converted.sin_family      = AF_INET;
    converted.sin_port        = htons(address.port);
    converted.sin_addr.s_addr = htonl(address.ip);
    return converted;
}

/**
 * Convert the Linux address to a generic address.
 *
 * @return An encapsulated version of the address.
 */
Address LinuxSocket::getAddress() const noexcept
{
    Address address = linuxAddressToAddress(address_);
    return address;
}

/**
 * It takes a pointer to the data to be sent, the size of the data, and the
 * destination address, and sends the data to the destination address
 *
 * @param data The data to be sent.
 * @param data_size The size of the data to be sent.
 * @param destAddr The address of the destination.
 */
void LinuxSocket::send(const void* data, int data_size, Address destAddr) const
{
    sockaddr_in linuxDestAddr = addressToLinuxAddress(destAddr);

    int sent_bytes =
        sendto(socketFd_, data, data_size, 0, reinterpret_cast<sockaddr*>(&linuxDestAddr), sizeof(linuxDestAddr));

    if (sent_bytes < 0) { throw NetworkError("Error in sending data from the server to the client"); }
}

/**
 * It receives data from the client and returns the received data and the client's
 * address
 *
 * @return A ReceivedInfos struct containing the address of the sender and the data
 * received encapsulated.
 */
ReceivedInfos LinuxSocket::receive()
{
    sockaddr_in   address = {0};
    socklen_t     addrLen = sizeof(address);
    ReceivedInfos infos;

    int bytesReceived = recvfrom(socketFd_,
        reinterpret_cast<void*>(receivedBuffer_.data()),
        receivedBuffer_.capacity(),
        0,
        reinterpret_cast<sockaddr*>(&address),
        &addrLen);

    if (bytesReceived < 0) { throw NetworkError("Error receiving data from the client"); }

    infos.address = linuxAddressToAddress(address);
    infos.data.insert(infos.data.begin(), receivedBuffer_.data(), receivedBuffer_.data() + bytesReceived);
    return infos;
}

#endif
