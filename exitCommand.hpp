#pragma once
#include "Command.hpp"
#include "ass1/knnGenerate.hpp"
#include <vector>
#include <string.h>
using namespace std;

class ExitCommand : public Command {
    public:
        ExitCommand(DefaultIO* dio);
        virtual void execute();
};