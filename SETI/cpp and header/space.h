#ifndef SPACE_H
#define SPACE_H

#include "libs.h"
#include "itemStack.h"
#include "layer.h"
#include "objects.h"
#include "userInterface.h"

class space{
    public:
        space();
		struct is{ libs::fo location; itemStack ist; };
		std::vector<is>	
			itemStacks;
		std::string		
			name = "";
		bool			
			open = false;
        layer			
			imageMain;
		SDL_Point		
			slotLocationTopLeft, 
			slotLocationTopLeftBase, 
			location;
		SDL_Rect		
			slotBoundary;
		int				
			slotsInOneRow = 0, //Amount of slots in a single inventory row
			distanceBetweenSlots = 0, //Pixel distance between slots in the inventory
			pressedId = -1,
			rowsInInventory = 0;
        std::vector<int>
			slotsLocationsX;
		void			
			addItemStack(),
			addItemStack(int itemCount, item itemToPut),
			addItemStacks(int ammount),
			addItemStacks(int ammount, int itemCount, item itemToPut),
			setItemStack(int itemStackId, int itemCount),
			setItemStack(int itemStackId, int itemCount, item itemToSet);
		userInterface::scrollBar scrollBar;
};

#endif // SPACE_H
