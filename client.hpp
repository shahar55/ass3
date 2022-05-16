/* 
 * class Client.
 *
 *  Created on: 21/08/2021
 *      Authors: shahar abitbol, ido barkai.
 */
#pragma once
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <vector>

class Client 
{
    int sock;
    const char* ip_address; // client ip
    const int port_no; //  tcp server port.
    struct sockaddr_in sin;
    /**
     * // Protocol for transferring the information between
     *  a client and the server that it was decided to use
     * (tcp or udp).
     * return: string 
     * */
    std::string protocol;
    void initializeSin();
    void uploadCommand();
    void algorithmSettingsCommand();
    void classifyCommand();
    void displayResultsCommand();
    void downloadResultsCommand();
    void confMatrixCommand();
    public:
        Client(const char*,const int); // constructor.
        void sendData(const char*);
        std::string getData();
        
        /**
         * A function that reads from the system and send vector to "handleCommand" func.
         * */

        void operateCommand(const char*);
        void handleCommand(std::vector<std::string>); // Determines the migration protocol, read and write to csv files.
        void handleConnction();
        void choosePath();
        void closeConnection();
};