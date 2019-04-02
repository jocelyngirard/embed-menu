//
// Created by Jocelyn Girard on 2019-04-02.
//

#include "MenuBack.h"


MenuBack::MenuBack(void (MenuRoot::*back)()) : Menu("Back") {
    this->back = back;
}
