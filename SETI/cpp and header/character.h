#ifndef CHARACTER_H
#define CHARACTER_H

#include "libs.h"
#include "entity.h"
#include "characterSpace.h"
#include "quest.h"

class functions;

class character: public entity{
    public:
        character(functions* fp);
        float experiencePoints;
        float baseMovementSpeed=1;
        float movementSpeed=baseMovementSpeed;
        float experienceRequiredForNextLevel;
        std::string type;// class/rank of the player
        characterSpace inventory;
        bool updateHealth=true, updateMana=true, updateExperience=true, updateLevel=true, updateType=true;
        int isInBattle=0;
		struct stat{ libs::fo mainBar, additionBar, backgroundBar, gradientBar;
					 std::string name; 
					 int levelBase, levelAddition, levelTotal, additionBarWidth, width[2];
					 layer image, statNameLayer, levelBaseLayer, levelAdditionLayer;
					 bool updateAddition = true, updateName = true, updateLevelBaseLayer=true;
		};
		std::vector<quest> quests;
		std::vector<stat> stats[3];//0-Combat 1-STAT#2 2-STAT#3
        int gathering=0;
        int gatherableId=-1;
        int gatherStartStage=0;
        float gatherTime=0;
        int gatherLevelRequired=0;
        void reset();
        void setType(std::string name);
        void addHealth(float amount);
        void addMana(float amount);
        void addExperience(float amount);
        void addStat(std::string statName, int levelBase, int levelAddition);
        int findStat(std::string statName);
        void addStatAddition(int addition, std::string statName);
};

#endif // CHARACTER_H
