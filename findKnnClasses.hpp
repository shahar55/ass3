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
const std:: vector<std::string> findFlowerName(std :: vector<std:: string> data);
std:: vector<std::string> mergeTypes(char const* fileName);