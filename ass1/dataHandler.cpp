#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "dataHandler.hpp"

std::vector<ClassifiedFlower> dataHandler::createClassedFlowersFromVector (std::vector<std::vector<std::string>>& data) {
    std::vector<ClassifiedFlower> classFlowersData;
    for (unsigned i=0; i<data.size(); ++i) {
        classFlowersData.push_back(ClassifiedFlower(std::stod(data[i][0]), std::stod(data[i][1]), std::stod(data[i][2]), std::stod(data[i][3]), const_cast<char*>(data[i][4].c_str())))
        ; // create the classed flowers object from a given data vector.
    }
    return classFlowersData;
}

std::vector<UnclassifiedFlower> dataHandler::createUnClassedFlowersFromVector (std::vector<std::vector<std::string>>& data) {
    std::vector<UnclassifiedFlower> unclassFlowersData;
    for (unsigned i=0; i<data.size(); ++i) {
        unclassFlowersData.push_back(UnclassifiedFlower(std::stod(data[i][0]), std::stod(data[i][1]), std::stod(data[i][2]), std::stod(data[i][3])))
        ; // create the un classed flowers (without name) object from a given data vector.
    }
    return unclassFlowersData;
}

dataHandler::dataHandler() {
}