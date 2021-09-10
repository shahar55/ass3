#include "AlgorithmSettingsCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/knnGenerate.hpp"
using namespace std;

AlgorithmSettingsCommand::AlgorithmSettingsCommand(KNNGenerate gen):gen(gen){
    description="algorithm settings";
    dio = StandartIO();
}

void AlgorithmSettingsCommand::execute(){
    cout<<"The current KNN parameters are: K=, distance metric = \n";
    string filePath;
    cin >> filePath;
    dio.write(filePath);
    cout<<"Upload complete.";
}