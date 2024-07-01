#include "include/TypeCommand.h"
#include "include/Utils.h"

TypeCommand::TypeCommand(
    const std::unordered_map<std::string, std::unique_ptr<Command>> &cmds)
    : commands(cmds) {}

void TypeCommand::execute(const std::string &input) {
  std::string commandName = input.substr(TYPE_COMMAND_LEN);
  if (commands.find(commandName) != commands.end()) {
    std::cout << commandName << " is a shell builtin" << '\n';
    return;
  }

  // Check if it's an executable in PATH
  std::string executablePath = Utils::findExecutableInPath(commandName);
  if (!executablePath.empty()) {
    std::cout << commandName << " is " << executablePath << std::endl;
  } else {
    std::cout << commandName << ": not found" << std::endl;
  }
}
