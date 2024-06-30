#include "include/ExitCommand.h"
#include <cstdlib>

void ExitCommand::execute(const std::string &input) {
  exit(0); // Exit the program
}
