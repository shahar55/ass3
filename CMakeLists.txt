cmake_minimum_required(VERSION 3.0.0)
project(run VERSION 0.1.0)

include(CTest)
enable_testing()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

file(GLOB ass1_SRC ass1/*.cpp)
add_executable(runClient client.cpp ${ass1_SRC})
            
add_executable(runServer tcpServer.cpp Command.cpp ClassifyCommand.cpp StandartIO.cpp UploadCommand.cpp confusionMatrixCommand.cpp
                AlgorithmSettingsCommand.cpp displayResCommand.cpp downloadResCommand.cpp exitCommand.cpp CLI.cpp
                SocketIO.cpp ServerDataManagement.cpp ${ass1_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
