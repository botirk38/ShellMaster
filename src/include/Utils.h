
#pragma once

#include <string>
#include <vector>

class Utils {
public:
  static std::vector<std::string> splitInput(const std::string &input);
  static bool isExecutable(const std::string &path);
  static std::string findExecutableInPath(const std::string &commandName);
};
