#include "pch.h"
#include <Windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "TcpServer.h"
#include "Utils.h"


auto _send = send;
auto _recv = recv;
auto _listen = listen;

bool TcpServer::listen()
{
    addrinfo* serverAddr = nullptr;
    addrinfo hints;

    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        logFmt("WSAStartup failed with error: %d\n", iResult);
        return false;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(addr.c_str(), port.c_str(), &hints, &serverAddr);
    if (iResult != 0) {
        logFmt("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return false;
    }

    // Create a SOCKET for connecting to server
    serverSocket = socket(serverAddr->ai_family, serverAddr->ai_socktype, serverAddr->ai_protocol);
    if (serverSocket == INVALID_SOCKET) {
        logFmt("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(serverAddr);
        WSACleanup();
        return false;
    }
    
    
    u_long iMode = 0;
    iResult = ioctlsocket(serverSocket, FIONBIO, &iMode);

    // Setup the TCP listening socket
    iResult = bind(serverSocket, serverAddr->ai_addr, (int)serverAddr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        logFmt("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(serverAddr);
        closesocket(serverSocket);
        WSACleanup();
        return false;
    }

    freeaddrinfo(serverAddr);

    iResult = _listen(serverSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        logFmt("listen failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return false;
    }

    return true;
}

bool TcpServer::waitClient()
{
    // Accept a client socket
    clientSocket = accept(serverSocket, NULL, NULL);
    
    u_long iMode = 0;
    ioctlsocket(clientSocket, FIONBIO, &iMode);
    
    if (clientSocket == INVALID_SOCKET) {
        logFmt("accept failed with error: %d\n", WSAGetLastError());
        closesocket(serverSocket);
        WSACleanup();
        return false;
    }
    return true;
}

void TcpServer::close()
{
    closesocket(serverSocket);
    closesocket(clientSocket);
}


int TcpServer::send(const char* buf, size_t len)
{
    auto size = _send(clientSocket, buf, len, 0);
    if (size == SOCKET_ERROR)
    {
        logFmt("send failed with error: %d\n", WSAGetLastError());
        closesocket(clientSocket);
    }
    return size;
}

bool TcpServer::sendAll(const char* buf, size_t len)
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

int TcpServer::recv(char* buffer, size_t len)
{
    int result = _recv(clientSocket, buffer, len, 0);
    if (result > 0) {
        logFmt("Bytes received: %d\n", result);
    }
    else if (result == 0)
    {
        logFmt("Connection closing...");
    }
    else if (result == SOCKET_ERROR)
    {
        logFmt("recv failed with error: %d", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
    }
    return result;
}

bool TcpServer::recvUntil(char* buffer, size_t len)
{
    size_t total = 0;
    while (len > 0)
    {
        auto size = recv(buffer, len);
        if (size <= 0)
            return false;
        buffer += size;
        len -= size;
        total += size;
        logFmt("Recv %d/%d", total, len);
    }
    return true;
}

template<>
bool TcpServer::send<std::string>(const std::string& value)
{
    return send<int>(value.size()) && sendAll(value.c_str(), value.size());
}

template<>
bool TcpServer::recv<std::string>(std::string& value)
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
    
    logFmt("Recv string %s", value.c_str());
    free(buf);
    logFmt("Free string %s", value.c_str());
    return true;
}