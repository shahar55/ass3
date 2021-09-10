/* 
 * class knnGenerate.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */

#pragma once
#include "classifiedFlower.hpp"
#include "unclassifiedFlower.hpp"
#include <vector>

class KNNGenerate{
    public:

        // find the k (th) closest flowers to unNamed flower. 
        std::vector<ClassifiedFlower> kthClosest(UnclassifiedFlower& f,std::vector<ClassifiedFlower>& flowers,int k);
        
        // fill the distances of the flowers in vector according to flower c.
        void fillDistances(std::vector<ClassifiedFlower>& v,UnclassifiedFlower& c);
};