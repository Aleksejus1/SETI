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

layer::layer()
{
    //ctor
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
    if(layer::texture!=NULL){
        SDL_DestroyTexture(layer::texture); layer::texture=NULL;
    }
}