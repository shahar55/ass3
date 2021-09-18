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

void TCPServer::handle() {
    CSVHandler c;
    dataHandler d;
    std::vector<std::vector<std::string>> s1 = c.readCSV("../resources/classified.csv"); // turn csv file into string or.
    std::vector<std::vector<std::string>> s2 = c.readCSV("../resources/TCPUnclassified.csv"); // turn csv file into stringvect vector.
    std::vector<ClassifiedFlower> c1 =  d.createClassedFlowersFromVector (s1); // create classified flowers from the string.
    std::vector<UnclassifiedFlower> c2 =  d.createUnClassedFlowersFromVector (s2); // create unclassified flowers from the string.
    std::vector<std::string> types; // the returned value vector, that is the types of the unFlowers.
    KNNGenerate k;
    /**
     * for loop that find for each unFlower his type according to knn algorithem.
     * **/
    for (UnclassifiedFlower u:c2) {
        std::vector<ClassifiedFlower> l = k.kthClosest(u,c1);
        std::string type = findFlowerName(l);
        types.push_back(type);
    }
    c.writeCSV("../resources/TCPOutput.csv" , types);
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