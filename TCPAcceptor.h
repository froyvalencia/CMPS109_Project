//Brian Nguyen
//TCPAcceptor.h
//includes member variables for the listening socket descriptor, the socket address information
// – IP address and TCP port – and a flag that indicates whether or not the TCPAcceptor has 
//started listening for connections. Two public methods are supported. One to start the listening
// and the other to accept connections.

#ifndef __tcpacceptor_h__
#define __tcpacceptor_h__

#include <string>
#include <netinet/in.h>
#include "TCPStream.h"
 
using namespace std;
 
class TCPAcceptor
{
    string m_address; //IP Address
    int    m_port; //TCP port
    int    m_lsd; //Listening Socket Descriptor
    bool   m_listening; //A flag determining whether or not the TCPAcceptor has started listenting
 
  public:
    TCPAcceptor(int port, const char* address=""); //costructor that takes TCP port and IP address in
    ~TCPAcceptor(); // empty Destructor
 
    int start();
    TCPStream* accept();
 
  private:
    TCPAcceptor() {}
};

#endif