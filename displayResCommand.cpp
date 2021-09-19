#include "displayResCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/CSVHandler.hpp"
#include <sstream>
#include <vector>
using namespace std;

DisplayResCommand::DisplayResCommand(DefaultIO* dio):Command(dio){
    description="display results";
}

void DisplayResCommand::execute(){
    CSVHandler handler;
    string results = handler.readCSVToString("../resources/output.csv");
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