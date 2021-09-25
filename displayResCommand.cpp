#include "displayResCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/CSVHandler.hpp"
#include "ServerDataManagement.hpp"
#include <sstream>
#include <vector>
using namespace std;

DisplayResCommand::DisplayResCommand(DefaultIO* dio,ServerDataManagement& manager):Command(dio,manager){
    description="display results";
}

void DisplayResCommand::execute(){
    CSVHandler handler;
    if (manager.getOutput().compare("ERROR: the data hasn't been classified.\n") == 0) {
        dio->write(manager.getOutput());
        return;
    }
    string results = manager.getOutput();
    istringstream split(results);
    string arg;
    int i=1;
    string output;
    while (getline(split,arg)) {
        output+=to_string(i)+"  "+arg+"\n";
        i++;
    }
    dio->write(output);
    dio->write("Done.\n");
}