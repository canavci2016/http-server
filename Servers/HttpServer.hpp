#pragma once

#include "WebServer.hpp"

namespace BBWS
{

    class HttpServer : public BBWS::WebServer
    {
    private:
        std::function<std::string(char *request)> request_callback;

    public:
        HttpServer(int port);
        std::string handler(); // since any one can declare its own handler
        void onRequestReceived(std::function<std::string(char *request)> callback);
    };

}