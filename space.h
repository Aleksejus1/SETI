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
        layer slotFrame,inventoryL;
        objects frame,backPanel,slider;
        SDL_Point backPanelOffset,sliderOffset;
        int offsetY,ammountOfIntersections;
        bool open=false;
        void setOffesets(int backPanelOffsetX, int backPanelOffsetY, int sliderOffsetX, int sliderOffsetY);
        void setLocations(int x, int y);
        void addItemStack();
        void addItemStack(int itemCount, item itemToPut);
        void addItemStacks(int ammount);
        void addItemStacks(int ammount, int itemCount, item itemToPut);
        void setItemStack(int itemStackId, int itemCount);
        void setItemStack(int itemStackId, int itemCount, item itemToSet);
};

#endif // SPACE_H
