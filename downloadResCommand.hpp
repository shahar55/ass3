#pragma once
#include "Command.hpp"
#include "ass1/knnGenerate.hpp"
#include <vector>
#include <string.h>
using namespace std;

class DownloadResCommand : public Command {
    public:
        DownloadResCommand(DefaultIO* dio);
        virtual void execute();
};