#ifndef INTERACT_H
#define INTERACT_H

#include "libs.h"
#include "objects.h"
#include "event.h"

class interact: public objects
{
    public:
        event events;
};

#endif // INTERACT_H
