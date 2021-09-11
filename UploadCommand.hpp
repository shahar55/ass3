#pragma once
#include "Command.hpp"
#include <string.h>

class UploadCommand : public Command {
    void upload(std::string,std::string);
    public:
        UploadCommand();
        virtual void execute();
};