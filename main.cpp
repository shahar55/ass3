#include <iostream>
#include "ass1/knnGenerate.hpp"
#include "Command.hpp"
#include "AlgorithmSettingsCommand.hpp"
#include "UploadCommand.hpp"
#include "displayResCommand.hpp"
#include "downloadResCommand.hpp"
#include "exitCommand.hpp"
#include "ClassifyCommand.hpp"
#include "confusionMatrixCommand.hpp"
#include "StandartIO.hpp"
#include <vector>
#include <memory>
#include "CLI.hpp"

void printMenu(std::vector<Command*> commands) {
    std::cout<<"Welcome to the KNN Classifier Server. Please choose an option:\n";
    int i=1;
    for (Command* c : commands) {
        std::cout<<i<<". "<<c->getDescription()<<"\n";
        i++;
    }
}

int main() {
   CLI c;
   c.start();
   return 0;
}