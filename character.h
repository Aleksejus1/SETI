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
#include "characterSpace.h"

class character: public entity
{
    public:
        character();
        float experiencePoints;
        float baseMovementSpeed=1;
        float movementSpeed=baseMovementSpeed;
        float experienceRequiredForNextLevel;
        std::string type;// class/rank of the player
        characterSpace inventory;
        int isInBattle=0;
        struct stat{std::string statName; int levelBase; layer image; int levelAddition; int levelTotal;};
        std::vector<stat> stats;
        int gathering=0;
        int gatherableId=-1;
        int gatherStartStage=0;
        float gatherTime=0;
        int gatherLevelRequired=0;
        void addStat(std::string statName, int levelBase, int levelAddition);
        int findStat(std::string statName);
        void addStatAddition(int addition, std::string statName);
};

#endif // CHARACTER_H
