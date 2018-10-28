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
    const char *name;
    struct MenuItem *menuItems = nullptr;
    MenuItem *current = nullptr;
    bool stateChanged = false;

    void setCurrent(MenuItem *current);

public:

    explicit Menu(const char *name);

    void add(const char *name);

    void interact(MenuInteractor *interactor);

    void display(MenuOutput *output);

    MenuItem *getCurrent();

    MenuItem *next();

    MenuItem *previous();
};


#endif //MENU_MENU_H
