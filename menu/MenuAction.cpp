//
// Created by Jocelyn Girard on 2019-04-03.
//

#include "MenuAction.h"

MenuAction::MenuAction(const char *name, void (*action)()) : Menu(name) {
    this->action = action;
}