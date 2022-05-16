#include <string>
#include <vector>
/* 
 * class flower.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */
#pragma once
class Flower{
    protected:
        std::vector<double> sizes;
    
    public:
        // constructor.
        Flower(std::vector<double> sizes);
        // compute and returns the Euclidean Distance between this flower and other  one.
        double getEuclideanDistance(const Flower& other) const;
        double getMANDistance(const Flower& other) const;
        double getCHEDistance(const Flower& other) const;
};