#include "TCPServer.h"
#include <vector>

addrinfo* TCPServer::resolve_serv_adress_and_port(std::string_view port)
{
    //ZeroMemory(&hints, sizeof(hints)); почему не используем это метод, а используем memset? так понимаю эта функция в данном случае заполняет все байты памяти "массива" hints символами '0'
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    addrinfo *result = nullptr;
    int status = getaddrinfo(NULL, std::string(port).c_str(), &hints, &result);
    if (status != 0) 
    {
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(status) + '\n');
    }
    return result;
}

void TCPServer::connect(addrinfo *adress)
{
    // Create a SOCKET for connecting to server
    listen_socket_ = socket(adress->ai_family, adress->ai_socktype, adress->ai_protocol);
    if (listen_socket_ == INVALID_SOCKET)
    {
        throw std::runtime_error("socket failed with error: " + std::to_string(WSAGetLastError()) + '\n');
    }

    // Setup the TCP listening socket
    int result = bind(listen_socket_, adress->ai_addr, (int)adress->ai_addrlen);
    if (result == SOCKET_ERROR)
    {
        throw std::runtime_error("bind failed with error: " + std::to_string(WSAGetLastError()) + '\n');
    }

    freeaddrinfo(adress); //нет ли тут утечки памяти?

    result = listen(listen_socket_, SOMAXCONN);
    if (result == SOCKET_ERROR)
    {
        throw std::runtime_error("listen failed with error: " + std::to_string(WSAGetLastError()) + '\n');
    }

        // Accept a client socket
        client_socket_ = accept(listen_socket_, NULL, NULL);
        if (client_socket_ == INVALID_SOCKET)
        {
            throw std::runtime_error("accept failed with error: " + std::to_string(WSAGetLastError()) + '\n');
        }
    }

std::string TCPServer::receive(int lenght)
{
    std::vector<char> buffer(lenght);
    int recieved = 0;
    int result = 0;
    do 
    {
        result = recv(client_socket_, buffer.data() + recieved, lenght - recieved, 0);
        if (result > 0) 
        {
            recieved += result;
            std::cout << "Bytes received: " << result << std::endl;

            // Echo the buffer back to the sender
            int send_result = send(client_socket_, buffer.data(), result, 0);
            if (send_result == SOCKET_ERROR) 
            {
                throw std::runtime_error("send failed with error: " + std::to_string(WSAGetLastError()) + '\n');
            }
            std::cout << "Bytes sent: " << send_result << std::endl;
        }
        else if (result == 0)
        {
            throw std::runtime_error("Connection closing..." + '\n');
        }
        else 
        {
            throw std::runtime_error("recv failed with error: " + std::to_string(WSAGetLastError()) + '\n');
        }
    } while (recieved < lenght);
    return std::string(buffer.begin(), buffer.end());
}

