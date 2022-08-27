#include "ListeningSocket.hpp"

int main(int argc, char **argv)
{

    HDE::BindingSocket listenSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY);

    // HDE::ListeningSocket listenSocket(AF_INET, SOCK_STREAM, 0, 4000, INADDR_ANY, 10);
}