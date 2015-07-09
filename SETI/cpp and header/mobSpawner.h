#ifndef MOBSPAWNER_H
#define MOBSPAWNER_H

#include "libs.h"
#include "entity.h"

class mobSpawner
{
    public:
        mobSpawner();
        SDL_Point location;
        std::vector<entity> mobs;
        void addMobs(entity enemy);
        void addMobs(entity enemy, int ammount);
};

#endif // MOBSPAWNER_H
