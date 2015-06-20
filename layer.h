#ifndef LAYER_H
#define LAYER_H
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
#include "SDL_opengl.h"
#include "GL\gl.h"
#include "GL\GLU.h"


class layer
{
    public:
        layer();
        SDL_Surface* surface=NULL;
        GLuint textureOpenGL=0;
        float zoom=0,zoomWidth=0,zoomHeight=0;
        SDL_Point location;
        int w=0,h=0;
        void updateSize();
        void setWidthZoom(float number);
        void setHeightZoom(float number);
        void setZoom(float number);
        void free();
        void freeSurface();
        void freeTexture();
};

#endif // LAYER_H
