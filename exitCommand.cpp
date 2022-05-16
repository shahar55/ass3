#include "exitCommand.hpp"
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

ExitCommand::ExitCommand(DefaultIO* dio,ServerDataManagement& manager):Command(dio,manager){
    description="exit";
}

void ExitCommand::execute(){
    dio->closeConnection();
}