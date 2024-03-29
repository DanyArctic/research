#define WIN32_LEAN_AND_MEAN

#pragma once
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <iostream>


class TCPClient
{
public:
	TCPClient();
	~TCPClient();
	
	addrinfo *resolve_adress_port(std::string_view adress, std::string_view port);
	bool connect(addrinfo* adress);
	void send_message(std::string_view message);
	void connection_shutdown();
	std::string receive(int lenght);
	
private:
	SOCKET socket_ = INVALID_SOCKET;
};

