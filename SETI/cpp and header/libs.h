#ifndef LIBS_H
#define LIBS_H
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
//#include <dirent.h>
//#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <commdlg.h>
#include "SDL2_rotozoom.h"
#include "SDL_opengl.h"
#include "GL\gl.h"
#include "GL\GLU.h"
#include <cstdlib>

class libs{
    public:
        libs();
        struct fo{SDL_Rect from,to;};
};

#endif // LIBS_H
