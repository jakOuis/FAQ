#pragma once
#define _WINSOCKAPI_ 
#include <WinSock2.h>
#include <windows.h>
#include <string>


class TCPClient
{
public:
    WSADATA wsaData;
    SOCKET socket;

    TCPClient()
    {
    }

    bool connect(const char* hostname, const char* port);

    size_t send(const char* buf, size_t len);
    bool sendAll(const char* buf, size_t len);

    size_t recv(char* buf, size_t len);
    bool recvUntil(char* buf, size_t len);
    
    template<typename T>
    bool send(const T& value);
	
    template<typename T>
    bool recv(T& value);
    
};

template <typename T>
bool TCPClient::send(const T& value)
{
    return sendAll((const char*)&value, sizeof(T));
}

template <typename T>
bool TCPClient::recv(T& value)
{
    return recvUntil((char*)&value, sizeof(T));
}

template<>
bool TCPClient::send<std::string>(const std::string& value);

template<>
bool TCPClient::recv<std::string>(std::string& value);