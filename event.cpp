#include "event.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_syswm.h"
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

event::event()
{
    //ctor
}

void event::createEnterEvent(int mapId, int entranceX, int entranceY){
    if(!event::eventCreated){
        event::type="Enter";
        event::information.addInfo(mapId);
        event::information.addInfo(entranceX);
        event::information.addInfo(entranceY);
        event::eventCreated=true;
    }
}

void event::createBattleEvent(int zoneId, std::vector<int> entitiesIds){
    if(!event::eventCreated){
        event::type="Battle";
        event::information.addInfo(zoneId);
        int temp=entitiesIds.size();
        event::information.addInfo(temp);
        for(int i=0; i<temp;i++){
            event::information.addInfo(entitiesIds[i]);
        }
        entitiesIds.clear();
        event::eventCreated=true;
    }
}
