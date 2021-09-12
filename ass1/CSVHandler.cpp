#include "CSVHandler.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <iterator>
#include <map>

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

const std:: vector<std::string> CSVHandler::findClassName(std :: vector<std::string> data) {
    std::vector<std::string> dataString; // vector of the flowers types (names).
    bool flag = false;
    for (int i = 0; i < data.size(); i++)
    {
        for ( int j = 0; j < dataString.size(); j++) // for loop that compare the corrent classflower name to each name in data string vector.
        {
            if (dataString[j].compare(data[i]) == 0 ) {
                flag = true;
            }
        }
        if (!flag) {
            dataString.push_back(data[i]);
        }
        flag = false;
    }
    return dataString;
    
    
}
std:: vector<std::string> CSVHandler::findClassesWithoutDuplicates(char const* fileName) {
    return findClassName(findClasses(fileName));
}

std:: vector<std::string> CSVHandler::findClasses(char const* fileName) {
    std::vector<std::vector<std::string>> data = readCSV(fileName);
    std::vector<std:: string> classFlowers;
    for (unsigned i=0; i<data.size(); ++i) {
       classFlowers.push_back(data[i][data[i].size() - 1]);
    }
    return classFlowers;
}
