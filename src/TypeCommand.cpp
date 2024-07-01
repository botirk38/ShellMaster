#include "include/TypeCommand.h"

TypeCommand::TypeCommand(
    const std::unordered_map<std::string, std::unique_ptr<Command>> &cmds)
    : commands(cmds) {}

void TypeCommand::execute(const std::string &input) {
  std::string commandName = input.substr(TYPE_COMMAND_LEN);
  if (commands.find(commandName) != commands.end()) {
    std::cout << commandName << " is a shell builtin" << '\n';
  } else {
    std::cout << commandName << ": not found" << '\n';
  }
}
