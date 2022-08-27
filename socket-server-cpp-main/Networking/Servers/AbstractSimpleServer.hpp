

#ifndef AbstractSimpleServer_hpp

#define AbstractSimpleServer_hpp

#include "../hdelib-sockets-loader.hpp"

namespace HDE
{
    class AbstractSimpleServer
    {
    private:
        ListeningSocket *socket;
        virtual void accepter() = 0;
        virtual std::string handler() = 0;
        virtual void responder(std::string const &response) = 0;

    public:
        AbstractSimpleServer(int domain, int service, int protocol, int port, u_long interface, int backlog);
        ListeningSocket *get_socket();
    };
}

#endif
