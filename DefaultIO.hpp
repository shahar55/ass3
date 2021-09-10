#pragma once
#include <string>
/**
 * The Command interface declares a method for executing a command.
 */
class DefaultIO {
 public:
  virtual ~DefaultIO() {
  }
  virtual std::string read();
  virtual void write(std:: string);
};