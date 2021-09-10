cmake_minimum_required(VERSION 3.0.0)
project(testing VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(testing main.cpp flower.cpp classifiedFlower.cpp unclassifiedFlower.cpp knnGenerate.cpp
findFlowerType.cpp CSVHandler.cpp dataHandler.cpp) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
