#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "udpServer.hpp"
#include "ass1/CSVHandler.hpp"
#include "ass1/dataHandler.hpp"
#include "ass1/knnGenerate.hpp"
#include "ass1/findFlowerType.hpp"
using namespace std;

UDPServer::UDPServer(const int server_port):server_port(server_port)
{
    initializeSin();
    mastersocket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (bind(mastersocket_fd, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error binding to socket");
    }
}

void UDPServer::initializeSin() {
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
}

struct sockaddr_in UDPServer::getData() {
    struct sockaddr_in from;
    CSVHandler c;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096]={};
    int bytes = recvfrom(mastersocket_fd, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("Error reading from socket");
        closeServer();
        exit(1);
    }
    cout << "Connection established... The client sent: " << buffer << endl;
    c.writeCSV("../resources/UDPUnclassified.csv",buffer);
    return from;
}

void UDPServer::handle() {
    CSVHandler c;
    dataHandler d;
    std::vector<std::vector<std::string>> s1 = c.readCSV("../resources/classified.csv"); // turn csv file into string or.
    std::vector<std::vector<std::string>> s2 = c.readCSV("../resources/UDPUnclassified.csv"); // turn csv file into stringvect vector.
    std::vector<ClassifiedFlower> c1 =  d.createClassedFlowersFromVector (s1); // create classified flowers from the string.
    std::vector<UnclassifiedFlower> c2 =  d.createUnClassedFlowersFromVector (s2); // create unclassified flowers from the string.
    std::vector<std::string> types; // the returned value vector, that is the types of the unFlowers.
    KNNGenerate k;
    /**
     * for loop that find for each unFlower his type according to knn algorithem.
     * **/
    for (UnclassifiedFlower u:c2) {
        std::vector<ClassifiedFlower> l = k.kthClosest(u,c1,5);
        std::string type = findFlowerName(l);
        types.push_back(type);
    }
    c.writeCSV("../resources/UDPOutput.csv" , types);
}

void UDPServer::sendData(struct sockaddr_in from) {
    CSVHandler c;
    handle();
    string v = c.readCSVToString("../resources/UDPOutput.csv"); // turn the data of the types in this file into  string 
    int sent_bytes = sendto(mastersocket_fd, v.c_str() ,strlen(v.c_str()) , 0, (struct sockaddr *) &from ,sizeof(from));
    if (sent_bytes < 0) {
        perror("Error writing to socket");
        closeServer();
        exit(1);
    }
}

void UDPServer::closeServer() {
    close(mastersocket_fd);
}

/*
 * main:
  create a udp server, that get data from client  implement it, and send it back,
  according to knn aldorithem. 
 * */
int main() {
    UDPServer s(50001);
    struct sockaddr_in client = s.getData();
    s.sendData(client);
    s.closeServer();
    return 0;
}