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

        void testToUnclassified(std::string testPath);
        std:: vector<std::string> findClassesWithoutDuplicates(char const* fileName);
        std:: vector<std::string> findClasses(char const* fileName);
};