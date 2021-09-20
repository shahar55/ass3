#pragma once
#include "Command.hpp"
#include "ServerDataManagement.hpp"
#include <vector>
#include <string.h>
using namespace std;

class DisplayResCommand : public Command {
    public:
        DisplayResCommand(DefaultIO*,ServerDataManagement& manager);
        virtual void execute();
};