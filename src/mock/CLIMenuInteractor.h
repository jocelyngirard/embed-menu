//
// Created by Jocelyn Girard on 26/10/2018.
//

#ifndef MENU_INPUT_H
#define MENU_INPUT_H

#include "../menu/io/MenuInteractor.h"

class CLIMenuInteractor : public MenuInteractor {

public:
    ~CLIMenuInteractor() override;

    Input waitInput() override;
};


#endif //MENU_INPUT_H
