#ifndef SPACE_H
#define SPACE_H
#include "slot.h"
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
        std::vector<slot> slots;
        layer slotFrame,inventoryL;
        objects frame,backPanel,slider;
        SDL_Point backPanelOffset,sliderOffset;
        int offsetY,ammountOfIntersections;
        bool open=false;
        void setOffesets(int backPanelOffsetX, int backPanelOffsetY, int sliderOffsetX, int sliderOffsetY);
        void setLocations(int x, int y);
        void addSlot();
        void addSlot(int itemCount, item itemToPut);
        void addSlots(int ammount);
        void addSlots(int ammount, int itemCount, item itemToPut);
        void setSlot(int slotId, int itemCount);
        void setSlot(int slotId, int itemCount, item itemToSet);
};

#endif // SPACE_H
