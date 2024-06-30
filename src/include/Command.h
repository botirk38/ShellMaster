#pragma once

#include <string>

class Command {

public:
  virtual void execute(const std::string &input) = 0;
  virtual ~Command() {}
};
