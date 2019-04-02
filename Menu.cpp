//
// Created by Jocelyn Girard on 26/10/2018.
//

#include "Menu.h"

Menu::Menu(const char *name) {
    this->name = name;
    this->subMenu = new LinkedList<Menu *>();
}

Menu::~Menu() {
}




