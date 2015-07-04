#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "libs.h"
#include "layer.h"
#include "Texolder.h"

class functions;

class userInterface{
    public:
        userInterface(functions *fp);
        functions *f;
        Texolder botUItxl;
        layer bar_empty,characterUI,botUI,topUIReflection;
        struct butt{layer state[2]; int currentState=0;};
        int botUIDistanceBetweenButtons=0,topUIDistanceBetweenButtons[3]={0,0,0};
        SDL_Point botUIButtonsTopLeftLocation={0,0},topUIButtonsTopLeftLocation={0,0};
        butt botUIButtons[4],topUIButtons[3];
        struct messageAndCount{layer message; float* countAmount; bool* update;};
        messageAndCount level;
        struct barAndUpdate : messageAndCount {layer bar;};
        barAndUpdate bar_green;
        struct bars : barAndUpdate {layer max_count; float* max_countAmount;};
        bars bar_red,bar_blue,bar_grey;
        bars* all[3];
};

#endif // USERINTERFACE_H
