/* 
 * class flower.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */
#pragma once
class Flower{
    protected:
        double cupLeafWidth;
        double cupLeafLength;
        double petalWidth;
        double petalLength;
    
    public:
        // constructor.
        Flower(double cupLeafWidth,double cupLeafLength,double petalWidth,double petalLength);
        // compute and returns the Euclidean Distance between this flower and other  one.
        double getEuclideanDistance(const Flower& other) const;
};