#include "include/CommandHandler.h"
#include "include/EchoCommand.h"
#include "include/ExitCommand.h"
#include "include/TypeCommand.h"
#include "include/Utils.h"
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

CommandHandler::CommandHandler() {
  // Register commands
  commands["echo"] = std::make_unique<EchoCommand>();
  commands["exit"] = std::make_unique<ExitCommand>();
  commands["type"] = std::make_unique<TypeCommand>(commands);
}

void CommandHandler::handleCommand(const std::string &input) {
  auto args = Utils::splitInput(input);
  if (args.empty())
    return;

  auto command = getCommand(args[0]);
  if (command) {
    command->execute(input);
  } else {
    executeExternalCommand(args);
  }
}

Command *CommandHandler::getCommand(const std::string &input) {
  for (const auto &pair : commands) {
    if (input == pair.first) { // Exact match for the command
      return pair.second.get();
    }
  }
  return nullptr;
}

void CommandHandler::executeExternalCommand(
    const std::vector<std::string> &args) {
  pid_t pid = fork();
  if (pid == 0) {
    // Child process
    std::vector<char *> argv;
    for (const auto &arg : args) {
      argv.push_back(const_cast<char *>(arg.c_str()));
    }
    argv.push_back(nullptr);

    execvp(argv[0], argv.data());
    // If execvp returns, there was an error
    std::cerr << args[0] << ": command not found" << std::endl;
    exit(1);
  } else if (pid > 0) {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
  } else {
    // Fork failed
    std::cerr << "Failed to fork" << std::endl;
  }
}

