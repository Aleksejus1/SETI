#include "mobSpawner.h"
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

mobSpawner::mobSpawner()
{
    //ctor
}

void mobSpawner::addMobs(entity enemy){
    mobSpawner::mobs.push_back(enemy);
}

void mobSpawner::addMobs(entity enemy, int ammount){
    for(int i=0; i<ammount; i++){
        mobSpawner::mobs.push_back(enemy);
    }
}