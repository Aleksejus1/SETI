#ifndef ENTITY_H
#define ENTITY_H
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
#include "skill.h"
#include "layer.h"

class entity
{
    public:
        entity();
        SDL_Point location;
        struct doublePoint{double x,y;}; doublePoint legCenter;
        layer image;
        int map_location,level;
        std::string name;
        std::vector<skill> skills;
        void addSkill(std::string name,int experience, int level);
        float healthPointsMax,healthPoints,healthPointsPrev,manaPointsMax,manaPoints,manaPointsPrev;
};

#endif // ENTITY_H
