/* 
 *  findFlowerType.hpp
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */

#pragma once
#include "classifiedFlower.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include "unclassifiedFlower.hpp"

// Receives a vector of flowers,
// and returns a string according to the name of the flower that appears most in the vector
const std::string findFlowerName(std :: vector<ClassifiedFlower> data);
