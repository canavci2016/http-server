#include <iostream>
#include <string>
#include "Servers/HttpServer.hpp"

int main()
{
    int port = 8080;
    std::cout << port << " is being used " << std::endl;
    BBWS::HttpServer testServer(port);
    auto request_callback = [](char request[])
    {
                                    //std::cout << request << std::endl;
                                     std::string hello_message = "hello worl";
                                     return hello_message; };

    testServer.onRequestReceived(request_callback);
    testServer.launch();

    return 0;
}