#pragma once
#include "Command.hpp"
#include "ServerDataManagement.hpp"
#include <vector>
#include <string.h>
using namespace std;

class AlgorithmSettingsCommand : public Command {
    private:
        void changeParams(vector<string> newParams);
    public:
        AlgorithmSettingsCommand(DefaultIO* dio, ServerDataManagement& managar);
        virtual void execute();
};