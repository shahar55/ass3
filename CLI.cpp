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
#include "StandartIO.hpp"
#include <vector>
#include <memory>
#include<stdio.h>    
#include<math.h>  
#include<stdlib.h> 
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
    KNNGenerate k(5,"EUC");
    UploadCommand u(dio);
    AlgorithmSettingsCommand a(dio,k);
    ClassifyCommand c(dio,k);
    DisplayResCommand d(dio);
    DownloadResCommand download(dio);
    ConfusionMatrixCommand cm(dio);
    ExitCommand e(dio);
    vector<Command*> commands;
    commands.push_back(&u);
    commands.push_back(&a);
    commands.push_back(&c);
    commands.push_back(&d);
    commands.push_back(&download);
    commands.push_back(&cm);
    commands.push_back(&e);
    //printMenu(commands);./
    do {
        int i=1;
        for (Command* c : commands) {
            std::cout<<i<<". "<<c->getDescription()<<"\n";
            i++;
        }
        handleCommand(commands);
        cout <<" \n------------------------------\n";
        backToMenu();
    }while(opr != 7);    
}
void backToMenu() {
    string c;
    getline(cin,c);
}

void CLI::handleCommand(vector<Command*>& commands) {
    char opr;
    cin >> opr;
    cin.ignore();
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
    break;  
    default:  
    cout <<"Something is wrong..!!";  
    break;  
    }  
}
