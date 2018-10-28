#include "CLIMenuInteractor.h"
#include "CLIMenuOutput.h"
#include "../../Menu.h"

int main();

int main() {
    MenuInteractor *interactor = new CLIMenuInteractor;
    MenuOutput *output = new CLIMenuOutput;
    Menu *menu = new Menu("Settings");

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

