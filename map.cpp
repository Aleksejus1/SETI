#include "map.h"
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
#include "interact.h"
#include "objects.h"
#include "functions.h"
#include "variables.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_syswm.h"
#include "zone.h"

map::map(functions &fu):
    f(fu)
{
    //ctor
}

void map::addGatherableReturnItemStack(int itemCount,item containingItem,gather &gatherableTypeVar){
    itemStack itemStack_temp;
    itemStack_temp.itemCount=itemCount;
    itemStack_temp.containingItem=containingItem;
    gatherableTypeVar.returnItems.push_back(itemStack_temp);
}

void map::createGatherable(int gatherableLocationX, int gatherableLocationY, bool colidable, float gatherTime, int requiredLevel, std::string requiredSkillName){
    //also need to call createEvent function, addStage function, addGatherableReturnItemStack
    gather gather_temp;
    gather_temp.colidable=colidable;
    gather_temp.gatherTime=gatherTime;
    gather_temp.requiredLevel=requiredLevel;
    gather_temp.requiredSkillName=requiredSkillName;
    gather_temp.location.x=gatherableLocationX;
    gather_temp.location.y=gatherableLocationY;
    map::gatherable.push_back(gather_temp);
}

void map::addStage(float timeUntilNextStage, bool isItAShortcutStage, bool isItGatherable, std::string imagePath,gather &gatherableTypeVar){
    stage stage_temp;
    stage_temp.timeUntilNextStage=timeUntilNextStage;
    stage_temp.shortcut=isItAShortcutStage;
    stage_temp.isItGatherable=isItGatherable;
    if(f.loadImage(imagePath,stage_temp.image)==0){
        gatherableTypeVar.stages.push_back(stage_temp);
    }
    else f.error("The program was unable to create an interactable. [Info: "+
                 f.toString(timeUntilNextStage)+"=timeUntilNextStage"+";\n"+
                 "isItAShortcutStage="+f.toString(isItAShortcutStage)+";\n"+
                 "imagePath="+imagePath+";\n"+
                 "]");
}

void createMobSpawner(int location_x, int location_y){
    mobSpawner spawner_temp;
    spawner_temp.location.x=location_x;
    spawner_temp.location.y=location_y;
}

void map::createZone(std::string owner, std::string zoneName){
    zone zone_temp;
    zone_temp.owner=owner;
    zone_temp.name=zoneName;
    if(map::layers.size()>0) {
        zone_temp.id=f.getZoneId(map::layers[0].surface);
        zone_temp.color=f.getColor(zone_temp.id);
        if(zone_temp.id!=-1){
            map::zones.push_back(zone_temp);
        }
        else f.error("The program was unable to create a zone. [Info: owner="+owner+"; zoneName="+zoneName+";");
    }
    else f.error("The program was unable to create a zone, because the map has no layers;");
}

void map::createInteractable(std::string imagePath, int interactableLocationX, int interactableLocationY, bool isInteractableColidable){
    interact interactable_temp;
    interactable_temp.colidable=isInteractableColidable;
    if(f.loadImage(imagePath,interactable_temp)==0){
        interactable_temp.location.x=interactableLocationX;
        interactable_temp.location.y=interactableLocationY;
        map::interactable.push_back(interactable_temp);
    }
    else f.error("The program was unable to create an interactable. [Info: imagePath="+imagePath+"; x="+f.toString(interactableLocationX)+"; y="+f.toString(interactableLocationY)+"; colidable="+f.toString(isInteractableColidable)+";]");
}

void map::createInteractable(std::string imagePath, int interactableLocationX, int interactableLocationY, int w, int h, bool isInteractableColidable){
    interact interactable_temp;
    interactable_temp.colidable=isInteractableColidable;
    if(f.loadImage(imagePath,interactable_temp)==0){
        interactable_temp.location.x=interactableLocationX;
        interactable_temp.location.y=interactableLocationY;
        f.resizeImage(0,w,h,f.antialiasing,interactable_temp);
        map::interactable.push_back(interactable_temp);
    }
    else f.error("The program was unable to create an interactable. [Info: imagePath="+imagePath+"; x="+f.toString(interactableLocationX)+"; y="+f.toString(interactableLocationY)+"; colidable="+f.toString(isInteractableColidable)+";]");
}

void map::createObject(std::string imagePath, int objectLocationX, int objectLocationY, bool isObjectColidable){
    objects object_temp;
    object_temp.location.x=objectLocationX;
    object_temp.location.y=objectLocationY;
    object_temp.colidable=isObjectColidable;
    if(f.loadImage(imagePath,object_temp)==0){
        map::object.push_back(object_temp);
    }
    else f.error("The program was unable to create an object. [Info: imagePath="+imagePath+"; objectLocationX="+f.toString(objectLocationX)+"; objectLocationY="+f.toString(objectLocationY)+"; isObjectColidable="+f.toString(isObjectColidable)+";");
}

void map::createLayer(std::string imagePath){
    layer layer_temp;
    if(f.loadImage(imagePath,layer_temp)==0){
        f.resizeImage(0,f.SCREEN_WIDTH,f.SCREEN_HEIGHT,f.antialiasing,layer_temp);
        map::layers.push_back(layer_temp);
    }
    else f.error("The program was unable to create a layer. [Info: imagePath="+imagePath+";");
}