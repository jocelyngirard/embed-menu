#include <SPI.h>
#include <Wire.h>

#include "GFXMenuInteractor.h"

GFXMenuInteractor::GFXMenuInteractor() {
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
}

GFXMenuInteractor::~GFXMenuInteractor() = default;

Input GFXMenuInteractor::waitInput() {
  if (!digitalRead(BUTTON_A)){
    return Up;
  }
  if (!digitalRead(BUTTON_B)){
    return Select;
  }
  if (!digitalRead(BUTTON_C)){
    return Down;
  }
  return Other;
}
