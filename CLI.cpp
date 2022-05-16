#include "CLI.hpp"
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
#include "ServerDataManagement.hpp"
#include "StandartIO.hpp"
#include "SocketIO.hpp"
#include <vector>
#include <memory>
#include <sys/socket.h>
#include <stdio.h>    
#include <math.h>  
#include <stdlib.h> 
using namespace std; 
void backToMenu();
CLI::CLI(DefaultIO* dio):dio(dio)
{
}

CLI::~CLI()
{
}
void CLI:: start() { 
    char opr;
// display different operation of the calculator  
    dio->write("Welcome to the KNN Classifier Server. Please choose an option:\n");
    ServerDataManagement manager;
    UploadCommand u(dio,manager);
    AlgorithmSettingsCommand a(dio,manager);
    ClassifyCommand c(dio,manager);
    DisplayResCommand d(dio,manager);
    DownloadResCommand download(dio,manager);
    ConfusionMatrixCommand cm(dio,manager);
    ExitCommand e(dio,manager);
    vector<Command*> commands;
    commands.push_back(&u);
    commands.push_back(&a);
    commands.push_back(&c);
    commands.push_back(&d);
    commands.push_back(&download);
    commands.push_back(&cm);
    commands.push_back(&e);
    std::string menu = getMenu(commands);
    bool toContinue = true;
    do {
        dio->write(menu);
        toContinue = handleCommand(commands);
    } while(toContinue);    
}

string CLI::getMenu(vector<Command*>& commands) {
    string menu="";
    int i=1;
    for (Command* c : commands) {
        menu += (to_string(i) + ". " + c->getDescription()+ "\n");
        i++;
    }
    return menu;
}

bool CLI::handleCommand(vector<Command*>& commands) {
    char opr;
    string StringOpr;
    StringOpr = dio->read();
    opr = StringOpr[0];
    switch (opr)  
    {
        case '1':
            commands[0]->execute();
        break;  
        case '2': 
            commands[1]->execute(); 
        break;  
        case '3':
            commands[2]->execute();    
        break;  
        case '4':
            commands[3]->execute();   
        break;  
        case '5':
            commands[4]->execute();    
        break;  
        case '6': 
            commands[5]->execute(); 
        break;  
        case '7':  
            commands[6]->execute();
            return false;
        break;  
        default: 
            dio->write("The command is not supportable");
        break;
    }
    return true;
}
