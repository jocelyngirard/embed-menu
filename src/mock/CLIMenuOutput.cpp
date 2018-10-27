//
// Created by Jocelyn Girard on 26/10/2018.
//

#include <curses.h>
#include <iostream>
#include "CLIMenuOutput.h"

CLIMenuOutput::CLIMenuOutput() {
    initscr();
    keypad(stdscr, TRUE);
}

CLIMenuOutput::~CLIMenuOutput() {}

int CLIMenuOutput::getRows() {
    return 4;
}

int CLIMenuOutput::getColumns() {
    return 21;
}

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

void CLIMenuOutput::drawTextCenter(const char *text) {
    mvprintw((this->getRows() + 1) / 2, static_cast<int>(((this->getColumns() + 1) - std::strlen(text)) / 2), "%s", text);
}

void CLIMenuOutput::erase() {
    clear();
    refresh();
}

void CLIMenuOutput::drawMenuTitle(const char *menuTitle) {

}

void CLIMenuOutput::drawMenuItem(MenuItem* menuItem) {
    this->erase();
    this->drawRect(0, 0, this->getRows() + 1, this->getColumns() + 1);
    this->drawTextCenter(menuItem->name);
}





