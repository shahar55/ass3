#pragma once
#include "Command.hpp"

class UploadCommand : public Command {
    public:
        UploadCommand();
        virtual void execute();
};