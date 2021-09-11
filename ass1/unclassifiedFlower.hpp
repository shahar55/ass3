/* 
 * class UnclassifiedFlower.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */

#pragma once
#include <string>
#include <iostream>
#include "flower.hpp"
class UnclassifiedFlower:public Flower{
   
   /*
    * constructor.
    */
    public:
        UnclassifiedFlower(std:: vector<double> sizes); // constructor
};