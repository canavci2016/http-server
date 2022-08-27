
#include "BindingSocket.hpp"

// Constructor
HDE::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface) : SimpleSocket(domain, service, protocol, port, interface)
{
    std::cout << "bind_ops was called from BindingSocket constructor" << std::endl;
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connection(get_connection());
}

int HDE::BindingSocket::connect_to_network(int sock, sockaddr_in address)
{
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}