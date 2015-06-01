#ifndef MAP_H
#define MAP_H
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
#include "interact.h"
#include "objects.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_syswm.h"
#include "zone.h"
#include "functions.h"
#include "mobSpawner.h"
#include "layer.h"

class map
{
    public:
        functions f;
        map(functions &fu);
        std::string name,id;
        std::vector<mobSpawner> mobSpawnLocations;
        std::vector<layer> layers;
        std::vector<zone> zones;
        std::vector<objects> object;
        std::vector<interact> interactable;
        void createInteractable(std::string imagePath, int interactableLocationX, int interactableLocationY, bool isInteractableColidable);
        void createInteractable(std::string imagePath, int interactableLocationX, int interactableLocationY, int w, int h, bool isInteractableColidable);
        void createObject(std::string imagePath, int objectLocationX, int objectLocationY, bool isObjectColidable);
        void createLayer(std::string imagePath);
        void createZone(std::string owner, std::string zoneName);
        void createMobSpawner();

};

#endif // MAP_H
