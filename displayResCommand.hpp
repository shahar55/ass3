#pragma once
#include "Command.hpp"
#include "ass1/knnGenerate.hpp"
#include <vector>
#include <string.h>
using namespace std;

class DisplayResCommand : public Command {
    public:
        DisplayResCommand(DefaultIO*);
        virtual void execute();
};