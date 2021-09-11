/* 
 * class knnGenerate.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */

#pragma once
#include "classifiedFlower.hpp"
#include "unclassifiedFlower.hpp"
#include <string.h>
#include <vector>

class KNNGenerate{
    private:
        int k;
        std::string distanceMetric;
    public:
        KNNGenerate(int k=5,std::string distanceMetric="EUC");
        // find the k (th) closest flowers to unNamed flower. 
        std::vector<ClassifiedFlower> kthClosest(UnclassifiedFlower& f,std::vector<ClassifiedFlower>& flowers);
        
        // fill the distances of the flowers in vector according to flower c.
        void fillDistances(std::vector<ClassifiedFlower>& v,UnclassifiedFlower& c);
        void changeK(int k);
        void changeDistanceMetric(std::string distanceMetric);
        std::string getParameters();
};