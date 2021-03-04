#pragma once
#define _WINSOCKAPI_ 
#include <WinSock2.h>

#include "Utils.h"


class TcpServer 
{
public:
	SOCKET serverSocket;
	SOCKET clientSocket;
	WSADATA wsaData;
    std::string addr;
    std::string port;

	TcpServer(const char* addr, const char* port): addr(addr), port(port)
	{
	}

    bool listen();

    bool waitClient();

    size_t send(const char* buf, size_t len);

    bool sendAll(const char* buf, size_t len);

    size_t recv(char* buffer, size_t len);

    bool recvUntil(char* buffer, size_t len);

	template<typename T>
	bool send(const T& value);
	
	template<typename T>
	bool recv(T& value);

	
};

template <typename T>
bool TcpServer::send(const T& value)
{
	return sendAll((const char*)&value, sizeof(T));
}

template <typename T>
bool TcpServer::recv(T& value)
{
	return recvUntil((char*)&value, sizeof(T));
}


template<>
bool TcpServer::send<std::string>(const std::string& value);

template<>
bool TcpServer::recv<std::string>(std::string& value);