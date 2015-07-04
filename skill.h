#ifndef SKILL_H
#define SKILL_H

#include "libs.h"

class skill
{
    public:
        skill();
        void addExperience(int ammount);
        void setLevel(int level);
        int multiplier=1.025;
        std::string name;
        int level;
        float experience,requiredExperience;
};

#endif // SKILL_H
