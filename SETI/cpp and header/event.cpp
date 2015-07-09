#include "event.h"
#include "libs.h"

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

void event::createGatherEvent(int idOfGatherable){
    if(!event::eventCreated){
        event::type="Gather";
        event::information.addInfo(idOfGatherable);
        event::eventCreated=true;
    }
}