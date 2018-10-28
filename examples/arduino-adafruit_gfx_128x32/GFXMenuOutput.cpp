#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "GFXMenuOutput.h"

#if (SSD1306_LCDHEIGHT != 32)
 #error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

Adafruit_SSD1306 display = Adafruit_SSD1306();

GFXMenuOutput::GFXMenuOutput() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

GFXMenuOutput::~GFXMenuOutput() = default;

int GFXMenuOutput::getRows() const { return 4; }

int GFXMenuOutput::getColumns() const { return 21; }

void GFXMenuOutput::clearOutput() {
  display.clearDisplay();
}

void GFXMenuOutput::drawMenuTitle(const char *menuTitle) {
  display.setCursor(0,0);
  display.print(menuTitle);
}

void print(int x, int y, const char* text) {
  display.setCursor(x,y);
  display.print(text);
}

void GFXMenuOutput::drawMenuItem(MenuItem *menuItem) {
    bool hasPrevious = menuItem->previous != nullptr;
    bool hasNext = menuItem->next != nullptr;
    int index = !hasPrevious ? 1 : !hasNext ? 3 : 2;
    
    print(1, index, ">");
    print(3, index, menuItem->name);

    if (hasPrevious) {
        print(3, index - 1, menuItem->previous->name);
    }

    if (hasNext) {
        print(3, index + 1, menuItem->next->name);
    }
  display.display();
}
