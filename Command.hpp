#pragma once
#include <string>
#include "DefaultIO.hpp"
/**
 * The Command interface declares a method for executing a command.
 */
class Command {
 protected:
    std::string description;
    DefaultIO dio;
 public:
  //virtual ~Command();
  virtual void execute()=0;
};