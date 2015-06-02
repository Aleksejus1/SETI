#ifndef STAGE_H
#define STAGE_H
#include "layer.h"

class stage
{
    public:
        stage();
        layer image; //picture
        float timeUntilNextStage; //cooldown for next stage
        bool shortcut=false; //if it's a shortcut then when gathered goes to the latest shortcut stage
};

#endif // STAGE_H
