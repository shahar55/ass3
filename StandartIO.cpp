#include "StandartIO.hpp"
#include <string>
#include <stdio.h>
#include <iostream>
#include "ass1/CSVHandler.hpp"
using namespace std;
StandartIO::StandartIO(){}
std::string StandartIO :: read(){
    std::string str;
    std::getline(std::cin, str);
    return str;
}
void StandartIO :: write(std :: string msg){
   std::cout << msg << endl;;
}

std::string StandartIO::readData() {
    string filePath;
    getline(cin,filePath);
    CSVHandler handler;
    return handler.readCSVToString(filePath.c_str());
}

void StandartIO::closeConnection(){
    exit(1);
}