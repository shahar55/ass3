/* 
 * class CSVHandler.
 *
 *  Created on: 9/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */

#pragma once
#include <string>
#include <vector>
class CSVHandler {
    private:
        std::string fileName;

        // private: spilt line according to "," char.
        std::vector<std::string> splitLine(std::string line);
        const std:: vector<std::string> findClassName(std :: vector<std:: string> data);
    public:

        // constructor.
        CSVHandler();

        // read a CSV file and return string vector.
        std::vector<std::vector<std::string>> readCSV(char const* fileName);

        // read a CSV file and return string.
        std::string readCSVToString(char const* fileName);

        // write types of flowers to CSV file.
        void writeCSV(std::string , std::vector<std::string> stringFlowerData);

        // write string to csv
        void writeCSV(std::string, std::string);

        std::string testToUnclassified(std::string test);
        std::vector<std::string> findClassesWithoutDuplicates(std::string file);
        std::vector<std::string> findClasses(std::string file);
        std::vector<std::vector<std::string>> fromStringToVector(std::string input);
        std::string fromVectorToString(std::vector<std::string> input);
};