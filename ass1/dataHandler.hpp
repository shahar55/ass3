/* 
 * class dataHandler.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */
#pragma once
#include <string>
#include <vector>
#include "unclassifiedFlower.hpp"
#include "classifiedFlower.hpp"
class dataHandler {
    public:
        // constructor.
        dataHandler();
        // create a vector of flowers with type from vector of string data.
        std::vector<ClassifiedFlower> createClassedFlowersFromVector (std::vector<std::vector<std::string>>& data);
        // create a vector of flowers without type from vector of string data.
        std::vector<UnclassifiedFlower> createUnClassedFlowersFromVector (std::vector<std::vector<std::string>>& data);

};