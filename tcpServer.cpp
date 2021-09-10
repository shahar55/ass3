#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "ass1/CSVHandler.hpp"
#include "ass1/dataHandler.hpp"
#include "ass1/knnGenerate.hpp"
#include "ass1/findFlowerType.hpp"
#include "tcpServer.hpp"

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

void TCPServer::getData(int client_sock) {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0); // recieve string-data from client.
    if (read_bytes == 0) {
        closeServer();
        exit(0);
    }
    else if (read_bytes < 0) {
        perror("Error reading from socket");
        closeServer();
        exit(1);
    }
    else {
        cout << buffer << endl;
    }
    CSVHandler c;
    c.writeCSV("../resources/TCPUnclassified.csv" ,buffer); // write the string data into csv file.
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
    int sent = send(client_sock, "connection ESTABLISHED\n", 23, 0); // return msg to the client to inform him that the connection work.
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

void TCPServer::sendData(int client_sock) {
    CSVHandler c;
    handle();
    string v = c.readCSVToString("../resources/TCPOutput.csv");
    int sent_bytes = send(client_sock, v.c_str() , strlen(v.c_str()), 0); // send the types of the unflowers to the client.
    if (sent_bytes < 0) {
        perror("Error writing to socket");
        closeServer(); // shutdown socket.
        exit(1);
    }
}

void TCPServer::closeServer() {
    close(sock);
}
/*
 * main:
  create a tcp server, that get data from client  implement it, and send it back,
  according to knn aldorithem. 
 * */
int main() {
    TCPServer s(50000);
    int client = s.connectToClient();
    s.getData(client);
    s.sendData(client);
    s.closeServer();
    return 0;
}