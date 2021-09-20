#include "Command.hpp"
#include "ServerDataManagement.hpp"
#include <string.h>

std::string Command::getDescription() {
    return description;
}

Command::Command(DefaultIO* dio,ServerDataManagement& manager):dio(dio),manager(manager){}