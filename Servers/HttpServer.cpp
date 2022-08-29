#include "HttpServer.hpp"

BBWS::HttpServer::HttpServer(int port) : WebServer(port)
{
}

std::string BBWS::HttpServer::handler()
{
    const std::string str = request_callback(request);
    return str;
}

void BBWS::HttpServer::onRequestReceived(std::function<std::string(char request[])> callback)
{
    request_callback = callback;
}
