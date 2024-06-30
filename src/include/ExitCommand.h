
#pragma once

#include "Command.h"

class ExitCommand : public Command {

public:
  void execute(const std::string &input) override;
};
