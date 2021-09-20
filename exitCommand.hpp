#pragma once
#include "Command.hpp"
#include "ServerDataManagement.hpp"
#include <vector>
#include <string.h>
using namespace std;

class ExitCommand : public Command {
    public:
        ExitCommand(DefaultIO* dio,ServerDataManagement& manager);
        virtual void execute();
};