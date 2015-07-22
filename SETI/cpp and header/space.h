#ifndef SPACE_H
#define SPACE_H

#include "libs.h"
#include "itemStack.h"
#include "layer.h"
#include "objects.h"

class space{
    public:
        space();
		std::string name = "";
		bool open = false;
		struct is{ libs::fo location; itemStack ist; };
		std::vector<is> itemStacks;
        layer imageMain;
		int rowsInInventory = 0;
		SDL_Point slotLocationTopLeft, slotLocationTopLeftBase, location;
		float ratioBetweenBarAndSlots = 0;
		float scrollBarOffset = 0;
		int pressedId = -1;
		SDL_Rect slotBoundary;
		int slotsInOneRow = 0; //Amount of slots in a single inventory row
		int distanceBetweenSlots = 0; //Pixel distance between slots in the inventory
        std::vector<int> slotsLocationsX;
        void addItemStack();
        void addItemStack(int itemCount, item itemToPut);
        void addItemStacks(int ammount);
        void addItemStacks(int ammount, int itemCount, item itemToPut);
        void setItemStack(int itemStackId, int itemCount);
        void setItemStack(int itemStackId, int itemCount, item itemToSet);
};

#endif // SPACE_H
