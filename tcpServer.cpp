#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "ass1/CSVHandler.hpp"
#include "ass1/dataHandler.hpp"
#include "ass1/knnGenerate.hpp"
#include "ass1/findFlowerType.hpp"
#include "tcpServer.hpp"
#include "CLI.hpp"
#include "SocketIO.hpp"

using namespace std;

TCPServer::TCPServer(const int server_port):server_port(server_port) {
    initializeSin();
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(sock, 5) < 0) {
        perror("Error listening to a socket");
        exit(1);
    }
}

void TCPServer::initializeSin() {
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
}

int TCPServer::connectToClient() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);
    if (client_sock < 0) {
        perror("Error accepting client");
        closeServer();
        exit(1);
    }
    return client_sock;
}

void TCPServer::getConnections() {
    while (true) {
        int* client = new int(connectToClient());
        pthread_t t;
        pthread_create(&t,NULL,handleConnction,client);
    }
}

void TCPServer::closeServer() {
    close(sock);
}

void* TCPServer::handleConnction(void* sock) {
    int clientSock = *((int*)sock);
    free(sock);
    SocketIO soc(clientSock);
    CLI cli(&soc);
    cli.start();
    return NULL;
}


/*
 * main:
  create a tcp server, that get data from client  implement it, and send it back,
  according to knn aldorithem. 
 * */
int main() {
    TCPServer s(50000);
    s.getConnections();
    //s.closeServer();
    return 0;
}