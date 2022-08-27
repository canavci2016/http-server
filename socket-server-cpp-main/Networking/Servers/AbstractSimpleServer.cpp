#include "AbstractSimpleServer.hpp"

HDE::AbstractSimpleServer::AbstractSimpleServer(int domain, int service, int protocol, int port, u_long interface, int backlog)
{
    socket = new ListeningSocket(domain, service, protocol, port, interface, backlog);
}

HDE::ListeningSocket *HDE::AbstractSimpleServer::get_socket()
{
    return socket;
}
