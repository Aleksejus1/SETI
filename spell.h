#ifndef SPELL_H
#define SPELL_H
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


class spell
{
    public:
        spell();
        std::string elementType; //The name of element
        float damage=0; // Damage amount of the spell
        bool isLearned=false; // Is the spell learned or not
        bool isActive=false; // Is the spell active or not
        float manaCost=0; //Mana cost of the spell
        layer base,icon_active, icon_cooldown; //Shape - the layer of spell, icon_active - active icon spell in UI, etc..
        SDL_Point offset; //The location of rendered image
};

#endif // SPELL_H
