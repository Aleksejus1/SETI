#include "mobSpawner.h"
#include "libs.h"

mobSpawner::mobSpawner()
{
    //ctor
}

void mobSpawner::addMobs(entity enemy){
    mobSpawner::mobs.push_back(enemy);
}

void mobSpawner::addMobs(entity enemy, int ammount){
    for(int i=0; i<ammount; i++){
        mobSpawner::mobs.push_back(enemy);
    }
}