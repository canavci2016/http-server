#pragma once

#include "WebServer.hpp"

namespace BBWS
{

    class HttpServer : public BBWS::WebServer
    {
    public:
        HttpServer(int port);
        std::string handler(); // since any one can declare its own handler
    };

}