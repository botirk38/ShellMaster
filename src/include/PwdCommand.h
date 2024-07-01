#pragma once

#include "Command.h"
#include <filesystem>
#include <iostream>
#include <string>

class PwdCommand : public Command {
public:
  void execute(const std::string &input) override;
};
