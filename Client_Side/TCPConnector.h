//Brian Nguyen 
//TCPConnector.H
//Provides the Connect() method to actively establist a conneciton wtih a server
//by accepting a port and a string containing the server host name or IP Address.
//If connecstion is successfull, returns a pointer to a TCPStream object to the caller.
#ifndef __tcpconnector_h__
#define __tcpconnector_h__
#include "TCPStream.h"

 
class TCPConnector
{
  public:
  	//Connect() takes a server host name or IP address string & server listening port args
    TCPStream* connect(int port, const char* server);
   private:
    int resolveHost(const char* host, struct in_addr* addr);
};

#endif