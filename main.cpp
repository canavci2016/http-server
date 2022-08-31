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
        std::string path = "./views/index.html";
        return BBWS::Response::htmlFile(path);
    };

    testServer.onRequestReceived(request_callback);
    testServer.launch();

    return 0;
}