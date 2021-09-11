#pragma once
#include <string>
/**
 * The Command interface declares a method for executing a command.
 */
class DefaultIO {
 public:
  virtual std::string read()=0;
  virtual std::string readData()=0;
  virtual void write(std:: string msg)=0;
};