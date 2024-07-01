#pragma once

#include "Command.h"
#include <string>

class CdCommand : public Command {

  public:
    void execute(const std::string& input) override;

};
