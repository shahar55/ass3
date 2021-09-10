#include "knnGenerate.hpp"
#include "classifiedFlower.hpp"
#include "unclassifiedFlower.hpp"
#include <queue>

void KNNGenerate::fillDistances(std::vector<ClassifiedFlower>& v,UnclassifiedFlower& c) {
    for (ClassifiedFlower& cf:v) {
        cf.setDistance(c);
    }
}

std::vector<ClassifiedFlower> KNNGenerate::kthClosest(UnclassifiedFlower& f,std::vector<ClassifiedFlower>& v,int k) {
    fillDistances(v,f);
    std::priority_queue<ClassifiedFlower, std::vector<ClassifiedFlower>,std::greater<ClassifiedFlower>> pq(v.begin(), v.end());
    std::vector<ClassifiedFlower> kth;
    // do for remaining array elements
    while (--k+1) {
        kth.push_back(pq.top());
        pq.pop();
    }
    return kth;
}