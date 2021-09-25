#include "confusionMatrixCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/knnGenerate.hpp"
#include "ass1/CSVHandler.hpp"
#include "ass1/dataHandler.hpp"
#include "ass1/findFlowerType.hpp"
#include "ServerDataManagement.hpp"
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

ConfusionMatrixCommand::ConfusionMatrixCommand(DefaultIO* dio,ServerDataManagement& manager):Command(dio,manager){
    description="display algorithm confusion matrix";
}

void ConfusionMatrixCommand::execute(){
    if (manager.getOutput().compare("ERROR: the data hasn't been classified.\n") == 0) {
        dio->write(manager.getOutput());
        return;
    }
    CSVHandler handler;
    vector<string> classes = handler.findClassesWithoutDuplicates(manager.getTest());
    map<string,int> classesMap;
    int i=0;
    for (string classType:classes) {
        classesMap.insert(pair<string,int>(classType,i));
        i++;
    }
    vector<string> trueClasses = handler.findClasses(manager.getTest());
    vector<string> predictedClasses = handler.findClasses(manager.getOutput());
    vector<vector<int>> matrix;
    clearMatrix(matrix,classes.size());
    fillConfusionMatrix(matrix,classesMap,trueClasses,predictedClasses);
    matrixToPercentage(matrix);
    dio->write(confusionMatrixToString(matrix,classes));
}

void ConfusionMatrixCommand::fillConfusionMatrix(vector<vector<int>>& mat,map<string,int> mapClass,vector<string> trueClasses,vector<string> predictedClasses) {
    for (int i=0;i<trueClasses.size();i++) {
        int row = mapClass[trueClasses[i]];
        int col = mapClass[predictedClasses[i]];
        mat[row][col]++;
    }
}

void ConfusionMatrixCommand::clearMatrix(vector<vector<int>>& matrix,int dim) {
    for (int i=0;i<dim;i++) {
        vector<int> row;
        for (int j=0;j<dim;j++)
            row.push_back(0);
        matrix.push_back(row);
    }
}

void ConfusionMatrixCommand::matrixToPercentage(vector<vector<int>>& matrix) {
    for (vector<int>& row:matrix) {
        int sum=0;
        for (int cell:row)
            sum+=cell;
        int i=0;
        for (int cell:row) {
            row[i]=round(float(cell)/sum*100);
            i++;
        }
    }
}

string ConfusionMatrixCommand::confusionMatrixToString(vector<vector<int>>& matrix,vector<string> classes) {
    string mat="";
    for (int i=0;i<classes.size();i++) {
        mat+=classes[i];
        mat+="\t\t";
        for (int j=0;j<classes.size();j++) {
            mat+="\t";
            mat+=to_string(matrix[i][j]);
            mat+="%";
        }
        mat+="\n";
    }
    mat+=("The current KNN parameters are: "+manager.getKNN().getClassParameters()+"\n");
    return mat;
}