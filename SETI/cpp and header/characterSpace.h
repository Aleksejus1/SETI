#ifndef CHARACTERSPACE_H
#define CHARACTERSPACE_H
#include "space.h"
#include "Texolder.h"

class functions;

class characterSpace: public space{
    public:
        characterSpace(functions* fp);
        Texolder txl;
        float zoom=(float)1/(float)5;
        struct equipment{itemStack item; std::string typeName; layer image; int x; int y;};
		libs::fo slotBase;
        int equipmentCount=7;
        equipment equipmentHandRight,equipmentHead,equipmentNeck,equipmentBody,equipmentLegs,equipmentHandLeft,equipmentFeet;
        equipment* equipmentAll[7];
        bool update;
        int furthestPossibleSliderLocation;
        int distanceBetweenEquipmentSlots,distanceBetweenStats;
        SDL_Point equipmentTopLeftLocation,statTopLeftLocation,closeLocation;
        layer closeButton;
        layer imageScrollBar,imageScrollBarFull,imageScrollBubble,imageScrollBubbleFull,imageScroll;
        layer imageInventorySlot[2];
        int doubleClick=-1;
        layer imageFull;
        struct bars{layer gradient,left,mid,right,full;};
        std::vector<bars> statsBar;
        bars additionBar;

};

#endif // CHARACTERSPACE_H
