#include "classifiedFlower.hpp"
#include <string>
ClassifiedFlower::ClassifiedFlower(double cupLeafWidth,double cupLeafLength,double petalWidth,double petalLength, char const* type)
:Flower(cupLeafWidth, cupLeafLength, petalWidth, petalLength){
    name = type;
}
std::string ClassifiedFlower::getName() const{
    return name;
}

void ClassifiedFlower::setDistance(UnclassifiedFlower& unNamedFlower) {
    distance = unNamedFlower.getEuclideanDistance(*this);
}

bool ClassifiedFlower::operator> (const ClassifiedFlower& namedFlower) const {
    return distance > namedFlower.distance;
}

double ClassifiedFlower::getDistance(){
    return distance;
} 
