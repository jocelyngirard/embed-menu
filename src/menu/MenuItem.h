//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_MENUITEM_H
#define MENU_MENUITEM_H

struct MenuItem {
    const char *name;
    struct MenuItem *next;
    struct MenuItem *previous;
};

#endif //MENU_MENUITEM_H
