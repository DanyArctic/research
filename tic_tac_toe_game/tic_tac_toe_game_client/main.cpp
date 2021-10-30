#include <iostream>
#include "TCPClient.h"
#include "Client.h"


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

constexpr std::string_view DEFAULT_PORT = "27015";

int __cdecl main(int argc, char** argv)
{   
    
    Client player;
    std::cout << "Please enter your name: " << std::endl;
    std::string name;
    std::cin >> name;
    name.push_back('$');
    player.set_players_name(name);
    const char* sendbuf = name.data();
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
        // Attempt to connect to an address until one succeeds
        bool connected = client.connect(result);

        freeaddrinfo(result);

        if (!connected)
        {
            std::cout << "Unable to connect to server!" << std::endl;
            return 1;
        }

        // Send an initial buffer
        client.send_message(sendbuf);

        // Receive until the peer closes the connection
        std::cout << client.receive(name.length()) << std::endl;

    }
    catch (const std::runtime_error &error)
    {
        std::cerr << error.what() << '\n';
    }
    
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
        client.send_message(std::to_string(x)+' '+ std::to_string(y));
        std::cout << client.receive(name.length()) << std::endl;
        //system("cls");
        player.print_field();
    }
    //restart function?
    return 0;
}