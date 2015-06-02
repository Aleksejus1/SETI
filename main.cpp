#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

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
#include "functions.h"
#include "map.h"

functions f; //Main way of accessing variables and functions in main.cpp
std::vector<map> maps;//Holder for all existing maps in the game

void createMap(std::string name, std::string id);//Adds a new map to the maps variable, requires a long identifier "name" and a short one "id"
void createBattleZone(std::string name, std::string id,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8,int x9,int y9,int x0,int y0);
void interact();//checks for any key-presses that are being searched for and does the corresponding actions
void battle(); //render all enemies and other battle stuffs

int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow){
	if(f.initialize()){//Continue if succeeds to initiate SDL and other modules
        f.loadMedia();//Pre-load images and variables
        //create maps
        createMap("Place holder", "error");
        createMap("The first map ever", "First");
        maps[maps.size()-1].createLayer("qpm\\secret.png");
        maps[maps.size()-1].createLayer("qpm\\bc.png");
        maps[maps.size()-1].createLayer("qpm\\Roks.png");
        maps[maps.size()-1].createInteractable("qpm\\caveEntrance.png",600,400,false);
        maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createEnterEvent(2,320,420);
        maps[maps.size()-1].createInteractable("qpm\\caveEntrance.png",1000,400,false);
        maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createEnterEvent(2,1080,480);
        maps[maps.size()-1].createInteractable("qpm\\battle_trigger.png",300,440,50,50,false);
        //f.addEnemyId("debug_1"); f.addEnemyId("debug_2"); f.addEnemyId("debug_3"); f.addEnemyId("debug_4"); f.addEnemyId("debug_5");
        f.addEnemyId("Zombie"); f.addEnemyId("Zombie"); f.addEnemyId("Zombie_mini"); f.addEnemyId("Zombie"); f.addEnemyId("Zombie");
        maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createBattleEvent(0,f.battleEnemiesIds);
        maps[maps.size()-1].createInteractable("qpm\\battle_trigger.png",160,240,50,50,false);
        maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createEnterEvent(1,320,420);

        createMap("The second map", "Caves");
        maps[maps.size()-1].createLayer("qpm\\secret2.png");
        maps[maps.size()-1].createLayer("qpm\\bc2.png");
        maps[maps.size()-1].createInteractable("qpm\\caveEntrance.png",300,440,false);
        maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createEnterEvent(1,620,380);
        maps[maps.size()-1].createInteractable("qpm\\caveEntrance.png",1060,500,false);
        maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createEnterEvent(1,1020,380);
        maps[maps.size()-1].createGatherable(false,2,0,"shitGathering");
        maps[maps.size()-1].addStage(maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1],-1,true,"qpm\\poop_full.png");
        maps[maps.size()-1].addStage(maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1],2,false,"qpm\\poop_empty.png");
        //finished creating maps
        f.ammountOfMaps=maps.size();
        //create battle zones
        createBattleZone("The third map", "Pyramids_So_Real",
                         0,0,   0,0,   320,500,   0,0,   0,0,
                         786,533,  797,675,  933,597,  1095,558,  1086,666
                         //393,419,   431,456,   315,387,   387,483,   360,519
                         );
        maps[maps.size()-1].createLayer("qpm\\pyramids_secret.png");
        maps[maps.size()-1].createLayer("qpm\\bc3.png");
        maps[maps.size()-1].createLayer("qpm\\pyramids_transparent.png");


        while( !f.quit ) { //Event cycle, does once every game tick
            f.mouseWheelMotion=0; //Reset mouse wheel motion
            f.mouseButton=0; //Reset mouse button
            while(SDL_PollEvent(&f.e)!=0){//Go through all events accumulated in the previous tick
                if(f.e.type==SDL_QUIT){//If program tries to shut down
                    f.quit = true;//Exit the game loop
                }
                else if(f.e.type==SDL_KEYDOWN){//Checks the pressed buttons
                    for(int i=1; i<f.buttons.size(); i++){//Goes through all buttons inside the buttons variable
                        if(f.e.key.keysym.sym==f.buttons[i].keycode){//Checks if the event holding the pressed button is the same as the button that is being checked
                            if(f.buttons[i].pressed==0) f.buttons[i].pressed=1;//If the button is unpressed then mark it as pressed
                            i=f.buttons.size();//Exits the check for this event
                        }
                    }
                }
                else if(f.e.type==SDL_KEYUP){//Checks the unpressed buttons
                    for(int i=1; i<f.buttons.size(); i++){//Goes through all buttons inside the buttons variable
                        if(f.e.key.keysym.sym==f.buttons[i].keycode){//Checks if the event holding the unpressed button is the same as the button that is being checked
                            f.buttons[i].pressed=0;//Marks the button as unpressed
                            i=f.buttons.size();//Exits the check for this event
                        }
                    }
                }
                else if(f.e.type==SDL_MOUSEWHEEL){//Checks if the mouse wheel was used
                    f.mouseWheelMotion=f.e.wheel.y;//Sets the mouse wheel value to it's corresponding one -1 to the used, 1 away from the used
                }
                else if(f.e.type==SDL_MOUSEBUTTONDOWN){//Checks if the mouse button was pressed
                    f.mouseButton=1;
                }
                else if(f.e.type==SDL_MOUSEBUTTONUP){//Checks if the mouse button was unpressed
                    f.mouseButton=2;
                    SDL_GetMouseState(&f.mouse.x,&f.mouse.y);
                }
            }
            for(int i=1; i<maps[f.player.map_location].layers.size(); i++) f.renderTexture(maps[f.player.map_location].layers[i].texture,maps[f.player.map_location].layers[i].surface->clip_rect,maps[f.player.map_location].layers[i].location);
            for(int i=0; i<maps[f.player.map_location].interactable.size(); i++) f.renderTexture(maps[f.player.map_location].interactable[i].texture,maps[f.player.map_location].interactable[i].surface->clip_rect,maps[f.player.map_location].interactable[i].location);
            f.moveCharacter(f.bordersAreAThing,maps[f.player.map_location].layers[0].surface);
            battle();
            interact();
            f.renderTexture(f.player.image.texture,f.player.image.location,f.player.location.x,f.player.location.y);
            f.renderInventory();
            SDL_RenderPresent(f.renderer); // update screen
            SDL_Delay(f.delay); // control frame rate
        }
        f.close(); //Free resources and close SDL
	}//try to initialize if fails, get crash number
    return f.messages.wParam;
}

void createMap(std::string name, std::string id){
    map map_temp(f);
    map_temp.name=name;
    map_temp.id=id;
    for(int i=0; i<1; i++){
        maps.push_back(map_temp);
    }
}

void createBattleZone(std::string name, std::string id,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8,int x9,int y9,int x0,int y0){
    map map_temp(f);
    map_temp.name=name;
    map_temp.id=id;
    SDL_Point location;
    location.x=x1; location.y=y1; map_temp.platforms.push_back(location);
    location.x=x2; location.y=y2; map_temp.platforms.push_back(location);
    location.x=x3; location.y=y3; map_temp.platforms.push_back(location);
    location.x=x4; location.y=y4; map_temp.platforms.push_back(location);
    location.x=x5; location.y=y5; map_temp.platforms.push_back(location);
    location.x=x6; location.y=y6; map_temp.platforms.push_back(location);
    location.x=x7; location.y=y7; map_temp.platforms.push_back(location);
    location.x=x8; location.y=y8; map_temp.platforms.push_back(location);
    location.x=x9; location.y=y9; map_temp.platforms.push_back(location);
    location.x=x0; location.y=y0; map_temp.platforms.push_back(location);
    for(int i=0; i<1; i++){
        maps.push_back(map_temp);
    }
}

void interact(){
    if(f.buttons[f.findButton("E")].pressed==1&&maps[f.player.map_location].interactable.size()>0){
        f.buttons[f.findButton("E")].pressed=2;
        float smallestDistance=pow(10,3);
        float check;
        int id=-1;
        for(int i=0; i<maps[f.player.map_location].interactable.size(); i++){
            check=sqrt(pow(f.player.location.x+f.player.image.location.w/2-
                           maps[f.player.map_location].interactable[i].location.x-maps[f.player.map_location].interactable[i].location.w/2,2)+
                       pow(f.player.location.y+f.player.image.location.h/2-
                           maps[f.player.map_location].interactable[i].location.y-maps[f.player.map_location].interactable[i].location.h/2,2));
            if(check<f.player.image.location.h/2&&check<smallestDistance){
                smallestDistance=check;
                id=i;
            }
        }
        if(id!=-1) f.callEvent(maps[f.player.map_location].interactable[id].events.type, maps[f.player.map_location].interactable[id].events.information);
    }
    if(f.buttons[f.findButton("I")].pressed==1){
        f.buttons[f.findButton("I")].pressed=2;
        f.player.inventory.open=!f.player.inventory.open;
    }
    if(f.buttons[f.findButton("Left Shift")].pressed==1){
        f.player.movementSpeed=f.player.baseMovementSpeed*4;
    }
    else f.player.movementSpeed=f.player.baseMovementSpeed;
    if(f.buttons[f.findButton("N")].pressed==1){
        f.buttons[f.findButton("N")].pressed=2;
        f.bordersAreAThing=!f.bordersAreAThing;
    }
    if(f.buttons[f.findButton("Esc")].pressed==1){
        f.quit=true;
    }
    if(f.buttons[f.findButton("G")].pressed==1){
        f.error(f.toString(f.selectedId+5)+"=["+
                f.toString(maps[f.player.map_location].platforms[f.selectedId+5].x)+";"+
                f.toString(maps[f.player.map_location].platforms[f.selectedId+5].y)+"]");
    }
}

void battle(){
    if(f.player.isInBattle==1){//initialize the battle
        //set player' location
            f.player.location.x=maps[f.player.map_location].platforms[2].x-f.player.image.surface->w/2;
            f.player.location.y=maps[f.player.map_location].platforms[2].y-f.player.image.surface->h;
        //set allies location [allies not yet implemented into the game
        //set enemies locations
            for(int i=0; ((i<f.battleEnemies.size())&&(i<5)); i++){
                f.battleEnemies[i].location.x=maps[f.player.map_location].platforms[i+5].x-f.battleEnemies[i].image.surface->w/2;
                f.battleEnemies[i].location.y=maps[f.player.map_location].platforms[i+5].y-f.battleEnemies[i].image.surface->h;
            }
            f.player.isInBattle=2;
        //done initializing the battle
    }
    if(f.player.isInBattle==2){//battle in progress
        int base=f.findImage("base");
        for(int i=0;((i<f.battleEnemies.size())&&(i<5)); i++){
            if(f.mouseButton==2){
                if(f.pointInsideRect(f.mouse,
                                     f.battleEnemies[i].location.x+f.battleEnemies[i].image.surface->w*f.battleEnemies[i].legCenter.x-f.images[base].image.surface->w/2,
                                     f.battleEnemies[i].location.y+f.battleEnemies[i].image.surface->h*f.battleEnemies[i].legCenter.y-f.images[base].image.surface->h/2,
                                     f.images[base].image.surface->w,
                                     f.images[base].image.surface->h)||
                   f.pointInsideRect(f.mouse,
                                     f.battleEnemies[i].location.x,
                                     f.battleEnemies[i].location.y,
                                     f.battleEnemies[i].image.surface->w,
                                     f.battleEnemies[i].image.surface->h)){
                       f.selectedId=i;
                }
            }
            f.renderTexture(f.images[base].image.texture,
                            f.images[base].image.surface->clip_rect,
                            f.battleEnemies[i].location.x+f.battleEnemies[i].image.surface->w*f.battleEnemies[i].legCenter.x-f.images[base].image.surface->w/2,
                            f.battleEnemies[i].location.y+f.battleEnemies[i].image.surface->h*f.battleEnemies[i].legCenter.y-f.images[base].image.surface->h/2);
            f.renderTexture(f.battleEnemies[i].image.texture,
                            f.battleEnemies[i].image.surface->clip_rect,
                            f.battleEnemies[i].location.x,
                            f.battleEnemies[i].location.y);
        }
        if(f.selectedId!=-1){
            if(f.movePoint(&(maps[f.player.map_location].platforms[f.selectedId+5]),3)) f.player.isInBattle=1;
        }
    }
}

