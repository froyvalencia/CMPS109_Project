//Brian Nguyen 
//TCPConnector.cpp

#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include "TCPConnector.h"
// method to actively establish a connection with a server. It accepts the server port and a string containing 
//the server host name or IP address. If successful, a pointer to a TCPStream object is returned to the caller.
TCPStream* TCPConnector::connect( int port,const char* server)
{
    struct sockaddr_in address;
 
    memset (&address, 0, sizeof(address));

    address.sin_family = AF_INET;
    //Set to the TCP port on which the server is listening for connections/
    address.sin_port = htons(port);
    //converts the DNS Host name string to an IP address. if call fails, assumption
    //is made that the server string contains an IP address and is converted to an
    //IP address in network byte order.
    if (resolveHost(server, &(address.sin_addr)) != 0) {
        inet_pton(PF_INET, server, &(address.sin_addr));
    } 
    //obtains and defines socket descriptor. mandates the TCP Protocol
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    //passes in socket descriptor, pointer to server(structor sockaddr_in) structure, 
    //cast to a (struct sockAddr) pointer, and length of the srever address structure.
    // Connect is prefeced with the :: qualifier to compiler doesn't confuse this fn
    // w/ TCPConnector::connect().
    //If ::connect() succeeds a connection, a TCPStream object is created w/ the 
    //connected socket descriptor and server socket address info. Then a pointer to the 
    //TCPStream object is returned to the caller

    if (sd < 0) {
        perror("socket() failed");
        return NULL;
    }
    if (::connect(sd, (struct sockaddr*)&address, sizeof(address)) != 0) {
        perror("connect() failed");
        close(sd);
        return NULL;
    }
    return new TCPStream(sd, &address);
}


// converts a DNS host name to an IP address in network byte order by calling getaddrinfo(). 
int TCPConnector::resolveHost(const char* hostname, struct in_addr* addr) 
{
    struct addrinfo *res;
 
    int result = getaddrinfo (hostname, NULL, NULL, &res);
    //If the host name is not a valid DNS name, i.e. it is an IP address string or something else, 
    //-1 is returned, otherwise 0 is returned.
    if (result == 0) {
        memcpy(addr, &((struct sockaddr_in *) res->ai_addr)->sin_addr, 
               sizeof(struct in_addr));
        freeaddrinfo(res);
    }
    return result;
}