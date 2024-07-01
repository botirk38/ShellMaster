
#pragma once

#include "Command.h"
#include <iostream>
#include <memory>
#include <string>
#include <sys/wait.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>

class CommandHandler {
public:
  CommandHandler();
  void handleCommand(const std::string &input);

private:
  std::unordered_map<std::string, std::unique_ptr<Command>> commands;
  Command *getCommand(const std::string &input);
  void executeExternalCommand(const std::vector<std::string> &args);
};
