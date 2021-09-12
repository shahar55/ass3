#pragma once
#include <string>
#include <iostream>
#include "DefaultIO.hpp"
class StandartIO:public DefaultIO{
    public:
        StandartIO();
        virtual std::string read();
        virtual std::string readData();
        virtual void write(std:: string msg);
        virtual void close();
};