#include "Command.hpp"
#include <vector>
#include <string.h>
#include "DefaultIO.hpp"
#pragma once
class CLI
{
private:
    DefaultIO* dio;
    bool handleCommand(std::vector<Command*>&);
    std::string getMenu(std::vector<Command*>&);
public:
    CLI(DefaultIO*);
    ~CLI();
    void start();
};