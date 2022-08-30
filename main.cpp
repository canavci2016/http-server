#include <iostream>
#include <string>
#include "Servers/HttpServer.hpp"
#include "Servers/Response.hpp"

int main()
{
    int port = 8080;
    std::cout << port << " is being used " << std::endl;
    BBWS::HttpServer testServer(port);
    auto request_callback = [](char request[])
    {
        // std::cout << request << std::endl;
        std::string content = "hello world";

        return BBWS::Response::html(content, 200);
    };

    testServer.onRequestReceived(request_callback);
    testServer.launch();

    return 0;
}