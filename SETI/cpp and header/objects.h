#ifndef OBJECTS_H
#define OBJECTS_H

#include "libs.h"
#include "layer.h"

class objects: public layer
{
    public:
        objects();
        bool colidable;
};

#endif // OBJECTS_H
