#include "TCPClient.h"

#include <ws2tcpip.h>

auto _socket = socket;
auto _connect = connect;
auto _send = send;
auto _recv = recv;

bool TCPClient::connect(const char* hostname, const char* port)
{
    struct addrinfo *result = NULL,
                    *ptr    = NULL,
                    hints;
    const char* sendbuf = "this is a test";
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0)
    {
        printf("WSAStartup failed with error: %d\n", iResult);
        return false;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(hostname, port, &hints, &result);
    if (iResult != 0)
    {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return false;
    }

    // Attempt to connect to an address until one succeeds
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next)
    {
        // Create a SOCKET for connecting to server
        socket = _socket(
            ptr->ai_family,
            ptr->ai_socktype,
            ptr->ai_protocol);
        if (socket == INVALID_SOCKET)
        {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return false;
        }

        u_long iMode = 0;
        iResult = ioctlsocket(socket, FIONBIO, &iMode);

        // Connect to server.
        iResult = _connect(socket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR)
        {
            closesocket(socket);
            socket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (socket == INVALID_SOCKET)
    {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return false;
    }

    return true;
}


int TCPClient::send(const char* buf, size_t len)
{
    auto size = _send(socket, buf, len, 0);
    if (size == SOCKET_ERROR)
    {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(socket);
    }
    return size;
}

bool TCPClient::sendAll(const char* buf, size_t len)
{
    while (len > 0)
    {
        auto size = send(buf, len);
        if (size == SOCKET_ERROR)
            return false;
        buf += size;
        len -= size;
    }
    return true;
}

int TCPClient::recv(char* buffer, size_t len)
{
    int result = _recv(socket, buffer, len, 0);
    if (result > 0) {
        // printf("Bytes received: %d\n", result);
    }
    else if (result == 0)
    {
        printf("Connection closing...");
    }
    else if (result == SOCKET_ERROR)
    {
        printf("recv failed with error: %d", WSAGetLastError());
        closesocket(socket);
        WSACleanup();
    }
    return result;
}

bool TCPClient::recvUntil(char* buffer, size_t len)
{
    while (len > 0)
    {
        auto size = recv(buffer, len);
        if (size <= 0)
            return false;
        buffer += size;
        len -= size;
    }
    return true;
}



template<>
bool TCPClient::send<std::string>(const std::string& value)
{
    return send<int>(value.size()) && sendAll(value.c_str(), value.size());
}

template<>
bool TCPClient::recv<std::string>(std::string& value)
{
    int size;
    if(!recv(size))
        return false;
    if(size == 0)
        return "";
    auto buf = (char*)malloc(size + 1);
    if(!recvUntil(buf, size))
        return false;
    buf[size] = 0;
    value = std::string(buf, size);
    free(buf);
    return true;
}

