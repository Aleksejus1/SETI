#ifndef EVENT_H
#define EVENT_H
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
#include "info.h"

class event
{
    public:
        event();
        std::string type;
        info information;
        bool eventCreated=false;
        void createEnterEvent(int mapId, int entranceX, int entranceY);
};

#endif // EVENT_H
