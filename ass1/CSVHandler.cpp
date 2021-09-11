#include "CSVHandler.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
std::vector<std::vector<std::string>> CSVHandler::readCSV(char const* fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        perror("ERROR: File not Open");
        exit(0);
    } 
    std::vector<std::vector<std::string>> data;
    std::string line;
    while (getline(inputFile,line)) {
        std::vector<std::string> tmp;
        tmp = splitLine(line);
        data.push_back(tmp);
    }
    return data;
}

std::string CSVHandler::readCSVToString(char const* fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        perror("ERROR: File not Open");
        exit(0);
    }
    std::string out;
    std::string line;
    while (getline(inputFile,line)) {
        out+=line;
        out+="\n";
    }
    return out.substr(0,out.size()-1);
}

std::vector<std::string> CSVHandler::splitLine(std::string line){
    std::vector<std::string> cells;
	std::stringstream s(line);
    std::string word;
    while (getline(s,word,',')) {
        cells.push_back(word);
    }
    return cells;
}

void CSVHandler::writeCSV(std::string fileName, std::vector<std::string> stringFlowerData) {
    std::ofstream outputFile(fileName);
    for (std::string& s : stringFlowerData) {
        outputFile<<s;
        if (&s != &stringFlowerData.back())
            outputFile<<std::endl;
    }
}

void CSVHandler::writeCSV(std::string fileName, std::string s) {
    std::ofstream outputFile(fileName);
    outputFile<<s;
}

CSVHandler::CSVHandler() {
}

void CSVHandler::testToUnclassified(std::string testPath) {
    std::vector<std::vector<std::string>> testData = readCSV(testPath.c_str());
    for (std::vector<std::string>& row : testData) {
        row.pop_back();
    }
    std::string unclassified="";
    for (std::vector<std::string> row : testData) {
        for (std::string cell:row) {
            unclassified+=cell;
            unclassified+=",";
        }
        unclassified.pop_back();
        unclassified+="\n";
    }
    unclassified.pop_back();
    writeCSV("../resources/Unclassified.csv",unclassified);
}