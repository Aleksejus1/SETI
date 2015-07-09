#include "entity.h"
#include "libs.h"

entity::entity()
{
    entity::addSkill("strength",0,1);
    entity::addSkill("stamina",0,1);
    entity::addSkill("defense",0,1);
    entity::addSkill("agility",0,1);
    entity::addSkill("inteligence",0,1);
    entity::addSkill("charisma",0,1);
    entity::addSkill("wisdom",0,1);
    entity::addSkill("willpower",0,1);
    entity::addSkill("perception",0,1);
    entity::addSkill("crafting",0,1);
    entity::addSkill("mining",0,1);
    entity::addSkill("gathering",0,1);
}

void entity::addSkill(std::string name,int experience, int level){
    skill skill_temp;
    skill_temp.experience=(float)experience;
    skill_temp.setLevel(level);
    skill_temp.name=name;
    entity::skills.push_back(skill_temp);
}