#include "UploadCommand.hpp"
#include "StandartIO.hpp"
#include <string.h>
using namespace std;

UploadCommand::UploadCommand(){
    description="upload an unclassified csv data file";
    dio = StandartIO();
}

void UploadCommand::execute(){
    cout<<"Please upload your local train CSV file.\n";
    string filePath;
    cin >> filePath;
    dio.write(filePath);
    cout<<"Upload complete.";
}