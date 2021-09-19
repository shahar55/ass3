#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sstream>
#include "client.hpp"
#include "ass1/CSVHandler.hpp"

using namespace std;

Client::Client(const char* ip_address,const int port_no) : ip_address(ip_address),port_no(port_no),protocol("TCP")
 // initialize the client. (the defulet protocol is tcp). 
{
    initializeSin();
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
    }
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("Error connecting to server");
    }
}

void Client::initializeSin() {
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
}

void Client::sendDataByTCP(const char* data) {
    int data_len = strlen(data);
    int sent_bytes = send(sock, data, data_len, 0);
    if (sent_bytes < 0) {
        perror("Error while sending data to server");
    }
}

void Client::sendDataByUDP(const char* data) {
    int data_len = strlen(data);
    int sent_bytes = sendto(sock, data, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("Error writing to socket");
    }
}

string Client::getDataByUDP() {
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096]={};
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("Error reading from socket");
    }
    cout<<buffer<<endl;
    return buffer;
}

string Client::getDataByTCP() {
    char buffer[4096] = {};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    }
    else if (read_bytes < 0) {
        // error
    }
    cout<<buffer<<endl;
    return buffer;
}

bool Client::changeProtocol(string pro) {
    if (pro=="TCP") {
        return true;
    }
    else if (pro=="UDP") {
        close(sock);
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        if (sock < 0) {
        perror("Error creating socket");
        }
        sin.sin_port = htons(50001);
        protocol = "UDP";
        return true;
    }
    else if (pro!="TCP") { // if the given protocol is not udp and not tcp, exit!
        cout << "The protocol "<< pro << " does not supportable.";
    }
    return false;
}

void Client::operateCommand(const char* command) {
    vector<string> out;
    stringstream ss(command);
    string s;
    /**
     * while loop that sparate the command by spaces and push the sapared values into vector.
     * */
    while (getline(ss,s,' ')) {
        out.push_back(s);
    }
    if (out.size()!=3) { // Exit the program if exactly three arguments are not inserted.
        cout << "The command is not supportable.\n";
        exit(0);
    }
    handleCommand(out);
}

void Client::handleCommand(std::vector<std::string> out) {
    if (!changeProtocol(out[0])) { // If the protocal type is not properly inserted into the system, exit the program.
        exit(0);
    }
    CSVHandler c;
    string v = c.readCSVToString(out[1].c_str());
    sendData(v.c_str());
    string output = getData();
    c.writeCSV(out[2],output);
}

void Client::sendData(const char* data) {
    if (protocol=="UDP") {
        sendDataByUDP(data);
    }
    else if (protocol=="TCP")
        sendDataByTCP(data);
}

string Client::getData() {
    if (protocol=="UDP") {
        return getDataByUDP();
    }
    else if (protocol=="TCP")
        return getDataByTCP();
    return NULL;
}
void* Client::handleConnction(void* clientSock) {
       int sock = *((int*)clientSock);
 
    printf("Connection estabilished\n");
 
    int choice;
        cin >> choice;
         // Create connection
    // depending on the input
    string client_request;
    switch (choice) {
    case 1: {
        string client_request = "1";
        break;
    }
    case 2: {
        string client_request = "2";
        break;
    }
    case 3: {
        string client_request = "3";
        break;
    }
    case 4: {
        string client_request = "4";
        break;
    }
    case 5: {
        string client_request = "5";
        break;
    }
    case 6: {
        string client_request = "";
        break;
    }
    case 7: {
        string client_request = "7";
        break;
    }

    default:
        std:: cout<<"Invalid Input\n";
        break;
    }
    int data_len = strlen(client_request.c_str());
    int sent_bytes = send(sock, client_request.c_str(), data_len, 0);
    if (sent_bytes < 0) {
     perror("Error while sending data to server");
    }
    pthread_exit(NULL);
    
    return 0;
}
/*
 * main:
  create a client, that decide the data transformation - protocol,
  send data to server, get data back and implement it.
  according to knn aldorithem.
  (Achieved by using client functions)
 * */
void Client:: choosePath() {
     int* socketPointer = new int(sock);
    while (1)
    {
       pthread_t tid;
        pthread_create(&tid, NULL,
                       handleConnction,
                       socketPointer);
        sleep(20);
    // Suspend execution of
    // calling thread
    pthread_join(tid, NULL);
    }
    free(socketPointer);
    return;
}
int main() {
    Client c("127.0.0.1",50000);
    c.choosePath();
}