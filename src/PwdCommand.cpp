#include "include/PwdCommand.h"

void PwdCommand::execute(const std::string &input) {

  std::string curr_working_dir = std::filesystem::current_path();

  std::cout << curr_working_dir << '\n';
}
