

#ifndef SimpleSocket_hpp

#define SimpleSocket_hpp

#include <stdio.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

namespace HDE
{
    class SimpleSocket
    {
    private:
        struct sockaddr_in address;
        int sock;
        int connection;

    public:
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface);
        void test_connection(int);

        // virtual methods
        virtual int connect_to_network(int sock, sockaddr_in address) = 0;

        // getter functions

        struct sockaddr_in get_address();
        int get_sock();
        int get_connection();

        // setter functions
        void set_connection(int connection);
    };

}

#endif
