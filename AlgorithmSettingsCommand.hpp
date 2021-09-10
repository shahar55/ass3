#pragma once
#include "Command.hpp"
#include "ass1/knnGenerate.hpp"

class AlgorithmSettingsCommand : public Command {
    private:
        KNNGenerate gen;
    public:
        AlgorithmSettingsCommand(KNNGenerate gen);
        virtual void execute();
};