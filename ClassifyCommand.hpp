#pragma once
#include "Command.hpp"
#include "ServerDataManagement.hpp"
#include <vector>
#include <string.h>
using namespace std;

class ClassifyCommand : public Command {
    private:
        void classify();
    public:
        ClassifyCommand(DefaultIO* dio, ServerDataManagement& manager);
        virtual void execute();
};