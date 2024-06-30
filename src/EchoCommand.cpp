#include "include/EchoCommand.h"
#include <iostream>

#define ECHO_LEN 5

void EchoCommand::execute(const std::string &input) {
  std::cout << input.substr(ECHO_LEN)
            << std::endl; // Assuming input starts with "echo "
}
