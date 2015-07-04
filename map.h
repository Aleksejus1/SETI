#ifndef MAP_H
#define MAP_H

#include "libs.h"
#include "interact.h"
#include "objects.h"
#include "zone.h"
#include "mobSpawner.h"
#include "layer.h"
#include "gather.h"

class map{
    public:
        map();
        //variables
        std::string name,id;
        std::vector<mobSpawner> mobSpawnLocations;
        std::vector<layer> layers;
        std::vector<zone> zones;
        std::vector<objects> object;
        std::vector<interact> interactable;
        std::vector<gather> gatherable;
        std::vector<SDL_Point> platforms;
        //functions
        void addGatherableReturnItemStack(int itemCount,item containingItem,gather &gatherableTypeVar);
        void createGatherable(int gatherableLocationX, int gatherableLocationY, bool colidable, float gatherTime, int requiredLevel, std::string requiredSkillName);
        void addStage(float timeUntilNextStage, bool isItAShortcutStage, bool isItGatherable, std::string imagePath,gather &gatherableTypeVar);
        void createInteractable(std::string imagePath, int interactableLocationX, int interactableLocationY, bool isInteractableColidable);
        void createInteractable(std::string imagePath, int interactableLocationX, int interactableLocationY, int w, int h, bool isInteractableColidable);
        void createObject(std::string imagePath, int objectLocationX, int objectLocationY, bool isObjectColidable);
        void createLayer(std::string imagePath);
        void createZone(std::string owner, std::string zoneName);
        void createMobSpawner();

};

#endif // MAP_H
