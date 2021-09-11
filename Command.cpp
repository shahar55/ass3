#include "Command.hpp"
#include <string.h>

std::string Command::getDescription() {
    return description;
}

Command::Command(DefaultIO* dio):dio(dio){}