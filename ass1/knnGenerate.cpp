#include "knnGenerate.hpp"
#include "classifiedFlower.hpp"
#include "unclassifiedFlower.hpp"
#include <string.h>
#include <queue>

void KNNGenerate::fillDistances(std::vector<ClassifiedFlower>& v,UnclassifiedFlower& c) {
    for (ClassifiedFlower& cf:v) {
        cf.setDistance(c,distanceMetric);
    }
}

std::vector<ClassifiedFlower> KNNGenerate::kthClosest(UnclassifiedFlower& f,std::vector<ClassifiedFlower>& v) {
    fillDistances(v,f);
    std::priority_queue<ClassifiedFlower, std::vector<ClassifiedFlower>,std::greater<ClassifiedFlower>> pq(v.begin(), v.end());
    std::vector<ClassifiedFlower> kth;
    // do for remaining array elements
    int tmpK=k;
    while (--tmpK+1) {
        kth.push_back(pq.top());
        pq.pop();
    }
    return kth;
}

KNNGenerate::KNNGenerate(int k,std::string distanceMetric):k(k),distanceMetric(distanceMetric) {
}

void KNNGenerate::changeK(int k) {
    this->k=k;
}

void KNNGenerate::changeDistanceMetric(std::string distanceMetric) {
    this->distanceMetric=distanceMetric;
}

std::string KNNGenerate::getParameters() {
    return "K = "+std::to_string(k)+", distance metric = "+distanceMetric;
}

void KNNGenerate::saveCurrParams(){
    classK = k;
    classDistanceMetric = distanceMetric;
}

std::string KNNGenerate::getClassParameters() {
    return "K = "+std::to_string(classK)+", distance metric = "+classDistanceMetric;
}