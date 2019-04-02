#include "CLIMenuInteractor.h"
#include "CLIMenuOutput.h"
#include "../../Menu.h"
#include "../../MenuRoot.h"
#include "../../MenuBack.h"

MenuInteractor *interactor = new CLIMenuInteractor;
MenuOutput *output = new CLIMenuOutput;

auto *root = new MenuRoot("Settings");
auto *backMenu = new MenuBack(&MenuRoot::back);

Menu *getApertureMenu() {
    Menu *menu = new Menu("Aperture");
    menu->subMenu->add(new Menu("1.2"));
    menu->subMenu->add(new Menu("1.4"));
    menu->subMenu->add(new Menu("1.8"));
    menu->subMenu->add(new Menu("2"));
    menu->subMenu->add(new Menu("2.8"));
    menu->subMenu->add(new Menu("4"));
    menu->subMenu->add(new Menu("5.6"));
    menu->subMenu->add(new Menu("8"));
    menu->subMenu->add(new Menu("11"));
    menu->subMenu->add(new Menu("16"));
    menu->subMenu->add(backMenu);
    return menu;
}

Menu *getISOMenu() {
    Menu *menu = new Menu("ISO");
    menu->subMenu->add(new Menu("100"));
    menu->subMenu->add(new Menu("200"));
    menu->subMenu->add(new Menu("400"));
    menu->subMenu->add(new Menu("800"));
    menu->subMenu->add(new Menu("1600"));
    menu->subMenu->add(new Menu("3200"));
    menu->subMenu->add(new Menu("6400"));
    menu->subMenu->add(backMenu);
    return menu;
}

Menu *getIntegrationMenu() {
    Menu *menu = new Menu("Integ. time");
    menu->subMenu->add(new Menu("100ms ()"));
    menu->subMenu->add(new Menu("200ms"));
    menu->subMenu->add(new Menu("300ms (default)"));
    menu->subMenu->add(new Menu("400ms"));
    menu->subMenu->add(new Menu("500ms"));
    menu->subMenu->add(new Menu("600ms (dim)"));
    menu->subMenu->add(backMenu);
    return menu;
}

int main() {


    root->subMenu->add(getApertureMenu());
    root->subMenu->add(getISOMenu());
    root->subMenu->add(getIntegrationMenu());
    root->subMenu->add(backMenu);

    root->display(output);

    while (true) {
        root->interact(interactor);
        root->display(output);
    }
}
