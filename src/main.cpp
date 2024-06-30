#include "include/CommandHandler.h"
#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  CommandHandler handler;

  while (true) {
    std::cout << "$ ";

    std::string input;
    std::getline(std::cin, input);

    handler.handleCommand(input);
  }
}

