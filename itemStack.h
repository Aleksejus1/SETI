#ifndef ITEMSTACK_H
#define ITEMSTACK_H

#include "libs.h"
#include "item.h"


class itemStack
{
    public:
        itemStack();
        item containingItem;
        layer itemCountLayer;
        bool updateItem=true;
        int itemCount;
        void reset();
};

#endif // ITEMSTACK_H
