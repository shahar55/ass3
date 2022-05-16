#include "SocketIO.hpp"
#include <cassert>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <pthread.h>
#include <string.h>
#include "ass1/CSVHandler.hpp"
SocketIO::SocketIO(int fd) : fd(fd) {
}

SocketIO::~SocketIO() {
    this->stop();
}

void SocketIO::stop() {
    closeConnection();
}



std::string SocketIO::read() {
    char buffer[16384];
    memset(buffer,0, sizeof(buffer));
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(fd, buffer, expected_data_len, 0); // recieve string-data from client.
    if (read_bytes == 0) {
        closeConnection();
        exit(0);
    }
    else if (read_bytes < 0) {
        perror("Error reading from socket");
        closeConnection();
    }
    return buffer;
}


void SocketIO::write(std::string msg) {
    int sent_bytes = send(fd, msg.c_str(), msg.length(), 0);
    if (sent_bytes < 0) {
        perror("Error writing to socket");
    }
    std::string done = read();
    if (done=="GOT")
        return;
}

std::string SocketIO::readData() {
    std::string filePath;
    filePath = read();
    CSVHandler handler;
    return handler.readCSVToString(filePath.c_str());
}

void SocketIO::terminate() {
    this->m_terminate = true;
}
void SocketIO::closeConnection() {
    shutdown(fd,2);
    close(fd);
    return;
}