#include "UploadCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
using namespace std;

UploadCommand::UploadCommand(){
    description="upload an unclassified csv data file";
    dio = StandartIO();
}

void UploadCommand::execute(){
    dio.write("Please upload your local train CSV file.");
    string filePath = dio.read();
    dio.write(filePath);
    dio.write("Upload complete.");
}