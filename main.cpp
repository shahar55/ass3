#include <iostream>
#include "ass1/knnGenerate.hpp"
#include "Command.hpp"
#include "AlgorithmSettingsCommand.hpp"

int main() {
    KNNGenerate k;
    AlgorithmSettingsCommand a(k);
    a.execute();
    a.execute();
    a.execute();
    a.execute();

}