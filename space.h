#ifndef SPACE_H
#define SPACE_H

#include "libs.h"
#include "itemStack.h"
#include "layer.h"
#include "objects.h"

class space{
    public:
        space();
        struct is{libs::fo location; itemStack is;};
        std::vector<is> itemStacks;
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
