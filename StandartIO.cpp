#include "StandartIO.hpp"
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
std::string DefaultIO :: read(){
    std::string str;
    std::getline(std::cin, str);
    return str;
}
void DefaultIO :: write(std :: string msg){
   std::cout << msg << endl;;
}
