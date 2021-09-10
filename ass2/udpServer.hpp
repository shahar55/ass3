/* 
 * class UDPServer.
 *
 *  Created on: 21/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */
#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>

class UDPServer
{
    int mastersocket_fd; // the server socker.
    const int server_port;
    struct sockaddr_in sin;
    void initializeSin();

    public:
        UDPServer(const int);
        void sendData(struct sockaddr_in);
        struct sockaddr_in getData(); // get the first data from client (in order to check the connection). 
        void handle(); // Classifies the data from the client
        void closeServer();
};