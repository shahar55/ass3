#include "downloadResCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/CSVHandler.hpp"
#include <sstream>
#include <vector>
using namespace std;

DownloadResCommand::DownloadResCommand(DefaultIO* dio):Command(dio){
    description="download results";
}

void DownloadResCommand::execute(){
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
    output.pop_back();
    handler.writeCSV("../resources/results.txt",output);
    dio->write("Done.");
}