/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** WinSocket
*/

#ifdef WIN32
#include <Error/Error.hpp>
#include <NetworkLib/WindowsSocket.hpp>

/**
 * It initializes an UDP socket compatible with Windows, binds it to the port, and reserves memory for the
 * received buffer.
 *
 * @param port The port to bind the socket to.
 */
WindowsSocket::WindowsSocket(Address::Port port)
{
    WSADATA wsa;
    int     err = WSAStartup(MAKEWORD(2, 2), &wsa);

    if (err < 0) { throw InitError("WSAStartup failed."); }
    socketFd_ = socket(AF_INET, SOCK_DGRAM, 0);

    if (socketFd_ < 1) { throw InitError("Socket initialization failed."); }

    address_.sin_port        = htons(port);
    address_.sin_addr.s_addr = htonl(INADDR_ANY);
    address_.sin_family      = AF_INET;

    if (bind(socketFd_, reinterpret_cast<SOCKADDR*>(&address_), sizeof(address_)) != 0)
        throw InitError("Socket binding to port failed.");
    receivedBuffer_.reserve(MAX_RECEIVED_BUFFER_SIZE);
}

/**
 * The destructor for the WindowsSocket class calls WSACleanup() and closes the
 * socket.
 */
WindowsSocket::~WindowsSocket() noexcept
{
    WSACleanup();
    closesocket(socketFd_);
}

/**
 * This function returns the socket file descriptor.
 *
 * @return The socket file descriptor.
 */
ISocket::Fd WindowsSocket::getSocketFd() const noexcept
{
    return socketFd_;
}

/**
 * It converts a Windows socket address to a cross-platform address
 *
 * @param address The address to convert.
 *
 * @return A WindowsSocket object.
 */
Address WindowsSocket::winAddressToAddress(SOCKADDR_IN address) noexcept
{
    Address converted{.port = ntohs(address.sin_port), .ip = ntohl(address.sin_addr.s_addr)};
    return converted;
}

/**
 * It converts an Address object to a Windows SOCKADDR_IN object
 *
 * @param address The address to convert.
 *
 * @return A SOCKADDR_IN struct.
 */
SOCKADDR_IN WindowsSocket::addressToWinAddress(Address address) noexcept
{
    SOCKADDR_IN converted;
    converted.sin_family      = AF_INET;
    converted.sin_port        = htons(address.port);
    converted.sin_addr.s_addr = htonl(address.ip);
    return converted;
}

/**
 * It converts a Windows address to a generic address.
 *
 * @return A copy of the address_ member variable.
 */
Address WindowsSocket::getAddress() const noexcept
{
    Address address = winAddressToAddress(address_);
    return address;
}

/**
 * It takes a pointer to the data to be sent, the size of the data, and the
 * destination address, and sends the data to the destination address.
 *
 * @param data The data to be sent.
 * @param data_size The size of the data to be sent.
 * @param destAddr The address of the destination.
 */
void WindowsSocket::send(const void* data, int data_size, Address destAddr) const
{
    SOCKADDR_IN winDestAddr = addressToWinAddress(destAddr);

    int sent_bytes = sendto(socketFd_,
        reinterpret_cast<const char*>(data),
        data_size,
        0,
        reinterpret_cast<SOCKADDR*>(&winDestAddr),
        sizeof(winDestAddr));

    if (sent_bytes < 0) { throw NetworkError("Error in sending data from the server to the client"); }
}

/**
 * It receives data from the client and returns the address of the client and the
 * data received
 *
 * @return A ReceivedInfos struct containing the address of the sender and the data
 * received.
 */
ReceivedInfos WindowsSocket::receive()
{
    SOCKADDR_IN   address = {0};
    socklen_t     addrLen = sizeof(address);
    ReceivedInfos infos;

    int bytesReceived = recvfrom(socketFd_,
        receivedBuffer_.data(),
        receivedBuffer_.capacity(),
        0,
        reinterpret_cast<SOCKADDR*>(&address),
        &addrLen);

    if (bytesReceived < 0) { throw NetworkError("Error receiving data from the client "); }

    infos.address = winAddressToAddress(address);
    infos.data.insert(infos.data.begin(), receivedBuffer_.data(), receivedBuffer_.data() + bytesReceived);
    return infos;
}

#endif