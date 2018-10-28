//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_SCREEN_H
#define MENU_SCREEN_H

#include "../menu/io/MenuOutput.h"

class CLIMenuOutput : public MenuOutput {

private:
    int rowOffset = 1;
    int columnOffset = 1;

    ~CLIMenuOutput() override;

    void drawRect(int y1, int x1, int y2, int x2);
    void print(int x, int y, const char *text) const;

public:
    CLIMenuOutput();

    int getRows() const override;

    int getColumns() const override;

    void drawMenuTitle(const char *menuTitle) override;

    void drawMenuItem(MenuItem* menuItem) override;

    void clearOutput() override;

};


#endif //MENU_SCREEN_H
