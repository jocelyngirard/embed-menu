//
// Created by Jocelyn Girard on 2019-04-02.
//

#include "MenuRoot.h"
#include "MenuBack.h"
#include "MenuAction.h"
#include "MenuSelect.h"

MenuRoot::MenuRoot(const char *string) : Menu(string) {}

void MenuRoot::interact(MenuInteractor *interactor) {
    switch (interactor->waitInput()) {
        case Up:
            this->currentMenu->index = max(this->currentMenu->index - 1, 0);
            break;
        case Down:
            this->currentMenu->index = min(this->currentMenu->index + 1, this->currentMenu->subMenu->size() - 1);
            break;
        case Select: {
            Menu *selectedMenu = this->currentMenu->subMenu->get(this->currentMenu->index);
            if (auto action = dynamic_cast<MenuAction *>(selectedMenu)) {
                action->action();
            } else if (auto selection = dynamic_cast<MenuSelect<int> *>(selectedMenu)) {
                selection->onValueSelected(selection->value);
            } else if (auto selection = dynamic_cast<MenuSelect<float> *>(selectedMenu)) {
                selection->onValueSelected(selection->value);
            } else if (dynamic_cast<MenuBack *>(selectedMenu) != nullptr) {
                this->back();
            } else if (selectedMenu->subMenu->size() > 0) {
                this->currentMenu = selectedMenu;
            }
        }
            break;
        default:
            break;
    }
}

void MenuRoot::display(MenuOutput *output) {
    output->clearOutput();
    output->drawMenu(this->currentMenu);
}

void MenuRoot::back() {
    this->currentMenu = this;
}

