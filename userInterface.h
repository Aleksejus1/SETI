#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_syswm.h"
#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <commdlg.h>
#include "layer.h"
#include "SDL_opengl.h"
#include "GL\gl.h"
#include "GL\GLU.h"

class userInterface
{
    public:
        userInterface();
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
