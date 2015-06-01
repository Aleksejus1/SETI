#ifndef CHARACTER_H
#define CHARACTER_H
#include "entity.h"
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
#include "space.h"

class character: public entity
{
    public:
        character(int inventoryX, int inventoryY, int ammountOfSlotsInInventory,int offset_x,int offset_y,int offset_x2,int offset_y2);
        float experiencePoints;
        float baseMovementSpeed=1;
        float movementSpeed=baseMovementSpeed;
        space inventory;
        int isInBattle=0;
};

#endif // CHARACTER_H
