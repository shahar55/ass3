#pragma once
#include "Command.hpp"
#include "DefaultIO.hpp"
#include <string.h>
#include "ServerDataManagement.hpp"

class UploadCommand : public Command {
    void upload(std::string,std::string);
    public:
        UploadCommand(DefaultIO* dio,ServerDataManagement& manager);
        virtual void execute();
};