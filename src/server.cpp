#include <iostream>
#include <string>
#include <sstream>
#include <thread>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#include "kv-store.hpp"

KeyValueStore kv;

void handle_client(int client_sock)
{
    char buffer[1024];
    int bytes_received;
    while ((bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0)) > 0)
    {
        buffer[bytes_received] = '\0';
        std::istringstream iss(buffer);
        std::string cmd, key, value, response;
        iss >> cmd >> key;

        if (cmd == "PUT")
        {
            iss >> value;
            response = kv.put(key, value);
        }
        else if (cmd == "GET")
        {
            response = kv.get(key);
        }
        else if (cmd == "DELETE")
        {
            response = kv.del(key);
        }
        else
        {
            response = "INVALID_COMMAND";
        }
        send(client_sock, response.c_str(), response.size(), 0);
    }
    closesocket(client_sock);
}

int main(int argc, char *argv[])
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }
    int port = 5000;
    if (argc > 1)
        port = std::stoi(argv[1]);

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    bind(server_sock, (sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, 5);

    std::cout << "Server listening on port " << port << "...\n";

    while (true)
    {
        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (sockaddr *)&client_addr, &client_len);
        std::thread(handle_client, client_sock).detach();
    }

    closesocket(server_sock);
    return 0;
}
