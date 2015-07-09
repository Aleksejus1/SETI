#ifndef ENTITY_H
#define ENTITY_H

#include "libs.h"
#include "skill.h"
#include "layer.h"

class entity
{
    public:
        entity();
        SDL_Point location;
        struct doublePoint{double x,y;}; doublePoint legCenter;
        layer image;
        int map_location;
        std::string name;
        std::vector<skill> skills;
        void addSkill(std::string name,int experience, int level);
        float healthPointsMax=0,healthPoints=0,healthPointsPrev=0,manaPointsMax=0,manaPoints=0,manaPointsPrev=0,level=0;
};

#endif // ENTITY_H
