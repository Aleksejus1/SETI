#include "skill.h"
#include "libs.h"

skill::skill()
{
}

void skill::addExperience(int ammount){
    skill::experience+=ammount;
    if(skill::experience>=skill::requiredExperience){
        skill::experience-=skill::requiredExperience;
        skill::setLevel(skill::level+1);
    }
}

void skill::setLevel(int level){
    skill::level=level;
    skill::requiredExperience=skill::level*pow(skill::multiplier,skill::level);
}