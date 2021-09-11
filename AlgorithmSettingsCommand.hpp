#pragma once
#include "Command.hpp"
#include "ass1/knnGenerate.hpp"
#include <vector>
#include <string.h>
using namespace std;

class AlgorithmSettingsCommand : public Command {
    private:
        KNNGenerate& gen;
        void changeParams(vector<string> newParams);
    public:
        AlgorithmSettingsCommand(KNNGenerate& gen);
        virtual void execute();
};