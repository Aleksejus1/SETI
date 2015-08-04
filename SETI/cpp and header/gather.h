#ifndef GATHER_H
#define GATHER_H
#include "interact.h"
#include "stage.h"
#include "itemStack.h"

class gather: public interact{
    public:
        std::vector<stage> stages;
        std::vector<itemStack> returnItems; //item returned when gathered
        std::string requiredSkillName;//skill type id which's level is used to determine if player can gather
        int currentStage=0;
        int requiredLevel=0;//required level of the given skill type for gathering at 100% success chance
        float gatherTime=0;//time required to gather
        float timeUntilRegrow=0;
};

#endif // GATHER_H
