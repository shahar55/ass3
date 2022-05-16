#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "dataHandler.hpp"

std::vector<ClassifiedFlower> dataHandler::createClassedFlowersFromVector (std::vector<std::vector<std::string>>& data) {
    std::vector<ClassifiedFlower> classFlowersData;
    std::vector<double> sizes;
    for (unsigned i=0; i<data.size(); ++i) {
        for (int  j = 0; j < data[i].size() - 1; j++)
        {
            sizes.push_back(std::stod(data[i][j]));
        }
        
        classFlowersData.push_back(ClassifiedFlower(sizes,
         const_cast<char*>(data[i][ data[i].size() - 1].c_str())));
        // create the classed flowers object from a given data vector.
        sizes.clear();
    }
    return classFlowersData;
}

std::vector<UnclassifiedFlower> dataHandler::createUnClassedFlowersFromVector (std::vector<std::vector<std::string>>& data) {
    std::vector<UnclassifiedFlower> unclassFlowersData;
    std::vector<double> sizes;
    for (unsigned i=0; i<data.size(); ++i) {
        for (int  j = 0; j < data[i].size(); j++)
        {
            sizes.push_back(std::stod(data[i][j]));
        }
        
        unclassFlowersData.push_back(UnclassifiedFlower(sizes));
        // create the unclassed flowers object from a given data vector.
        sizes.clear();
    }
    return unclassFlowersData;
}

dataHandler::dataHandler() {
}