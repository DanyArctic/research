#define WIN32_LEAN_AND_MEAN

#pragma once
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stdexcept>


class TCPClient
{
public:
	TCPClient()
	{
		// Initialize Winsock
		WSADATA wsaData;
		int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (result != 0)
		{
			printf("WSAStartup failed with error: %d\n", result);
		}
	}
	~TCPClient()
	{
		// cleanup
		//closesocket(ConnectSocket_);
		WSACleanup();
	}
	
	addrinfo *resolve_adress_port(std::string adress, std::string port);
	SOCKET connect(addrinfo* adress);
	/*
private:
	int iResult_;
	WSADATA wsaData_;
	SOCKET ConnectSocket_ = INVALID_SOCKET;
	struct addrinfo* result_ = NULL,
		* ptr_ = NULL,
		hints_;
	const char* sendbuf_ = "this is a test";
	char recvbuf_[DEFAULT_BUFLEN];
	int recvbuflen_ = DEFAULT_BUFLEN;
	*/
};

