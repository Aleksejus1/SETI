#ifndef CHARACTERSPACE_H
#define CHARACTERSPACE_H
#include "space.h"

class characterSpace: public space
{
    public:
        characterSpace();
        float zoom=(float)1/(float)5;
        float scrollBarOffset=0;
        itemStack equipmentHandRight,equipmentHead,equipmentNeck,equipmentBody,equipmentLegs,equipmentHandLeft,equipmentFeet;
        bool update;
        float furthestPossibleSliderLocation;
        float ratioBetweenBarAndSlots;
        int distanceBetweenEquipmentSlots,distanceBetweenStats;
        SDL_Point equipmentTopLeftLocation,statTopLeftLocation;
        layer imageEquipmentBody,imageEquipmentHead,imageEquipmentJewels,imageEquipmentLegs,imageEquipmentShoes,imageEquipmentShield,imageEquipmentWeapon;
        layer imageScrollBar,imageScrollBarFull,imageScrollBubble,imageScrollBubbleFull,imageScroll;
        layer imageInventorySlot;
        layer imageStatHealth,imageStatAttack,imageStatStrength,imageStatAgility,imageStatInteligence;
        layer imageFull;
        struct bars{layer gradient,left,mid,right,full;};
        std::vector<bars> statsBar;

};

#endif // CHARACTERSPACE_H
