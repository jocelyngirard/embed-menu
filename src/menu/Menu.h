//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "MenuItem.h"
#include "io/MenuInteractor.h"
#include "io/MenuOutput.h"

class Menu {

private:
    struct MenuItem *menuItems = nullptr;
    MenuItem *current = nullptr;

public:
    void add(const char *name);

    void interact(MenuInteractor *interactor);

    void display(MenuOutput *output);

    MenuItem *getCurrent();

    MenuItem *next();

    MenuItem *previous();
};


#endif //MENU_MENU_H
