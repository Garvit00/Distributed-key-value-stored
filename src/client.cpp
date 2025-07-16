#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char *argv[])
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }
    std::string server_ip = "127.0.0.1";
    int port = 5000;

    if (argc > 1)
        port = std::stoi(argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);

    connect(sock, (sockaddr *)&server_addr, sizeof(server_addr));

    std::cout << "Connected to server.\nEnter commands (PUT key val / GET key / DELETE key):\n";
    std::string input;
    char buffer[1024];

    while (true)
    {
        std::getline(std::cin, input);
        if (input.empty())
            continue;
        send(sock, input.c_str(), input.size(), 0);
        int len = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (len <= 0)
            break;
        buffer[len] = '\0';
        std::cout << "Response: " << buffer << "\n";
    }

    closesocket(sock);
    return 0;
}
