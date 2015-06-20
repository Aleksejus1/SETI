#include "layer.h"
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

layer::layer(){
    setZoom(1);
    setWidthZoom(1);
    setHeightZoom(1);
}

void layer::updateSize(){
    if(surface!=NULL){
        w=surface->w*zoom*zoomWidth;
        h=surface->h*zoom*zoomHeight;
    }
}

void layer::setZoom(float number){
    zoom=number;
    updateSize();
}

void layer::setWidthZoom(float number){
    zoomWidth=number;
    updateSize();
}

void layer::setHeightZoom(float number){
    zoomHeight=number;
    updateSize();
}

void layer::free(){
    layer::freeSurface();
    layer::freeTexture();
}

void layer::freeSurface(){
    if(layer::surface!=NULL){
        SDL_FreeSurface(layer::surface); layer::surface=NULL;
    }
}

void layer::freeTexture(){
    if(textureOpenGL!=0){
        glDeleteTextures(1,&textureOpenGL);
        textureOpenGL=0;
    }
}