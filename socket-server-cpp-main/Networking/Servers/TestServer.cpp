

#include "TestServer.hpp"

HDE::TestServer::TestServer() : AbstractSimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)
{
    launch();
}

void HDE::TestServer::accepter()
{
    sockaddr_in address = get_socket()->get_address();
    int addrlen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrlen);

    read(new_socket, buffer, 30000);
}

std::string HDE::TestServer::handler()
{
    std::cout << buffer << std::endl;
    std::string s = "merhaba";
    return s;
}

void HDE::TestServer::responder(std::string const &res)
{
    const char *hello = "Hello from server";
    write(new_socket, hello, strlen(hello));
    std::cout << "------------------Hello message sent-------------------" << std::endl;
    close(new_socket);
}

void HDE::TestServer::launch()
{
    while (1)
    {
        std::cout << "============waiting for server ===========" << std::endl;
        accepter();
        std::string handler_response = handler();
        responder(handler_response);
        std::cout << "============ responded ===========" << std::endl;
    }
}
