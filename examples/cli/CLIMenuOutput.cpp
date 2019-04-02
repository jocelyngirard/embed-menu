//
// Created by Jocelyn Girard on 26/10/2018.
//

#include <curses.h>
#include "CLIMenuOutput.h"

CLIMenuOutput::CLIMenuOutput() {
    initscr();
    keypad(stdscr, TRUE);
}

CLIMenuOutput::~CLIMenuOutput() = default;

int CLIMenuOutput::getRows() const { return 4; }

int CLIMenuOutput::getColumns() const { return 21; }

void CLIMenuOutput::drawRect(int y1, int x1, int y2, int x2) {
    mvhline(y1, x1, 0, x2 - x1);
    mvhline(y2, x1, 0, x2 - x1);
    mvvline(y1, x1, 0, y2 - y1);
    mvvline(y1, x2, 0, y2 - y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void CLIMenuOutput::print(int x, int y, const char *text) const {
    mvprintw(y + rowOffset, x + columnOffset, "%s", text);
}

void CLIMenuOutput::clearOutput() {
    clear();
    refresh();
    this->drawRect(0, 0, this->getRows() + rowOffset, this->getColumns() + columnOffset);
}

void CLIMenuOutput::drawMenu(Menu *menuItem) {

    print(1, 0, menuItem->name);

    int index = 2;

    Menu *previousMenu = menuItem->subMenu->get(menuItem->index - 1);
    Menu *selectedMenu = menuItem->subMenu->get(menuItem->index);
    Menu *nextMenu = menuItem->subMenu->get(menuItem->index + 1);

    print(1, index, ">");
    if (previousMenu != nullptr) {
        print(3, index - 1, previousMenu->name);
    }
    print(3, index, selectedMenu->name);
    if (nextMenu != nullptr) {
        print(3, index + 1, nextMenu->name);
    }
}





