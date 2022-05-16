#pragma once
#include "Command.hpp"
#include "ServerDataManagement.hpp"
#include <vector>
#include <string.h>
using namespace std;

class ClassifyCommand : public Command {
    private:
        static void classify(ServerDataManagement* manager);
    public:
        ClassifyCommand(DefaultIO* dio, ServerDataManagement& managerGiven);
        virtual void execute();
};