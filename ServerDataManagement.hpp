#pragma once
#include "ass1/knnGenerate.hpp"
#include <string.h>
using namespace std;

class ServerDataManagement
{
    private:
        KNNGenerate gen;
        string classified;
        string unClassified;
        string test;
        string output;
    
    public:
        ServerDataManagement();
        KNNGenerate& getKNN();
        void setOutput(string ouput);
        string getOutput();
        void setClassified(string classified);
        string getClassified();
        void setUnClassified(string unClassified);
        string getUnClassified();
        void setTest(string test);
        string getTest();
        void changeK(int k);
        void changeDistanceMetric(string distanceMetric);

};