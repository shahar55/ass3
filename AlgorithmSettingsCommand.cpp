#include "AlgorithmSettingsCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/knnGenerate.hpp"
#include <sstream>
#include <vector>
using namespace std;

AlgorithmSettingsCommand::AlgorithmSettingsCommand(DefaultIO* dio,ServerDataManagement& manager):Command(dio,manager){
    description="algorithm settings";
}

void AlgorithmSettingsCommand::execute(){
    dio->write("The current KNN parameters are: "+manager.getKNN().getParameters()+"\n");
    string arg;
    vector<string> args;
    string newArgs = dio->read();
    if (newArgs=="PASS") {
        return;
    }
    istringstream split(newArgs);
    while (getline(split,arg,' ')) {
        args.push_back(arg);
    }
    changeParams(args);
}

void AlgorithmSettingsCommand::changeParams(vector<string> params) {
    if (params.size()==0)
        dio->write("good");
        return;
    if (params.size()!=2)
    {
        dio->write("Invalid amount of parameters");
        return;
    }
    if (atoi(params[0].c_str())<1) {
        dio->write("Invalid value for K");
        return;
    }
    if (params[1]!="EUC" && params[1]!="MAN" && params[1]!="CHE") {
        dio->write("Invalid value for distance metric");
        return;
    }
    manager.changeK(atoi(params[0].c_str()));
    manager.changeDistanceMetric(params[1]);
    dio->write("good");
}