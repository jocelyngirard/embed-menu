#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include <io/MenuOutput.h>
#include <Adafruit_SSD1306.h>

class GFXMenuOutput : public MenuOutput {

private:
    ~GFXMenuOutput() override;

    void print(int x, int y, const char *text);

public:
    GFXMenuOutput();

    int getRows() const override;

    int getColumns() const override;

    void drawMenuTitle(const char *menuTitle) override;

    void drawMenuItem(MenuItem* menuItem) override;

    void clearOutput() override;

};


#endif //MENU_SCREEN_H
