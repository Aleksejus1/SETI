#ifndef CHARACTERSPACE_H
#define CHARACTERSPACE_H
#include "space.h"

class functions;

class characterSpace: public space{
    public:
		characterSpace(functions* fp);
		float				
			zoom = (float)1 / (float)5;
		struct equipment{ itemStack item; std::string typeName; layer image; int x; int y; } 
			equipmentHandRight,
			equipmentHandLeft,
			equipmentHead, 
			equipmentNeck, 
			equipmentBody, 
			equipmentLegs, 
			equipmentFeet,
			*equipmentAll[7];
		libs::fo			
			slotBase;
		bool				
			update;
		int					
			distanceBetweenEquipmentSlots = 0,
			distanceBetweenStats = 0,
			equipmentCount = 7,
			doubleClick = -1;
		SDL_Point			
			equipmentTopLeftLocation, 
			statTopLeftLocation, 
			closeLocation;
		layer				
			closeButton,
			imageInventorySlot[2],
			imageFull;
		struct bars{ layer gradient, left, mid, right, full; }
			additionBar;
		std::vector<bars>	
			statsBar;
};

#endif // CHARACTERSPACE_H
