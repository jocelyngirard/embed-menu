//
// Created by Jocelyn Girard on 26/10/2018.
//

#include "Menu.h"

Menu::Menu(const char *name) {
    this->name = name;
}

void Menu::add(const char *name) {
    auto *new_node = new MenuItem;// (struct MenuItem *) malloc(sizeof(struct MenuItem));

    new_node->name = name;
    new_node->next = nullptr;

    if (this->menuItems == nullptr) {
        new_node->previous = nullptr;
        this->menuItems = new_node;
        return;
    }

    struct MenuItem *last = this->menuItems;
    while (last->next != nullptr) {
        last = last->next;
    }

    last->next = new_node;
    new_node->previous = last;

    if (current == nullptr) {
        current = this->menuItems;
    }
}

MenuItem *Menu::getCurrent() {
    return this->current;
}

MenuItem *Menu::next() {
    if (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

MenuItem *Menu::previous() {
    if (current->previous != nullptr) {
        current = current->previous;
    }
    return current;
}

void Menu::interact(MenuInteractor *interactor) {
    switch (interactor->waitInput()) {
        case Up:
            this->previous();
            break;
        case Down:
            this->next();
            break;
        case Select:
//                menu->getCurrent();
            break;
        default:
            break;
    }
}

void Menu::display(MenuOutput *output) {
    output->clearOutput();
    output->drawMenuTitle(this->name);
    output->drawMenuItem(this->getCurrent());
}
