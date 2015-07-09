#ifndef ITEM_H
#define ITEM_H

#include "objects.h"
#include "layer.h"

class item
{
    public:
        item();
        layer image;
        friend bool operator==(item &a, item &b);
        std::string name;
        std::string type;
        float damage;
        struct affect{std::string statName; float ammount;};
        std::vector<affect> affectedStats;
        void reset();
};

#endif // ITEM_H
