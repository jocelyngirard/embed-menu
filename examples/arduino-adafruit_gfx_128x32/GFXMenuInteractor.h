#ifndef MENU_INPUT_H
#define MENU_INPUT_H

#include <io/MenuInteractor.h>

#if defined(ESP8266)
  #define BUTTON_A 0
  #define BUTTON_B 16
  #define BUTTON_C 2
#elif defined(ESP32)
  #define BUTTON_A 15
  #define BUTTON_B 32
  #define BUTTON_C 14
#elif defined(ARDUINO_STM32F2_FEATHER)
  #define BUTTON_A PA15
  #define BUTTON_B PC7
  #define BUTTON_C PC5
#elif defined(TEENSYDUINO)
  #define BUTTON_A 4
  #define BUTTON_B 3
  #define BUTTON_C 8
#elif defined(ARDUINO_FEATHER52)
  #define BUTTON_A 31
  #define BUTTON_B 30
  #define BUTTON_C 27
#else // 32u4, M0, M4, and 328p
  #define BUTTON_A 9
  #define BUTTON_B 6
  #define BUTTON_C 5
#endif

class GFXMenuInteractor : public MenuInteractor {

private:
    ~GFXMenuInteractor() override;

public:
    GFXMenuInteractor();

    Input waitInput() override;
};


#endif //MENU_INPUT_H
