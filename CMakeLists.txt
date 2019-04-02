cmake_minimum_required(VERSION 3.12)
project(menu)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(
        menu
        lib/LinkedList.h
        io/MenuOutput.h
        io/MenuInteractor.h
        Menu.cpp
        examples/cli/main.cpp
        examples/cli/CLIMenuInteractor.cpp
        examples/cli/CLIMenuOutput.cpp
        MenuRoot.cpp MenuRoot.h MenuBack.cpp MenuBack.h)