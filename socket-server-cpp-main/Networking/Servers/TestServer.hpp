

#ifndef TestServer_hpp

#define TestServer_hpp

#include "AbstractSimpleServer.hpp"
#include <unistd.h>
#include <netinet/in.h>

namespace HDE
{
    class TestServer : public AbstractSimpleServer
    {
    private:
        char buffer[30000] = {0};
        int new_socket;

        void accepter();
        std::string handler();
        void responder(std::string const &response);

    public:
        TestServer();
        void launch();
    };
}

#endif
