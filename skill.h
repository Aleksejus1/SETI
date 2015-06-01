#ifndef SKILL_H
#define SKILL_H
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
