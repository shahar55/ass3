#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "findKnnClasses.hpp"
#include <iterator>
#include <map>
#include "ass1/CSVHandler.hpp"
using namespace std;
const std:: vector<std::string> findFlowerName(std :: vector<std::string> data) {
    vector<string>  dataString; // vector of the flowers types (names).
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
std:: vector<std::string> mergeTypes(char const* fileName) {
    CSVHandler handler;
    std::vector<std::vector<std::string>> data = handler.readCSV(fileName);
    std::vector<std:: string> classFlowers;
    for (unsigned i=0; i<data.size(); ++i) {
       classFlowers.push_back(data[i][data[i].size() - 1]);
    }
    return  findFlowerName(classFlowers);
}