//Brian Nguyen
//client.cpp


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>    
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include "TCPConnector.h"
#include "thread.h"
#include "parser.h"
using namespace std;



int main(int argc, char** argv)
{
    if (argc < 3 || argc > 4) {
        printf("usage: %s <txtfile> <port> <ip>\n", argv[0]);
        exit(1);
    }
    
    int len;
    string message;
    char line[256];
    TCPConnector* connector = new TCPConnector();
    TCPStream* stream = connector->connect( atoi(argv[2]), argv[3]);
        if (stream) {
        message = argv[1];
        stream->send(message.c_str(), message.size());

        printf("sent: %s\n", message.c_str());
        len = stream->receive(line, sizeof(line));
        line[len] = '\0';
        printf(" Prossesed: %s\n", line);
        delete stream;
        }

    exit(0);
}

