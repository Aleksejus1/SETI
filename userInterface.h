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

class userInterface
{
    public:
        userInterface();
        SDL_Surface* red;
        SDL_Surface* blue;
        SDL_Surface* grey;
        SDL_Surface* green;
        layer bar_red,bar_blue,bar_green,bar_grey,bar_empty,characterUI;
};

#endif // USERINTERFACE_H
