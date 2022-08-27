#include "WebServer.hpp"

BBWS::WebServer::WebServer(int port) : AbstractSimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
}

void BBWS::WebServer::accepter()
{
    sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);

    read(new_socket, request, 30000);
}

std::string BBWS::WebServer::handler()
{
    std::cout << request << std::endl;

    const std::string str = "hello server is up \n";
    return str;
}

void BBWS::WebServer::responder(std::string const &str)
{
    write(new_socket, str.c_str(), str.length());
    std::cout << "------------------Hello message sent (responded)-------------------" << std::endl;
}

void BBWS::WebServer::launch()
{
    std::cout << "============waiting for server ===========" << std::endl;

    while (1)
    {
        accepter();
        std::string response = handler();
        responder(response);
        close(new_socket);
    }
}