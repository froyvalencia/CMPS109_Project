//Brian Nguyen
//TCPAcceptor.cpp
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include "TCPAcceptor.h"
//Constructor
//This constructor sets m_lsd indicating that the listening socket has not been created.
TCPAcceptor::TCPAcceptor(int port, const char* address) 
	: m_lsd(0), m_port(port), m_address(address), m_listening(false) {}
//Destructor
//If the listening socket has been created then it is closed in the destructor.
TCPAcceptor::~TCPAcceptor(){
    if (m_lsd > 0)
        close(m_lsd);
}
//Accepts connections
int TCPAcceptor::start()
{
	//Creating a listening socket involves the most socket calls of any operation. before
	//going through the series of calls, (TCPAcceptor:Start()) checkto see if a listening 
	//socket already exists. If so, the method just returns 0.
    if (m_listening == true) { return 0; }
 	//creates a listening socket descriptor for TCP and IP The socket() calls for servers 
 	//is the same as it is for clients. Same for peers...
    m_lsd = socket(PF_INET, SOCK_STREAM, 0);
 
    struct sockaddr_in address; //initializes socket addres structure.
    memset(&address, 0, sizeof(address));
    address.sin_family = PF_INET;//sets the protocol family,
    address.sin_port = htons(m_port); // initializes listening TCP port

    //If the server listening IP address has m_address has been set, inet_pton is called to 
    //convert it to a numerical IP address in network byte order.
    if (m_address.size() > 0) {
        inet_pton(PF_INET, m_address.c_str(), &(address.sin_addr));
    }
    //if fails, then the socket listening address is set to any IP address meaning the server will
    //listen for connections on all the network interfaces.
    else {
        address.sin_addr.s_addr = INADDR_ANY;
    }
 	//to disable waiting time intbetwen listening for IP and Port, we set the so_reuseADDR socket option for listening
 	//before calling bind()
    int optval = 1;
    setsockopt(m_lsd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
 
 	//Bind the listening socket adddresss to the scoket descriptor
    int result = bind(m_lsd, (struct sockaddr*)&address, sizeof(address));
    //if bind() fails, error message and return value by bind().
    if (result != 0) {
        perror("bind() failed");
        return result;
    }
    //turn on server listening with the listen() fn. 2nd arg of this fn sets num of connections
    //requests TCP will queue. 
    result = listen(m_lsd, 5);
    //if listen fails(), error message and return value by listen()
    if (result != 0) {
        perror("listen() failed");
        return result;
    }
    //if listen() is success, sets listning flar to treue and returns value.
    m_listening = true;
    return result;
}


//Accept connections from clients
TCPStream* TCPAcceptor::accept()
{
	//TCPAcceptor::accept() returns NULL if the socket is not in a listening state. 
    if (m_listening == false) {
        return NULL;
    }
	// Otherwise a sockaddr_in structure is set to NULL and a pointer to it, cast as a sockaddr structure, is passed to ::accept(). 
    struct sockaddr_in address;
    socklen_t len = sizeof(address);
    memset(&address, 0, sizeof(address));

    //When a connection with a client is established, the socket address structure is populated with the client’s socket information and 
    //::accept() returns 0. Then a pointer to a TCPStream object is returned to the caller.
    int sd = ::accept(m_lsd, (struct sockaddr*)&address, &len);
    if (sd < 0) {
        perror("accept() failed");
        return NULL;
    }
    return new TCPStream(sd, &address);
}