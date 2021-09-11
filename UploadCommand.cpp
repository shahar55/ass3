#include "UploadCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/CSVHandler.hpp"

using namespace std;

UploadCommand::UploadCommand(DefaultIO* dio):Command(dio){
    description="upload an unclassified csv data file";
}

void UploadCommand::execute(){
    dio->write("Please upload your local train CSV file.");
    string trainData = dio->readData(); //getting the CSV data
    dio->write("Please upload your local test CSV file.");
    string testData = dio->readData();
    upload(trainData,testData);
    dio->write("Upload complete.");
}

void UploadCommand::upload(string train, string test) {
    CSVHandler handler;
    handler.writeCSV("../resources/classified.csv",train);
    handler.writeCSV("../resources/test.csv",test);
    handler.testToUnclassified("../resources/test.csv");
}