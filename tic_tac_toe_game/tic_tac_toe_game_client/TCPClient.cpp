#include "TCPClient.h"

addrinfo *TCPClient::resolve_adress_port(const std::string adress, const std::string port)
{
    //ZeroMemory(&hints, sizeof(hints));
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    addrinfo *result = nullptr;
    int status = getaddrinfo(adress.c_str(), port.c_str(), &hints, &result);
    
    if (status != 0) 
    {
        throw std::runtime_error("getaddrinfo failed with error: " + std::to_string(status) + '\n');
    }
	return result;
}

SOCKET TCPClient::connect(addrinfo *adress)
{
    for (addrinfo* ptr = adress; ptr != nullptr; ptr = ptr->ai_next)
    {
        // Create a SOCKET for connecting to server
        SOCKET ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype,
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) 
        {
            throw std::runtime_error("socket failed with error: " + std::to_string(WSAGetLastError()) + '\n');
            return ConnectSocket;
        }

        // Connect to server.
        int result = ::connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (result == SOCKET_ERROR) 
        {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        return ConnectSocket;
    }
    return INVALID_SOCKET;
}

void TCPClient::send_message(SOCKET connect_socket, const char *sendbuf)
{
    SOCKET result = send(connect_socket, sendbuf, (int)strlen(sendbuf), 0);
    if (result == SOCKET_ERROR)
    {
        throw std::runtime_error("send failed with error: " + std::to_string(WSAGetLastError()) + '\n');
        closesocket(connect_socket);
    }
    std::cout << "Bytes Sent: " << result << std::endl;
}