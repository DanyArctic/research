/*#include "Field.h"
#include "Server.h"
#include <iostream>
#include <cmath>
#include <string>


int main()
{
	//tests
	Field game;
	game.print();
	game.cell_set(0, 1, Field::CellState(2));
	game.print();
	game.clear_field();
	game.print();
	game.cell_set(0, 0, Field::CellState(1));
	game.cell_set(1, 1, Field::CellState(1));
	game.cell_set(2, 2, Field::CellState(1));
	game.print();
	game.clear_field();
	game.cell_set(2, 2, Field::CellState(1));
	game.print();
	//game.cell_set(2, 2, Field::CellState(1));

	Server serv;

	std::string player_one("Alice");
	std::string player_two("Daniel");
	
	serv.set_players_name(player_one, player_two);

	serv.first_or_second();
	int play = serv.get_play_order();
	std::cout << "play_order: " << play << '\n';
	
	/*int next = serv.set_get_next_play_order();

	for (int i = 0; i < 5; ++i)
	{
		std::cout << next << '\n';
		next = serv.set_get_next_play_order();
	}*/
	/*
	Field::WinState game_result = Field::WinState::Nobody;

	game_result = game.get_win_state(); //почему на пустом поле вылезает 3?
	std::cout << "game_result: " << (int)game_result << std::endl;

	switch (game_result)
	{
	case Field::WinState::Tie:
		std::cout << "Draw!" << std::endl;
		break;
	case Field::WinState::X:
		std::cout << player_one << " is the winner!" << std::endl;
		break;
	case Field::WinState::O:
		std::cout << player_two << " is the winner!" << std::endl;
		break;
	default:
		std::cout << "No one is the winner yet!" << std::endl;
	}

	return 0;
}*/
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int __cdecl main(void)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    // Initialize Winsock в конструктор
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // No longer need server socket
    closesocket(ListenSocket);

    // Receive until the peer shuts down the connection
    do {

        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            printf("Bytes received: %d\n", iResult);

            // Echo the buffer back to the sender
            iSendResult = send(ClientSocket, recvbuf, iResult, 0);
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            printf("Bytes sent: %d\n", iSendResult);
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

    } while (iResult > 0);

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup в деструктор
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}