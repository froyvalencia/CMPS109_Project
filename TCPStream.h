//Brian Nguyen 
//TCPStream.H
//Methods to send/recieve data over a TCP Connection between peers: "client/Server"

#ifndef __tcpstream_h__
#define __tcpstream_h__

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
 
using namespace std;
 
class TCPStream{
    int m_sd;
    string m_peerIP;
    int m_peerPort;
    //char* buffer;

  public:
    //TCP objects are created by TCP Connector and TCP Acceptor objects only
    friend class TCPAcceptor;
    friend class TCPConnector;
    //Destructor to used to close the TCP Connection between peers.
    ~TCPStream();
    //TCPStream::send() and TCPStream::receive() simply wrap calls to read() and write(), 
    //returning the number of bytes sent and bytes received.
    ssize_t send(const char* buffer, size_t len);
    ssize_t receive(char* buffer, size_t len);

    //return the IP address and TCP port information of the peer to which the network application,
    // client or server, are connected. 
    string getPeerIP();
    int getPeerPort();

  private:
    //Declared private to prevent TCP Stream from being called directly by
    // any other objects other than TCPAcceptor and TCPConnector.
    TCPStream();
    TCPStream(int sd, struct sockaddr_in* address);
    TCPStream(const TCPStream& stream);
};

#endif
