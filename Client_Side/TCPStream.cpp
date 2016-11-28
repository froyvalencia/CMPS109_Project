//Brian Nguyen 
//TCPStream.cpp
#include <arpa/inet.h>
#include "TCPStream.h"
 
//Constructor
//Stores the connected socket descript then converts the socket info structure fields
//to a peer IP Address string and peer TCP port. These params can be inspected with calls
//to TCP::::getPeerIP() and TCPStream::getPeerPort();
TCPStream::TCPStream(int sd, struct sockaddr_in* address) : m_sd(sd){
    char ip[50];
    inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr), 
              ip, sizeof(ip)-1);
    m_peerIP = ip;
    m_peerPort = ntohs(address->sin_port);
}
//Destructor
//Used to close the TCP Connection between peers.
TCPStream::~TCPStream(){
    close(m_sd);
}

ssize_t TCPStream::send(const char* buffer, size_t len) {
    return write(m_sd, buffer, len);
}

ssize_t TCPStream::receive(char* buffer, size_t len) {
    return read(m_sd, buffer, len);
}

string TCPStream::getPeerIP() {
    return m_peerIP;
}

int TCPStream::getPeerPort() {
    return m_peerPort;
}
