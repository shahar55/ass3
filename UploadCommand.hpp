#pragma once
#include "Command.hpp"
#include "DefaultIO.hpp"
#include <string.h>

class UploadCommand : public Command {
    void upload(std::string,std::string);
    public:
        UploadCommand(DefaultIO* dio);
        virtual void execute();
};