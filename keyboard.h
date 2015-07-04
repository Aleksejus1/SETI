#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "libs.h"

class keyboard
{
    public:
        keyboard();
        int pressed=0;
        std::string name;
        SDL_Keycode keycode;
};

#endif // KEYBOARD_H
