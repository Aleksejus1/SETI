#ifndef ZONE_H
#define ZONE_H

#include "libs.h"

class zone{
    public:
        zone();
        int id;
        SDL_Color color;
        std::string name,owner;
};

#endif // ZONE_H
