#ifndef MOBSPAWNER_H
#define MOBSPAWNER_H
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
#include "entity.h"

class mobSpawner
{
    public:
        mobSpawner();
        SDL_Point location;
        std::vector<entity> mobs;
        void addMobs(entity enemy);
        void addMobs(entity enemy, int ammount);
};

#endif // MOBSPAWNER_H
