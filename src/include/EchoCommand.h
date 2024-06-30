#pragma once

#include "Command.h"
class EchoCommand : public Command {

public:
  void execute(const std::string &input) override;
};
