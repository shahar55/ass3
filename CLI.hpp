#include "Command.hpp"
#include <vector>
#pragma once
class CLI
{
private:
    void handleCommand(std::vector<Command*>&);
public:
    CLI();
    ~CLI();
    void start();
};