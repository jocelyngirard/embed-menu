cmake_minimum_required(VERSION 3.12)
project(menu)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(
        menu
        src/main.cpp
        src/menu/Menu.cpp
        src/menu/io/MenuOutput.h
        src/menu/io/MenuInteractor.h
        src/mock/CLIMenuInteractor.cpp
        src/mock/CLIMenuOutput.cpp
        src/menu/MenuItem.h)