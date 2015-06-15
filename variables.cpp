#include "variables.h"
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
#include "character.h"
#include "map.h"
#include "spell.h"

variables::variables(){
    player.healthPointsMax=999.0;
    player.healthPoints=player.healthPointsMax-333;
    player.manaPointsMax=820.0;
    player.manaPoints=player.manaPointsMax-800;
    player.experiencePoints=125.0;
    player.experienceRequiredForNextLevel=9001.0;
    player.location.x=320;//sets the starting x position of the player
    player.location.y=420;//sets the starting y position of the player
    player.map_location=1;//sets the starting map id of the player
    player.inventory.addItemStacks((2+8)*4+2);
    player.type="EGYPTIAN WARRIOR";
}
