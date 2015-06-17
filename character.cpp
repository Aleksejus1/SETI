#include "character.h"
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

character::character(){
    addStat("Health",  40,0);
    addStat("Attack",  60,0);
    addStat("Strength",25,0);
    addStat("Agility", 31,0);
    addStat("Intel",   20,0);
}

void character::addStat(std::string statName, int levelBase, int levelAddition){
    character::stat tempStat;
    tempStat.statName=statName;
    tempStat.levelBase=levelBase;
    tempStat.levelAddition=0;
    tempStat.levelBase=levelBase;
    stats.push_back(tempStat);
    addStatAddition(levelAddition,statName);
}

int character::findStat(std::string statName){
    for(int i=0; i<stats.size(); i++){
        if(stats[i].statName==statName) return i;
    }
    return -1;
}

void character::addStatAddition(int addition, std::string statName){
    int statId=findStat(statName);
    if(statId!=-1){
        stats[statId].levelAddition+=addition;
        stats[statId].levelTotal=stats[statId].levelBase+stats[statId].levelAddition;
    }
}