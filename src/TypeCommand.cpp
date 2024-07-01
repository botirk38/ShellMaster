#include "include/TypeCommand.h"

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
  std::string executablePath = findExecutableInPath(commandName);
  if (!executablePath.empty()) {
    std::cout << commandName << " is " << executablePath << std::endl;
  } else {
    std::cout << commandName << ": not found" << std::endl;
  }
}

bool TypeCommand::isExecutable(const std::string &path) {
  struct stat sb;
  return (stat(path.c_str(), &sb) == 0 && sb.st_mode & S_IXUSR);
}

std::string TypeCommand::findExecutableInPath(const std::string &commandName) {
  const char *pathEnv = std::getenv("PATH");
  if (!pathEnv) {
    return "";
  }

  std::string pathStr(pathEnv);
  std::stringstream ss(pathStr);
  std::string dir;
  while (std::getline(ss, dir, ':')) {
    std::string fullPath = dir + "/" + commandName;
    if (isExecutable(fullPath)) {
      return fullPath;
    }
  }
  return "";
}
