#ifndef CHARACTERSPACE_H
#define CHARACTERSPACE_H
#include "space.h"

class characterSpace: public space
{
    public:
        characterSpace();
        float zoom=(float)1/(float)5;
        float scrollBarOffset=0;
        bool update;
        float furthestPossibleSliderLocation;
        float ratioBetweenBarAndSlots;
        layer imageEquipmentBody,imageEquipmentHead,imageEquipmentJewels,imageEquipmentLegs,imageEquipmentShoes,imageEquipmentShield,imageEquipmentWeapon;
        layer imageScrollBar,imageScrollBarFull,imageScrollBubble,imageScrollBubbleFull,imageScroll;
        layer imageInventorySlot;
        layer imageFull;

};

#endif // CHARACTERSPACE_H
