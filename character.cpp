#include "character.h"
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

character::character(int inventoryX, int inventoryY, int ammountOfSlotsInInventory,int offset_x,int offset_y,int offset_x2,int offset_y2)
{
    character::inventory.setOffesets(offset_x,offset_y,offset_x2,offset_y2);
    character::inventory.setLocations(inventoryX,inventoryY);
    character::inventory.addItemStacks(ammountOfSlotsInInventory);
}