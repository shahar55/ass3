#pragma once
#include "Command.hpp"
#include "ass1/knnGenerate.hpp"
#include <vector>
#include <string.h>
using namespace std;

class ClassifyCommand : public Command {
    private:
        KNNGenerate& gen;
        void classify();
    public:
        ClassifyCommand(DefaultIO* dio, KNNGenerate& gen);
        virtual void execute();
};