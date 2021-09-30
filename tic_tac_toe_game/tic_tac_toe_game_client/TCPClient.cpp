#include "TCPClient.h"
#include <vector>

addrinfo *TCPClient::resolve_adress_port(std::string_view adress, std::string_view port)
{
    //ZeroMemory(&hints, sizeof(hints));
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    addrinfo *result = nullptr;
    int status = getaddrinfo(std::string(adress).c_str(), std::string(port).c_str(), &hints, &result); //более безопасная конверсия
    
    if (status != 0) 
    {
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(status) + '\n');
    }
	return result;
}

bool TCPClient::connect(addrinfo *adress)
{
    for (addrinfo* ptr = adress; ptr != nullptr; ptr = ptr->ai_next)
    {
        // Create a SOCKET for connecting to server
        socket_ = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (socket_ == INVALID_SOCKET) 
        {
            throw std::runtime_error("socket failed with error: " + std::to_string(WSAGetLastError()) + '\n');
        }

        // Connect to server.
        int result = ::connect(socket_, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (result == SOCKET_ERROR) 
        {
            closesocket(socket_);
            socket_ = INVALID_SOCKET;
            continue;
        }
        return true;
    }
    return false;
}

void TCPClient::send_message(std::string_view message)
{
    int result = send(socket_, message.data(), message.length(), 0);
    if (result == SOCKET_ERROR)
    {
        throw std::runtime_error("send failed with error: " + std::to_string(WSAGetLastError()) + '\n');
    }
    std::cout << "Bytes Sent: " << result << std::endl;
}

std::string TCPClient::receive(int lenght)
{
    std::vector<char> buffer(lenght);
    int result = 0;
    int recieved = 0;
    do
    {
        result = recv(socket_, buffer.data() + recieved, lenght - recieved, 0); //buffer.data() pointer to [0]
        if (result > 0)
        {
            recieved += result;
            std::cout << "Bytes received: " << result << std::endl;
        }
        else if (result == 0)
            throw std::runtime_error("Connection closed\n");
        else
            throw std::runtime_error("recv failed with error: " + std::to_string(WSAGetLastError()) + '\n');
    } while (recieved < lenght);
    return std::string(buffer.begin(), buffer.end());
}

void TCPClient::connection_shutdown()
{
    int result = shutdown(socket_, SD_SEND);
    if (result == SOCKET_ERROR)
    {
        throw std::runtime_error("shutdown failed with error: " + std::to_string(WSAGetLastError()) + '\n');
    }
}
