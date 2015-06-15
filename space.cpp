#include "space.h"
#include "itemStack.h"
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

void space::addItemStack(){
    itemStack itemStack_temp;
    space::itemStacks.push_back(itemStack_temp);
}

void space::addItemStack(int itemCount, item itemToPut){
    itemStack itemStack_temp;
    itemStack_temp.containingItem=itemToPut;
    itemStack_temp.itemCount=itemCount;
    space::itemStacks.push_back(itemStack_temp);
}

void space::addItemStacks(int ammount){
    itemStack itemStack_temp;
    for(int i=0; i<ammount; i++) space::itemStacks.push_back(itemStack_temp);
}

void space::addItemStacks(int ammount, int itemCount, item itemToPut){
    itemStack itemStack_temp;
    itemStack_temp.containingItem=itemToPut;
    itemStack_temp.itemCount=itemCount;
    for(int i=0; i<ammount; i++) space::itemStacks.push_back(itemStack_temp);
}

void space::setItemStack(int itemStackId, int itemCount){
    space::itemStacks[itemStackId].itemCount=itemCount;
}

void space::setItemStack(int itemStackId, int itemCount, item itemToSet){
    space::itemStacks[itemStackId].itemCount=itemCount;
    space::itemStacks[itemStackId].containingItem=itemToSet;
}