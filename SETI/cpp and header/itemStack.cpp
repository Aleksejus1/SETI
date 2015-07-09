#include "itemStack.h"
#include "libs.h"

itemStack::itemStack()
{
    reset();
}

void itemStack::reset(){
    itemCount=0;
    containingItem.reset();
}