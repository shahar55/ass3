#include "downloadResCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/CSVHandler.hpp"
#include "ServerDataManagement.hpp"
#include <sstream>
#include <vector>
using namespace std;

DownloadResCommand::DownloadResCommand(DefaultIO* dio,ServerDataManagement& manager):Command(dio,manager){
    description="download results";
}

void DownloadResCommand::execute(){
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
    output.pop_back();
    dio->write(output);
    dio->write("Done.\n");
}