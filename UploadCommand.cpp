#include "UploadCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
#include "ass1/CSVHandler.hpp"

using namespace std;

UploadCommand::UploadCommand(DefaultIO* dio):Command(dio){
    description="upload an unclassified csv data file";
}

void UploadCommand::execute(){
    dio->write("Please upload your local train CSV file.\n");
    string trainData = dio->read(); //getting the CSV data
    dio->write("Please upload your local test CSV file.\n");
    string testData = dio->read();
    upload(trainData,testData);
    dio->write("Upload complete.\n");
}

void UploadCommand::upload(string train, string test) {
    CSVHandler handler;
    handler.writeCSV("../resources/classified.csv",train);
    handler.writeCSV("../resources/test.csv",test);
    handler.testToUnclassified("../resources/test.csv");
}