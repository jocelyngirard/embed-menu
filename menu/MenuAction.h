//
// Created by Jocelyn Girard on 2019-04-03.
//

#ifndef MENU_MENUACTION_H
#define MENU_MENUACTION_H


#include "../Menu.h"

class MenuAction : public Menu {

public:
    void (*action)();

    explicit MenuAction(const char *name, void (*action)());
};


#endif //MENU_MENUACTION_H
