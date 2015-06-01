#include "info.h"
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

info::info()
{
    //ctor
}

void info::addInfo(int info){
    info::intInfo.push_back(info);
}

void info::addInfo(float info){
    info::floatInfo.push_back(info);
}

void info::addInfo(std::string info){
    info::stringInfo.push_back(info);
}