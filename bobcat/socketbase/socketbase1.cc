#include "socketbase.ih"

SocketBase::SocketBase(uint16_t port) throw (Errno)
:
    InetAddress(port)
{
    d_sock = ::socket(AF_INET, SOCK_STREAM, 0);   // 0: protocol, should be 0

    if (d_sock < 0)
        throw Errno("SocketBase::SocketBase(port)");
}