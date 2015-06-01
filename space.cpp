#include "space.h"
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

space::space()
{
    //ctor
}

void space::setOffesets(int backPanelOffsetX, int backPanelOffsetY, int sliderOffsetX, int sliderOffsetY){
    space::backPanelOffset.x=backPanelOffsetX;
    space::backPanelOffset.y=backPanelOffsetY;
    space::sliderOffset.x=sliderOffsetX;
    space::sliderOffset.y=sliderOffsetY;
}

void space::setLocations(int x, int y){
    space::frame.location.x=x;
    space::frame.location.y=y;
    space::backPanel.location.x=x+space::backPanelOffset.x;
    space::backPanel.location.y=y+space::backPanelOffset.y;
    space::slider.location.x=x+space::sliderOffset.x;
    space::slider.location.y=y+space::sliderOffset.y;
}

void space::addSlot(){
    slot slot_temp;
    space::slots.push_back(slot_temp);
}

void space::addSlot(int itemCount, item itemToPut){
    slot slot_temp;
    slot_temp.containingItem=itemToPut;
    slot_temp.itemCount=itemCount;
    space::slots.push_back(slot_temp);
}

void space::addSlots(int ammount){
    slot slot_temp;
    for(int i=0; i<ammount; i++) space::slots.push_back(slot_temp);
}

void space::addSlots(int ammount, int itemCount, item itemToPut){
    slot slot_temp;
    slot_temp.containingItem=itemToPut;
    slot_temp.itemCount=itemCount;
    for(int i=0; i<ammount; i++) space::slots.push_back(slot_temp);
}

void space::setSlot(int slotId, int itemCount){
    space::slots[slotId].itemCount=itemCount;
}

void space::setSlot(int slotId, int itemCount, item itemToSet){
    space::slots[slotId].itemCount=itemCount;
    space::slots[slotId].containingItem=itemToSet;
}