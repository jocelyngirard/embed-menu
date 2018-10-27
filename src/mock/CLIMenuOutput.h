//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "../menu/io/MenuOutput.h"

class CLIMenuOutput : public MenuOutput {

private:
    ~CLIMenuOutput() override;

    void drawRect(int y1, int x1, int y2, int x2);

    void drawTextCenter(const char *text);

    void erase();


public:
    CLIMenuOutput();

    int getRows() override;

    int getColumns() override;

    void drawMenuTitle(const char *menuTitle) override;

    void drawMenuItem(MenuItem* menuItem) override;
};


#endif //MENU_SCREEN_H
