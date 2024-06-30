
#pragma once

#include "Command.h"
#include <memory>
#include <string>
#include <unordered_map>

class CommandHandler {
public:
  CommandHandler();
  void handleCommand(const std::string &input);

private:
  std::unordered_map<std::string, std::unique_ptr<Command>> commands;
  Command *getCommand(const std::string &input);
};
