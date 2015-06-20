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
        int map_location;
        std::string name;
        std::vector<skill> skills;
        void addSkill(std::string name,int experience, int level);
        float healthPointsMax=0,healthPoints=0,healthPointsPrev=0,manaPointsMax=0,manaPoints=0,manaPointsPrev=0,level=0;
};

#endif // ENTITY_H
