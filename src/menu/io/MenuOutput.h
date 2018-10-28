//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_MENUOUTPUT_H
#define MENU_MENUOUTPUT_H

#include "../MenuItem.h"

class MenuOutput {


public:
    virtual ~MenuOutput() = default;

    virtual int getRows() const = 0;
    virtual int getColumns() const = 0;

    virtual void clearOutput() = 0;

    virtual void drawMenuTitle(const char* menuTitle) = 0;
    virtual void drawMenuItem(MenuItem* menuItem) = 0;
};


#endif //MENU_MENUOUTPUT_H
