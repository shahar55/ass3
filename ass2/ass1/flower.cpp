#include "flower.hpp"
#include <cmath>
double Flower::getEuclideanDistance(const Flower& other) const{
    double cupLeafLengthPow = pow(cupLeafLength-other.cupLeafLength,2);
    double cupLeafWidthPow = pow(cupLeafWidth-other.cupLeafWidth,2);
    double petalLengthPow = pow(petalLength-other.petalLength,2);
    double petalWidthPow = pow(petalWidth-other.petalWidth,2);
    return sqrt(cupLeafWidthPow+cupLeafLengthPow+petalWidthPow+petalLengthPow);
}

Flower::Flower(double cupLeafWidth,double cupLeafLength,double petalWidth,double petalLength):
cupLeafLength(cupLeafLength),cupLeafWidth(cupLeafWidth),petalLength(petalLength),petalWidth(petalWidth){}