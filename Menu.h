//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_MENU_H
#define MENU_MENU_H

#include "lib/LinkedList.h"
#include "io/MenuOutput.h"
#include "io/MenuInteractor.h"

#define min(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#define max(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

class MenuOutput;

class Menu {

public:
    int index = 0;

    const char *name;

    LinkedList<Menu *> *subMenu = new LinkedList<Menu *>();

    explicit Menu(const char *name);

    virtual ~Menu() = default;
};


#endif //MENU_MENU_H
