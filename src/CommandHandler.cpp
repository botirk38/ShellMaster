#include "include/CommandHandler.h"
#include "include/EchoCommand.h"
#include "include/ExitCommand.h"

#include <iostream>

CommandHandler::CommandHandler() {
  // Register commands
  commands["echo"] = std::make_unique<EchoCommand>();
  commands["exit"] = std::make_unique<ExitCommand>();
}

void CommandHandler::handleCommand(const std::string &input) {
  auto command = getCommand(input);
  if (command) {
    command->execute(input);
  } else {
    std::cout << input << ": command not found\n";
  }
}

Command *CommandHandler::getCommand(const std::string &input) {
  for (const auto &pair : commands) {
    if (input.rfind(pair.first, 0) == 0) { // Command found at the start
      return pair.second.get();
    }
  }
  return nullptr;
}
