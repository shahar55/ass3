#include <iostream>
#include "ass1/knnGenerate.hpp"
#include "Command.hpp"
#include "AlgorithmSettingsCommand.hpp"
#include "UploadCommand.hpp"
#include <vector>

void printMenu(vector<Command*> commands) {
    std::cout<<"Welcome to the KNN Classifier Server. Please choose an option:\n";
    int i=1;
    for (Command* c : commands) {
        cout<<i<<". "<<c->getDescription()<<"\n";
        i++;
    }
}
int main() {
    KNNGenerate k;
    vector<Command*> commands;
    UploadCommand u;
    /*AlgorithmSettingsCommand a(k);
    commands.push_back(&u);
    commands.push_back(&a);
    printMenu(commands);
    u.execute();*/
    u.execute();
}