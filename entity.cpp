#include "entity.h"
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
    skill_temp.experience=experience;
    skill_temp.setLevel(level);
    skill_temp.name=name;
    entity::skills.push_back(skill_temp);
}