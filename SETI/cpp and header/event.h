#ifndef EVENT_H
#define EVENT_H

#include "libs.h"
#include "info.h"

class event
{
    public:
        event();
        std::string type;
        info information;
        bool eventCreated=false;
        void createEnterEvent(int mapId, int entranceX, int entranceY);
        void createBattleEvent(int zoneId, std::vector<int> entitiesIds);
        void createGatherEvent(int idOfGatherable);
};

#endif // EVENT_H
