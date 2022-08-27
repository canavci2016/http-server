
#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    // establish connection
    sock = socket(domain, service, protocol);
    test_connection(sock);
};

void HDE::SimpleSocket::test_connection(int item)
{
    if (item < 0)
    {
        perror("failed to connect");
        exit(EXIT_FAILURE);
    }
}
// getter functions

struct sockaddr_in HDE::SimpleSocket::get_address()
{
    return address;
};

int HDE::SimpleSocket::get_sock()
{
    return sock;
}

int HDE::SimpleSocket::get_connection()
{
    return connection;
}

// setter functions

void HDE::SimpleSocket::set_connection(int connection)
{
    this->connection = connection;
}