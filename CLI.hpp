#include "Command.hpp"
#include <vector>
#include "DefaultIO.hpp"
#pragma once
class CLI
{
private:
    DefaultIO* dio;
    void handleCommand(std::vector<Command*>&);
public:
    CLI(DefaultIO*);
    ~CLI();
    void start();
};