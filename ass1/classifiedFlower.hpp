/* 
 * class ClassifiedFlower.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */
#pragma once
#include <string>
#include "flower.hpp"
#include "unclassifiedFlower.hpp"
class ClassifiedFlower:public Flower{
    std::string name;
    double distance;
    public:
    
        // constructor.
        ClassifiedFlower(std::vector<double> sizes, char const* type);
        
        // get name
        std::string getName() const;
        
        // set distance between this flower and unamed flower.
        void setDistance(UnclassifiedFlower& unNamedFlower);
        // operator ">".
        bool operator> (const ClassifiedFlower& namedFlower) const;
        // get distance.
        double getDistance();
};