#ifndef CHARACTERSPACE_H
#define CHARACTERSPACE_H
#include "space.h"
#include "Texolder.h"

class functions;

class characterSpace: public space{
    public:
		characterSpace(functions* fp);
		Texolder			
			txl;
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
			furthestPossibleSliderLocation = 0,
			distanceBetweenEquipmentSlots = 0,
			distanceBetweenStats = 0,
			scrollBubbleHeight = 0,
			scrollBarHeight = 0,
			equipmentCount = 7,
			doubleClick = -1,
			sliderWidth = 0;
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
