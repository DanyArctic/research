#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

class TCPServer
{
public:
	TCPServer()
	{
		WSADATA wsaData;
		int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (result != 0) 
		{
			std::cout << "WSAStartup failed with error: " << result << std::endl; //тут по идее нужно остановить
		}
	}
	~TCPServer()
	{
		closesocket(listen_socket_);
		closesocket(client_socket_);
		WSACleanup();
	}

	addrinfo* resolve_serv_adress_and_port(std::string_view port);
	void connect(addrinfo* adress);
	void accept_socket();
	std::string receive(int lenght);
private:
	SOCKET listen_socket_ = INVALID_SOCKET;
	SOCKET client_socket_ = INVALID_SOCKET;
};

