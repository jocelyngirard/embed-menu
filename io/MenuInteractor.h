//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_MENUINTERACTOR_H
#define MENU_MENUINTERACTOR_H

enum Input {
    Up, Down, Select, Other
};

class MenuInteractor {

public:
    virtual ~MenuInteractor() = default;

    virtual Input waitInput() = 0;

};

#endif //MENU_MENUINTERACTOR_H
