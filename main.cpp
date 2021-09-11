#include <iostream>
#include "ass1/knnGenerate.hpp"
#include "Command.hpp"
#include "AlgorithmSettingsCommand.hpp"
#include "UploadCommand.hpp"
#include "displayResCommand.hpp"
#include "downloadResCommand.hpp"
#include "ClassifyCommand.hpp"
#include "StandartIO.hpp"
#include <vector>
#include <memory>

void printMenu(std::vector<Command*> commands) {
    std::cout<<"Welcome to the KNN Classifier Server. Please choose an option:\n";
    int i=1;
    for (Command* c : commands) {
        std::cout<<i<<". "<<c->getDescription()<<"\n";
        i++;
    }
}

int main() {
    KNNGenerate k(5,"MAN");
    StandartIO s;
    UploadCommand u(&s);
    AlgorithmSettingsCommand a(&s,k);
    ClassifyCommand c(&s,k);
    DisplayResCommand d(&s);
    DownloadResCommand download(&s);
    vector<Command*> commands;
    commands.push_back(&u);
    commands.push_back(&a);
    commands.push_back(&c);
    commands.push_back(&d);
    commands.push_back(&download);
    printMenu(commands);
    commands[4]->execute();
    return 0;
}