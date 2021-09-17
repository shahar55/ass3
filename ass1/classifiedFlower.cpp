#include "classifiedFlower.hpp"
#include <string>
ClassifiedFlower::ClassifiedFlower(std::vector<double> sizes, char const* type)
:Flower(sizes){
    name = type;
}
std::string ClassifiedFlower::getName() const{
    return name;
}

void ClassifiedFlower::setDistance(UnclassifiedFlower& unNamedFlower,std::string distanceMetric) {
    if (distanceMetric=="EUC") {
        distance = unNamedFlower.getEuclideanDistance(*this);
    }
    else if (distanceMetric=="MAN") {
        distance = unNamedFlower.getMANDistance(*this);
    }
    else if (distanceMetric=="CHE") {
        distance = unNamedFlower.getCHEDistance(*this);
    }
}

bool ClassifiedFlower::operator> (const ClassifiedFlower& namedFlower) const {
    return distance > namedFlower.distance;
}

double ClassifiedFlower::getDistance(){
    return distance;
} 
