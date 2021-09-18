#pragma once
#include "DefaultIO.hpp"
#include <thread>

class SocketIO:public DefaultIO {
private:
    int fd = -1;
    bool m_terminate = false;

    

    void stop();

public:
    explicit SocketIO(int fd);
    ~SocketIO();
    virtual void write(std::string msg);
    virtual std::string read();
    virtual void close();
    void terminate();
    virtual std::string readData();
};