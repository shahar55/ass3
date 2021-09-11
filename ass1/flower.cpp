#include "flower.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
double Flower::getEuclideanDistance(const Flower& other) const{
    double Sum;
	double distance;
	for(int i=0;i<sizes.size();i++)
	{
		Sum = Sum + pow((sizes[i]-other.sizes[i]),2.0);
		distance = sqrt(Sum);
	}
	return distance;
}
double Flower::getMANDistance(const Flower& other) const{
    double Sum;
	double distance;
	for(int i=0;i<sizes.size();i++)
	{
		Sum = Sum + abs((sizes[i]-other.sizes[i]));
		distance = (Sum);
	}
	return distance;
}
double Flower::getCHEDistance(const Flower& other) const{
    double max;
    double maxCheck;
	double distance;
	for(int i=0;i<sizes.size();i++)
	{
        maxCheck = max;
		max = std::max(maxCheck, fabs(sizes[i] - other.sizes[i]));
		distance = max;
	}
	return distance;
}
Flower::Flower(std::vector<double> sizes):
sizes(sizes){}