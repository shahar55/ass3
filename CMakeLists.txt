cmake_minimum_required(VERSION 3.0.0)
project(run VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB ass1_SRC ass1/*.cpp)
add_executable(run main.cpp Command.cpp StandartIO.cpp UploadCommand.cpp AlgorithmSettingsCommand.cpp ${ass1_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
