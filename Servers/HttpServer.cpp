#include "HttpServer.hpp"

BBWS::HttpServer::HttpServer(int port) : WebServer(port)
{
}

std::string BBWS::HttpServer::handler()
{
    return request_callback(request);
}

void BBWS::HttpServer::onRequestReceived(std::function<std::string(char request[])> callback)
{
    request_callback = callback;
}
