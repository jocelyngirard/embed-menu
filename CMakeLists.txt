cmake_minimum_required(VERSION 3.12)
project(menu)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(
        menu

        src/menu/Menu.cpp
        src/menu/MenuItem.h
        src/menu/io/MenuOutput.h
        src/menu/io/MenuInteractor.h

        examples/cli/main.cpp
        examples/cli/CLIMenuInteractor.cpp
        examples/cli/CLIMenuOutput.cpp
)