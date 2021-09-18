/* 
 * class tcpServer.
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

class TCPServer
{
    int sock; // the server socker.
    const int server_port;
    struct sockaddr_in sin;
    void initializeSin();
    int connectToClient(); // check and create the connection between this server to a client.
    static void* handleConnction(void* sock);

    public:
        TCPServer(const int);
        void getConnections(); 
        void closeServer();
};