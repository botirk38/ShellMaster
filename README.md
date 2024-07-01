# ShellMaster - A Custom Unix Shell

Welcome to **ShellMaster**, a custom Unix shell designed to mimic the behavior of common shell commands. This project implements several built-in commands (`cd`, `pwd`, `echo`, `exit`, `type`) and supports running external programs with arguments, leveraging environment variables like `PATH` for command resolution.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)
  - [Built-in Commands](#built-in-commands)
  - [External Commands](#external-commands)
- [Project Structure](#project-structure)
- [Building the Project](#building-the-project)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Built-in Commands**: `cd`, `pwd`, `echo`, `exit`, `type`
- **External Commands**: Execute any program available in the `PATH`
- **Directory Navigation**: Handle absolute and relative paths, including `~` for the home directory
- **Path Resolution**: Search for executables in the directories listed in the `PATH` environment variable

## Installation

To install and build **ShellMaster**, ensure you have a C++ compiler and `make` installed. Clone the repository and build the project using the provided `Makefile`.

```sh
git clone https://github.com/yourusername/shellmaster.git
make
```

## Usage

After building the project, you can start the shell by running the executable:

```sh
./bin/my_shell
```

## Commands

### Built-in Commands

#### `cd`
Changes the current working directory.

```sh
cd /path/to/directory
cd ~ # Changes to the home directory
```

#### `pwd`
Prints the current working directory.

```sh
pwd
```

#### `echo`
Prints the given arguments to the standard output.

```sh
echo Hello, World!
```

#### `exit`
Exits the shell.

```sh
exit
```

#### `type`
Displays how a command would be interpreted (as a built-in or external command).

```sh
type echo
type /usr/bin/ls
```

### External Commands

You can execute any external program available in your `PATH`.

```sh
ls -l
grep "pattern" file.txt
```

## Project Structure

```
shellmaster/
├── include/
│   ├── Command.h
│   ├── EchoCommand.h
│   ├── ExitCommand.h
│   ├── TypeCommand.h
│   ├── CommandHandler.h
│   ├── CdCommand.h
│   ├── PwdCommand.h
│   ├── Utils.h
├── src/
│   ├── main.cpp
│   ├── Command.cpp
│   ├── EchoCommand.cpp
│   ├── ExitCommand.cpp
│   ├── TypeCommand.cpp
│   ├── CommandHandler.cpp
│   ├── CdCommand.cpp
│   ├── PwdCommand.cpp
│   ├── Utils.cpp
└── Makefile
```

## Building the Project

To build the project, simply run:

```sh
make
```

This will compile the source files and create the executable `shell_master` in the `bin` directory.

To clean up the build artifacts, run:

```sh
make clean
```

## Contributing

Contributions are welcome! Please fork the repository, create a new branch for your feature or bug fix, and submit a pull request. Make sure to follow the coding style and include tests for new functionality.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

Enjoy using **ShellMaster**! If you encounter any issues or have suggestions for improvement, feel free to open an issue on GitHub.
