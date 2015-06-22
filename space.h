#ifndef SPACE_H
#define SPACE_H
#include "itemStack.h"
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
#include "objects.h"

class space
{
    public:
        space();
        std::vector<itemStack> itemStacks;
        bool open=false;
        layer imageMain;
        int rowsInInventory;
        SDL_Point slotLocationTopLeft,location;
        int slotLocationBottomY;
        int distanceBetweenSlots;
        std::vector<int> slotsLocationsX;
        int slotsInOneRow;
        void addItemStack();
        void addItemStack(int itemCount, item itemToPut);
        void addItemStacks(int ammount);
        void addItemStacks(int ammount, int itemCount, item itemToPut);
        void setItemStack(int itemStackId, int itemCount);
        void setItemStack(int itemStackId, int itemCount, item itemToSet);
};

#endif // SPACE_H
