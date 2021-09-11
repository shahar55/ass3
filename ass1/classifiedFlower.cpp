#include "classifiedFlower.hpp"
#include <string>
ClassifiedFlower::ClassifiedFlower(std::vector<double> sizes, char const* type)
:Flower(sizes){
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
