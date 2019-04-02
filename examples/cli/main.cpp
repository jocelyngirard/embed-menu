#include <iostream>
#include "CLIMenuInteractor.h"
#include "CLIMenuOutput.h"
#include "../../Menu.h"
#include "../../menu/MenuRoot.h"
#include "../../menu/MenuBack.h"
#include "../../menu/MenuAction.h"
#include "../../menu/MenuSelect.h"


void onApertureSelected(float value) {
    printf("aperture: %f", value);
}

int main() {
    auto *output = new CLIMenuOutput;
    auto *interactor = new CLIMenuInteractor;
    auto *backMenu = new MenuBack();

    Menu *apertureMenu = new Menu("Aperture");
    apertureMenu->subMenu->add(new MenuSelect<float>("1.2", 1.2, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("1.4", 1.4, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("1.8", 1.8, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("2", 2, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("2.8", 2.8, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("4", 4, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("5.6", 5.6, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("8", 8, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("11", 11, onApertureSelected));
    apertureMenu->subMenu->add(new MenuSelect<float>("16", 16, onApertureSelected));
    apertureMenu->subMenu->add(backMenu);

    auto onISOSelected = [](int value) {};

    Menu *isoMenu = new Menu("ISO");
    isoMenu->subMenu->add(new MenuSelect<int>("100", 100, onISOSelected));
    isoMenu->subMenu->add(new MenuSelect<int>("200", 200, onISOSelected));
    isoMenu->subMenu->add(new MenuSelect<int>("400", 400, onISOSelected));
    isoMenu->subMenu->add(new MenuSelect<int>("800", 800, onISOSelected));
    isoMenu->subMenu->add(new MenuSelect<int>("1600", 1600, onISOSelected));
    isoMenu->subMenu->add(new MenuSelect<int>("3200", 3200, onISOSelected));
    isoMenu->subMenu->add(new MenuSelect<int>("6400", 6400, onISOSelected));
    isoMenu->subMenu->add(backMenu);

    auto onIntegrationSelected = [](int value) {};

    Menu *integrationMenu = new Menu("Integ. time");
    integrationMenu->subMenu->add(new MenuSelect<int>("100ms (bright)", 0x00, onIntegrationSelected));
    integrationMenu->subMenu->add(new MenuSelect<int>("200ms", 0x01, onIntegrationSelected));
    integrationMenu->subMenu->add(new MenuSelect<int>("300ms (default)", 0x02, onIntegrationSelected));
    integrationMenu->subMenu->add(new MenuSelect<int>("400ms", 0x03, onIntegrationSelected));
    integrationMenu->subMenu->add(new MenuSelect<int>("500ms", 0x04, onIntegrationSelected));
    integrationMenu->subMenu->add(new MenuSelect<int>("600ms (dim)", 0x05, onIntegrationSelected));
    integrationMenu->subMenu->add(backMenu);

    auto *root = new MenuRoot("Settings");
    root->subMenu->add(apertureMenu);
    root->subMenu->add(isoMenu);
    root->subMenu->add(integrationMenu);
    root->subMenu->add(new MenuAction("Quit", []() {
        system("clear"); // Houuuuu !
        exit(42);
    }));

    root->display(output);
    while (true) {
        root->interact(interactor);
        root->display(output);
    }
}
