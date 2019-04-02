//
// Created by Jocelyn Girard on 2019-04-03.
//

#ifndef MENU_MENUSELECT_H
#define MENU_MENUSELECT_H


#include "../Menu.h"

template<typename T>
class MenuSelect : public Menu {

public:
    T value;

    explicit MenuSelect(const char *name, T value, void (*onValueSelected)(T)) : Menu(name) {
        this->value = value;
        this->onValueSelected = onValueSelected;
    }

    void (*onValueSelected)(T);

};


#endif //MENU_MENUSELECT_H
