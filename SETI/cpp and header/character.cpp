#include "character.h"
#include "entity.h"
#include "libs.h"
#include "functions.h"

character::character(functions* fp):
inventory(fp){
    addStat("Health",  0,0);
    addStat("Attack",  160,0);
    addStat("Strength",125,0);
    addStat("Agility", 31,0);
    addStat("Intel",   20,0);
}

void character::reset(){
    if(updateExperience) updateExperience=false;
    if(updateHealth)     updateHealth    =false;
    if(updateMana)       updateMana      =false;
    if(updateLevel)      updateLevel     =false;
    if(updateType)       updateType      =false;
}

void character::setType(std::string name){
    type=name;
    updateType=true;
}

void character::addHealth(float amount){
    healthPoints+=amount;
    if(healthPoints<0) healthPoints=0;
    else if(healthPoints>healthPointsMax) healthPoints=healthPointsMax;
    updateHealth=true;
}

void character::addMana(float amount){
    manaPoints+=amount;
    if(manaPoints<0) manaPoints=0;
    else if(manaPoints>manaPointsMax) manaPoints=manaPointsMax;
    updateMana=true;
}

void character::addExperience(float amount){
    experiencePoints+=amount;
    if(experiencePoints>=experienceRequiredForNextLevel){
        experiencePoints-=experienceRequiredForNextLevel;
        level++;
        updateLevel=true;
    }
    else if(experiencePoints<0){
        experiencePoints+=experienceRequiredForNextLevel;
        level--;
        updateLevel=true;
    }
    updateExperience=true;
}

void character::addStat(std::string statName, int levelBase, int levelAddition){
    character::stat tempStat;
    tempStat.name=statName;
    tempStat.levelBase=levelBase;
    tempStat.levelAddition=0;
    tempStat.levelBase=levelBase;
    stats[0].push_back(tempStat);
    addStatAddition(levelAddition,statName);
}

int character::findStat(std::string statName){
	for (int i = 0; i<(int)stats[0].size(); i++){
		if (stats[0][i].name == statName) return i;
    }
    return -1;
}

void character::addStatAddition(int addition, std::string statName){
    int statId=findStat(statName);
    if(statId!=-1){
        stats[0][statId].levelAddition+=addition;
    }
}