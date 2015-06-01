#ifndef INFO_H
#define INFO_H
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

class info
{
    public:
        info();
        std::vector<int> intInfo;
        std::vector<float> floatInfo;
        std::vector<std::string> stringInfo;
        void addInfo(int info);
        void addInfo(float info);
        void addInfo(std::string info);
};

#endif // INFO_H
