#include "mock/CLIMenuInteractor.h"
#include "mock/CLIMenuOutput.h"
#include "menu/Menu.h"

int main() {
    auto *interactor = new CLIMenuInteractor;
    MenuOutput *output = new CLIMenuOutput;
    Menu *menu = new Menu;

    menu->add("Aperture");
    menu->add("ISO");
    menu->add("Shutter speed");
    menu->add("Integ. time");
    menu->add("Quit");

    menu->display(output);

    while (true) {
        menu->interact(interactor);
        menu->display(output);
    }
}

