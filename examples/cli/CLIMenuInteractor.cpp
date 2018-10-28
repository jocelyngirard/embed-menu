//
// Created by Jocelyn Girard on 26/10/2018.
//

#include <ncurses.h>

#include "CLIMenuInteractor.h"

CLIMenuInteractor::~CLIMenuInteractor() = default;

Input CLIMenuInteractor::waitInput() {
    switch (getch()) {
        case KEY_UP:
            return Up;
        case KEY_DOWN:
            return Down;
        case KEY_ENTER:
            return Select;
        default:
            return Other;
    }
}

