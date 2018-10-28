#include <Menu.h>
#include <MenuItem.h>

#include "GFXMenuInteractor.h"
#include "GFXMenuOutput.h"

MenuInteractor *interactor;
MenuOutput *output;
Menu *menu;

void setup() {
  interactor = new GFXMenuInteractor;
  output = new GFXMenuOutput;
  menu = new Menu("Settings");

  menu->add("Aperture");
  menu->add("ISO");
  menu->add("Shutter speed");
  menu->add("Integ. time");
  menu->add("Quit");

  menu->display(output);
}

void loop() {
  menu->interact(interactor);
  menu->display(output);
}
