#pragma once

#include "../socket-server-cpp-main/hdelib-socket-server.hpp"
#include <unistd.h>
#include <netinet/in.h>

namespace BBWS
{

    class WebServer : public HDE::AbstractSimpleServer
    {
    private:
        int new_socket;

        // virtual members
        void accepter();
        void responder(std::string const &response);

    protected:
        char request[30000] = {0};

    public:
        WebServer(int port);

        // start the server
        void launch();
        // virtual methods
        virtual std::string handler(); // since any one can declare its own handler
    };

}
