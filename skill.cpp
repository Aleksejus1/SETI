#include "skill.h"
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