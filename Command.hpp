#pragma once
#include <string>
#include "DefaultIO.hpp"
/**
 * The Command interface declares a method for executing a command.
 */
class Command {
 protected:
    std::string description;
    DefaultIO* dio;
 public:
   Command(DefaultIO* dio);
   virtual ~Command() = default;
   virtual void execute()=0;
   std::string getDescription();
};