//Brian Nguyen
//Server.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "thread.h"
#include "linequeue.h"
#include "TCPAcceptor.h"
#include "Machine.h"
class WorkItem
{
    TCPStream* m_stream;
 
  public:
    WorkItem(TCPStream* stream) : m_stream(stream) {}
    ~WorkItem() { delete m_stream; }
 
    TCPStream* getStream() { return m_stream; }
};

class ConnectionHandler : public Thread
{
    linequeue<WorkItem*>& m_queue;
    public:
        ConnectionHandler(linequeue<WorkItem*>& queue) : m_queue(queue) {}
     
        void* run() {
            // Remove 1 item at a time and process it. Blocks if no items are 
            // available to process.
            for (int i = 0;; i++) {
                printf("thread %lu: waiting for MIS line...\n", 
                       (long unsigned int)self());
                WorkItem* item = m_queue.remove();
                printf("thread %lu: recieved MIS Line\n", 
                       (long unsigned int)self());
                TCPStream* stream = item->getStream();

               // Echo messages back the client until the connection is cancelled. with cntrl+c


                char input[256];
                int len;
                //input is the line that is taken in. consider line as the "item" in the queue. 
                // You can take input here and then 
                while ((len = stream->receive(input, sizeof(input)-1)) > 0 ){
                    input[len] = '\0';
                   // printf("FLAG HERE %s\n", input);
                    Machine *m = new Machine(input);
                    m->executeAll();
                    stream->send(input, len);//send to client. input here.
                    //verified print on server here.

                    printf("thread %lu: Proccessed: %s\n\n", (long unsigned int)self(), input);
                  delete m; 
                }        
             
                delete item; 

            }
            return NULL; //Never reaches here.
        }
};

int main(int argc, char** argv)
{
    // Process command line arguments
    if ( argc < 2 || argc > 3 ) {
        printf("usage: %s <port> <ip>\n", argv[0]);
        exit(-1);
    }
    //Number of threads. Too many threads will slow down our processes because of having to constantly switch inbetween.
    int workers = 5;
    int port = atoi(argv[1]);
    string ip;
    if (argc == 3) { 
        ip = argv[2];
    }
 
    // Create the queue and consumer (worker) threads
    linequeue<WorkItem*>  queue;
    for (int i = 0; i < workers; i++) {
        ConnectionHandler* handler = new ConnectionHandler(queue);
        if (!handler) {
            printf("Could not create ConnectionHandler %d\n", i);
            exit(1);
        } 
        handler->start();
    }
 
    // Create an acceptor then start listening for connections
    WorkItem* item;
    TCPAcceptor* connectionAcceptor;
    if (ip.length() > 0) {
        connectionAcceptor = new TCPAcceptor(port, (char*)ip.c_str());
    }
    else {
        connectionAcceptor = new TCPAcceptor(port);        
    }                                        
    if (!connectionAcceptor || connectionAcceptor->start() != 0) {
        printf("Could not create an connection acceptor\n");
        exit(1);
    }

    // Add a work item to the queue for each connection
    while (1) {
        TCPStream* connection = connectionAcceptor->accept(); 
        if (!connection) {
            printf("Could not accept a connection\n");
            continue;
        }
        item = new WorkItem(connection);
        if (!item) {
            printf("Could not create work item a connection\n");
            continue;
        }
        queue.add(item);
    }
 
    // Should never get here
    exit(0);
}
