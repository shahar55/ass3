#include "ClassifyCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/knnGenerate.hpp"
#include "ass1/CSVHandler.hpp"
#include "ass1/dataHandler.hpp"
#include "ass1/findFlowerType.hpp"
#include "ServerDataManagement.hpp"
#include <sstream>
#include <vector>
using namespace std;

ClassifyCommand::ClassifyCommand(DefaultIO* dio,ServerDataManagement& manager):Command(dio,manager){
    description="classify data";
}

void ClassifyCommand::execute(){
    if (manager.getClassified().compare("ERROR: files hasn't been uploaded to the server.\n") == 0) {
        dio->write(manager.getClassified());
        return;
    }
    else {
        classify();
        manager.getKNN().saveCurrParams();
        dio->write("classifying data complete.\n");
    }
}

void ClassifyCommand::classify(){
    CSVHandler c;
    dataHandler d;
    string classified = manager.getClassified();
    string unclassified = manager.getUnClassified();
    std::vector<std::vector<std::string>> s1 = c.fromStringToVector(classified); // turn csv file into string or.
    std::vector<std::vector<std::string>> s2 = c.fromStringToVector(unclassified); // turn csv file into stringvect vector.
    std::vector<ClassifiedFlower> c1 =  d.createClassedFlowersFromVector (s1); // create classified flowers from the string.
    std::vector<UnclassifiedFlower> c2 =  d.createUnClassedFlowersFromVector (s2); // create unclassified flowers from the string.
    std::vector<std::string> types; // the returned value vector, that is the types of the unFlowers.
    /**
     * for loop that find for each unFlower his type according to knn algorithem.
     * **/
    for (UnclassifiedFlower u:c2) {
        std::vector<ClassifiedFlower> l = manager.getKNN().kthClosest(u,c1);
        std::string type = findFlowerName(l);
        types.push_back(type);
    }
    manager.setOutput(c.fromVectorToString(types));
}