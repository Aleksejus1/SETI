#include "item.h"
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

item::item(){
    reset();
}

bool operator==(item &a, item &b){
    if(a.name==b.name&&a.type==b.type) return true;
    return false;
}

void item::reset(){
    name="empty";
    type="none";
    damage=0;
    affectedStats.clear();
}