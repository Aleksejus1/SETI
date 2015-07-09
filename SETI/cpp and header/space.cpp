#include "space.h"
#include "itemStack.h"
#include "libs.h"

space::space(){
    //ctor
}

void space::addItemStack(){
    is itemStack_temp;
    space::itemStacks.push_back(itemStack_temp);
}
void space::addItemStack(int itemCount, item itemToPut){
    is itemStack_temp;
    itemStack_temp.ist.containingItem=itemToPut;
	itemStack_temp.ist.itemCount = itemCount;
    space::itemStacks.push_back(itemStack_temp);
}
void space::addItemStacks(int ammount){
    is itemStack_temp;
    for(int i=0; i<ammount; i++) space::itemStacks.push_back(itemStack_temp);
}
void space::addItemStacks(int ammount, int itemCount, item itemToPut){
    is itemStack_temp;
	itemStack_temp.ist.containingItem = itemToPut;
	itemStack_temp.ist.itemCount = itemCount;
    for(int i=0; i<ammount; i++) space::itemStacks.push_back(itemStack_temp);
}
void space::setItemStack(int itemStackId, int itemCount){
	space::itemStacks[itemStackId].ist.itemCount = itemCount;
}
void space::setItemStack(int itemStackId, int itemCount, item itemToSet){
	space::itemStacks[itemStackId].ist.itemCount = itemCount;
	space::itemStacks[itemStackId].ist.containingItem = itemToSet;
}