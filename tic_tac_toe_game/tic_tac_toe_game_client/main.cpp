/*#include <iostream>
#include "Client.h"

int main()
{
    Client player;
    std::cout << "Please enter your name: " << std::endl;
    std::string name;
    std::cin >> name;
    player.set_players_name(name);
    while (player.get_win_state() == 0)
    {
        int x = 0;
        int y = 0;
        std::cout << "Make your move, by coordinates x and y, from 0 to 2, with space between them: " << std::endl;
        std::cin >> x >> y;
        if (x < 0 || x >= Client::board_size_ || y < 0 || y >= Client::board_size_)
        {
            std::cout << "Wrong set. Try again." << std::endl;
            continue;
        }
        player.current_cell_set(x, y);
        system("cls");
        player.print_field();
    }
    //restart function?
}
*/
#define WIN32_LEAN_AND_MEAN

//#include <windows.h>
//#include <winsock2.h>
//#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "TCPClient.h"

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

int __cdecl main(int argc, char** argv)
{
    //WSADATA wsaData;
    

    const char *sendbuf = "this is a test"; // not possible to use string?
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;

    // Validate the parameters
    if (argc != 2) 
    {
        printf("usage: %s server-name\n", argv[0]);
        return 1;
    }

    TCPClient client;
    try
    {
        addrinfo* result = client.resolve_adress_port(argv[1], DEFAULT_PORT);
        SOCKET ConnectSocket = client.connect(result);

        // Attempt to connect to an address until one succeeds
        client.connect(result);
        freeaddrinfo(result);

        if (ConnectSocket == INVALID_SOCKET)
        {
            printf("Unable to connect to server!\n");
            return 1;
        }

        // Send an initial buffer
        client.send_message(ConnectSocket, sendbuf);

        // shutdown the connection since no more data will be sent
        iResult = shutdown(ConnectSocket, SD_SEND);
        if (iResult == SOCKET_ERROR) 
        {
            printf("shutdown failed with error: %d\n", WSAGetLastError());
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

        // Receive until the peer closes the connection
        do 
        {
            iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
            if (iResult > 0)
                printf("Bytes received: %d\n", iResult);
            else if (iResult == 0)
                printf("Connection closed\n");
            else
                printf("recv failed with error: %d\n", WSAGetLastError());

        } while (iResult > 0);

        // cleanup
        closesocket(ConnectSocket);

    }
    catch (const std::runtime_error &error)
    {
        std::cerr << error.what() << '\n';
    }
    return 0;
}