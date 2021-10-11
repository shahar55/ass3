#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <unistd.h>
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

void Client::sendData(const char* data) {
    int data_len = strlen(data);
    int sent_bytes = send(sock, data, data_len, 0);
    if (sent_bytes < 0) {
        perror("Error while sending data to server");
    }
}

string Client::getData() {
    char buffer[16384];
    memset(buffer,0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        // connection is closed
    }
    else if (read_bytes < 0) {
        // error
    }
    send(sock, "GOT", 3, 0);
    return buffer;
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
    return;
}

void Client::uploadCommand(){
    CSVHandler handler;
    string train;
    string test;
    cout<<getData();
    getline(cin,train);
    train = handler.readCSVToString(train.c_str());
    sendData(train.c_str());
    cout<<getData();
    getline(cin,test);
    test = handler.readCSVToString(test.c_str());
    sendData(test.c_str());
    cout<<getData();
}

void Client::algorithmSettingsCommand() {
    cout<<getData();
    string params;
    getline(cin,params);
    if (params.length()==0) {
        sendData("PASS");
    }
    else {
        sendData(params.c_str());
    }
    string rec = getData();
    if (rec=="OK") {
        return;
    }
    else {
        cout<<rec;
    }

}

void Client::classifyCommand() {
    cout<<getData();
}

void Client::displayResultsCommand(){
    std:;string data = getData(); 
    cout<<data;
    if (data.compare("ERROR: the data hasn't been classified.\n") == 0) {
        return;
    }
    cout<<getData();
}

void Client::downloadResultsCommand(){
    CSVHandler handler;
    string output = getData();
    if (output.compare("ERROR: the data hasn't been classified.\n") == 0) {
        cout << output;
        return;
    }
    string path;
    cout<<"Please Enter the path to save the results.\n";
    getline(cin,path);
    handler.writeCSV(path,output);
    cout<<getData();
}

void Client::confMatrixCommand() {
    cout<<getData();
}

void Client::handleConnction() {
    cout << getData();
    char choice;
    while (choice!='7') {
        cout << getData();
        cin>>choice;
        cin.ignore();
        // Create connection
        // depending on the input
        switch (choice) {
            case '1': {
                sendData("1");
                uploadCommand();
                break;
            }
            case '2': {
                sendData("2");
                algorithmSettingsCommand();
                break;
            }
            case '3': {
                sendData("3");
                classifyCommand();
                break;
            }
            case '4': {
                sendData("4");
                displayResultsCommand();
                break;
            }
            case '5': {
                sendData("5");
                downloadResultsCommand();
                break;
            }
            case '6': {
                sendData("6");
                confMatrixCommand();
                break;
            }
            case '7': {
                sendData("7");
                closeConnection();
                return;
                break;
            }
            default: {
                std:: cout<<"Invalid Input\n";
                break;
            }
        }
    }
}

void Client::closeConnection(){
    shutdown(sock,2);
    close(sock);
}

/*
 * main:
  create a client, that decide the data transformation - protocol,
  send data to server, get data back and implement it.
  according to knn aldorithem.
  (Achieved by using client functions)
 * */

int main() {
    Client c("127.0.0.1",50000);
    c.handleConnction();
}