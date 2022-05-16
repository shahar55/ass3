#include "ServerDataManagement.hpp"
#include "ass1/knnGenerate.hpp"

ServerDataManagement::ServerDataManagement():gen(){
    classified = "ERROR: files hasn't been uploaded to the server.\n";
    unClassified = "ERROR: files hasn't been uploaded to the server.\n";
    test = "ERROR: files hasn't been uploaded to the server.\n";
    output = "ERROR: the data hasn't been classified.\n";
}

void ServerDataManagement::setOutput(string output) {
    this->output=output;
}

string ServerDataManagement::getOutput() {
    return output;
}

void ServerDataManagement::setClassified(string classified) {
    this->classified=classified;
}

string ServerDataManagement::getClassified() {
    return classified;
}

void ServerDataManagement::setUnClassified(string unClassified) {
    this->unClassified=unClassified;
}

string ServerDataManagement::getUnClassified() {
    return unClassified;
}

void ServerDataManagement::setTest(string test) {
    this->test=test;
}
string ServerDataManagement::getTest() {
    return test;
}

void ServerDataManagement::changeK(int k) {
    gen.changeK(k);
}

void ServerDataManagement::changeDistanceMetric(string distanceMetric) {
    gen.changeDistanceMetric(distanceMetric);
}

KNNGenerate& ServerDataManagement::getKNN(){
    return gen;
}