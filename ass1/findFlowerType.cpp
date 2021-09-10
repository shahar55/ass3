#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include "findFlowerType.hpp"
#include <iterator>
#include <map>
using namespace std;
const string findFlowerName(std :: vector<ClassifiedFlower> data) {
    vector<string>  dataString; // vector of the flowers types (names).
    vector<int> arr; // vector of the num flowers call this name.
    bool flag = false;
    for (int i = 0; i < data.size(); i++)
    {
        for ( int j = 0; j < dataString.size(); j++) // for loop that compare the corrent classflower name to each name in data string vector.
        {
            if (dataString[j].compare(data[i].getName()) == 0 ) {
                arr[j] = arr[j] + 1;
                flag = true;
            }
        }
        if (!flag) {
            dataString.push_back(data[i].getName());
            arr.push_back(1);
        }
        flag = false;
    }
    int max = 0;
    int iMax = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] >= max) {
            max = arr[i];
            iMax = i;
        }
    }
    return dataString[iMax];
    
    
}