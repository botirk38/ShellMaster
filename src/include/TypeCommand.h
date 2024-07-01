#pragma once

#include "Command.h"
#include <unordered_map>
#include <memory>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <sys/stat.h>
#include <unistd.h>

#define TYPE_COMMAND_LEN 5

class TypeCommand : public Command {
public:
    TypeCommand(const std::unordered_map<std::string, std::unique_ptr<Command>>& cmds);
    void execute(const std::string &input) override;

private:
    const std::unordered_map<std::string, std::unique_ptr<Command>>& commands;
    bool isExecutable(const std::string& path);
    std::string findExecutableInPath(const std::string& commandName);

};


