#include "SocketIO.hpp"
#include <cassert>
#include <sys/socket.h>
#include <errno.h>
#include <iostream>
#include <pthread.h>
#include "ass1/CSVHandler.hpp"
SocketIO::SocketIO(int fd) : fd(fd) {
}

SocketIO::~SocketIO() {
    this->stop();
}

void SocketIO::stop() {
    close();
}



std::string SocketIO::read() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(fd, buffer, expected_data_len, 0); // recieve string-data from client.
    if (read_bytes == 0) {
        close();
        exit(0);
    }
    else if (read_bytes < 0) {
        perror("Error reading from socket");
        close();
        exit(1);
    }

    return buffer;
}


void SocketIO::write(std::string msg) {
    int n = send(this->fd, msg.c_str(), msg.size(), 0);
    if (n != static_cast<int>(msg.size())) {
        std::cout << "Error while sending message, message size: " << msg.size() << " bytes sent: " << std::endl;
    }
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
void SocketIO::close() {
    return;
}