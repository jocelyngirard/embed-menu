//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_MENUOUTPUT_H
#define MENU_MENUOUTPUT_H

#include "../Menu.h"

class Menu;

class MenuOutput {

public:
    virtual ~MenuOutput() = default;

    virtual int getRows() const = 0;

    virtual int getColumns() const = 0;

    virtual void clearOutput() = 0;

    virtual void drawMenu(Menu *menu) = 0;
};


#endif //MENU_MENUOUTPUT_H
