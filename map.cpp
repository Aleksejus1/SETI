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
    interactable_temp.location.x=interactableLocationX;
    interactable_temp.location.y=interactableLocationY;
    interactable_temp.colidable=isInteractableColidable;
    if(f.loadImage(imagePath,interactable_temp)==0){
        map::interactable.push_back(interactable_temp);
    }
    else f.error("The program was unable to create an interactable. [Info: imagePath="+imagePath+"; x="+f.toString(interactableLocationX)+"; y="+f.toString(interactableLocationY)+"; colidable="+f.toString(isInteractableColidable)+";]");
}

void map::createInteractable(std::string imagePath, int interactableLocationX, int interactableLocationY, int w, int h, bool isInteractableColidable){
    interact interactable_temp;
    interactable_temp.location.x=interactableLocationX;
    interactable_temp.location.y=interactableLocationY;
    interactable_temp.colidable=isInteractableColidable;
    interactable_temp.resized=true;
    interactable_temp.resized_h=h;
    interactable_temp.resized_w=w;
    if(f.loadImage(imagePath,interactable_temp)==0){
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
        map::layers.push_back(layer_temp);
    }
    else f.error("The program was unable to create a layer. [Info: imagePath="+imagePath+";");
}
