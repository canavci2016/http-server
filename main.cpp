#include <iostream>
#include <string>
#include "Servers/HttpServer.hpp"

int main()
{
    int port = 8080;
    std::cout << port << " is being used " << std::endl;
    BBWS::HttpServer testServer(port);
    testServer.launch();

    return 0;
}