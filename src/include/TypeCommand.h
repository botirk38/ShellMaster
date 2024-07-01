#pragma once

#include "Command.h"
#include <unordered_map>
#include <memory>
#include <string>
#include <iostream>

#define TYPE_COMMAND_LEN 5

class TypeCommand : public Command {
public:
    TypeCommand(const std::unordered_map<std::string, std::unique_ptr<Command>>& cmds);
    void execute(const std::string &input) override;

private:
    const std::unordered_map<std::string, std::unique_ptr<Command>>& commands;
};


