#ifndef LAYER_H
#define LAYER_H
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

class layer
{
    public:
        layer();
        SDL_Surface* surface=NULL;
        SDL_Texture* texture=NULL;
        SDL_Rect rect;
        bool resized=false;
        int resized_h=0;
        int resized_w=0;
};

#endif // LAYER_H
