#include "HttpServer.hpp"

BBWS::HttpServer::HttpServer(int port) : WebServer(port)
{
}

std::string BBWS::HttpServer::handler()
{
    std::cout << request << std::endl;

    const std::string str = "new http  server is up \n";
    return str;
}