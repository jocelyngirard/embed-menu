#include <SPI.h>
#include <Wire.h>
#include <JC_Button.h>

#include "GFXMenuInteractor.h"

Button previousButton(BUTTON_A);
Button selectButton(BUTTON_B);
Button nextButton(BUTTON_C);

GFXMenuInteractor::GFXMenuInteractor(){
  previousButton.begin();
  nextButton.begin();
  selectButton.begin();
}

GFXMenuInteractor::~GFXMenuInteractor() = default;

Input GFXMenuInteractor::waitInput() {
  previousButton.read();
  nextButton.read();
  selectButton.read();

  if (previousButton.wasReleased() == true) {
    return Up;
  } else if (nextButton.wasReleased() == true) {
    return Down;
  } else if (selectButton.wasReleased() == true) {
    return Select;
  } else {
    return Other;
  }
}
