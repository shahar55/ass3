#pragma once
#include "Command.hpp"
#include "ServerDataManagement.hpp"
#include <vector>
#include <string.h>
#include <map>
using namespace std;

class ConfusionMatrixCommand : public Command {
    private:
        void fillConfusionMatrix(vector<vector<int>>&,map<string,int>,vector<string>,vector<string>);
        void clearMatrix(vector<vector<int>>& matrix,int dim);
        void matrixToPercentage(vector<vector<int>>& matrix);
        string confusionMatrixToString(vector<vector<int>>& matrix,vector<string> classes);
    public:
        ConfusionMatrixCommand(DefaultIO* dio,ServerDataManagement& manager);
        virtual void execute();
};