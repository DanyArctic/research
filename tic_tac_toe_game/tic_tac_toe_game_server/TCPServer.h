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
	TCPServer();
	~TCPServer();

	addrinfo* resolve_serv_adress_and_port(std::string_view port);
	void connect(addrinfo* adress);
	void accept_socket();
	std::string receive(int lenght);
private:
	SOCKET listen_socket_ = INVALID_SOCKET;
	SOCKET client_socket_ = INVALID_SOCKET;
};

