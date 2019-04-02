//
// Created by Jocelyn Girard on 2019-04-02.
//

#ifndef MENU_MENUROOT_H
#define MENU_MENUROOT_H


#include "../io/MenuInteractor.h"
#include "../io/MenuOutput.h"

class MenuRoot : public Menu {

public:
    Menu *currentMenu = this;

    explicit MenuRoot(const char *name);

    void display(MenuOutput *output);

    void interact(MenuInteractor *interactor);

    void back();
};


#endif //MENU_MENUROOT_H
