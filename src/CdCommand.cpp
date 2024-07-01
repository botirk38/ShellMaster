#include "include/CdCommand.h"
#include <iostream>
#include <filesystem>

void CdCommand::execute(const std::string &input) {
    std::string path = input.substr(3); // Assuming input starts with "cd "
    if (path.empty()) {
        std::cerr << "cd: missing argument" << std::endl;
        return;
    }
    std::error_code ec;
    std::filesystem::current_path(path, ec);
    if (ec) {
        std::cerr << "cd: " << path << ": " << ec.message() << std::endl;
    }
}

