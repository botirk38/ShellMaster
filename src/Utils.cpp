#include "include/Utils.h"
#include <cstdlib>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>

std::vector<std::string> Utils::splitInput(const std::string &input) {
  std::vector<std::string> tokens;
  std::istringstream iss(input);
  std::string token;
  while (iss >> token) {
    tokens.push_back(token);
  }
  return tokens;
}

bool Utils::isExecutable(const std::string &path) {
  struct stat sb;
  return (stat(path.c_str(), &sb) == 0 && sb.st_mode & S_IXUSR);
}

std::string Utils::findExecutableInPath(const std::string &commandName) {
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
