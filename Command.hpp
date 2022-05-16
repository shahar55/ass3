#pragma once
#include <string>
#include "DefaultIO.hpp"
#include "ServerDataManagement.hpp"

/**
 * The Command interface declares a method for executing a command.
 */
class Command {
 protected:
    std::string description;
    DefaultIO* dio;
    ServerDataManagement& manager;
 public:
   Command(DefaultIO* dio,ServerDataManagement& manager);
   virtual ~Command() = default;
   virtual void execute()=0;
   std::string getDescription();
};