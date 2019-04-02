//
// Created by Jocelyn Girard on 2019-04-02.
//

#ifndef MENU_MENUBACK_H
#define MENU_MENUBACK_H


#include "Menu.h"
#include "MenuRoot.h"

class MenuBack : public Menu {

public:
    void (MenuRoot::*back)();
    explicit MenuBack(void (MenuRoot::*back)());
};


#endif //MENU_MENUBACK_H
