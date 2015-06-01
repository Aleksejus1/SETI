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
        f.addEnemyId("Zombie");
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
        //finished creating maps
        f.ammountOfMaps=maps.size();
        //create battle zones
        createBattleZone("The third map", "Pyramids_So_Real",
                         0,0,   0,0,   320,500,   0,0,   0,0,
                         0,0,   0,0,   0,0,       0,0,   0,0
                         );
        maps[maps.size()-1].createLayer("qpm\\pyramids_secret.png");
        maps[maps.size()-1].createLayer("qpm\\bc3.png");
        maps[maps.size()-1].createLayer("qpm\\pyramids_transparent.png");


        while( !f.quit ) { //Event cycle, does once every game tick
            f.mouseWheelMotion=0; //Reset mouse wheel motion
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
            }
            if(f.player.isInBattle==1){ //instead of this there should be a call to a function which would initiate the battle "Ain't my job"-Aleksejus
                f.player.location.x=maps[f.player.map_location].platforms[2].x;
                f.player.location.y=maps[f.player.map_location].platforms[2].y;
                f.player.isInBattle=2;
            }
            for(int i=1; i<maps[f.player.map_location].layers.size(); i++) f.renderTexture(maps[f.player.map_location].layers[i].texture,maps[f.player.map_location].layers[i].rect,true);
            for(int i=0; i<maps[f.player.map_location].interactable.size(); i++) f.renderTexture(maps[f.player.map_location].interactable[i].texture,maps[f.player.map_location].interactable[i].surface->clip_rect,maps[f.player.map_location].interactable[i].rect);
            f.moveCharacter(f.bordersAreAThing,maps[f.player.map_location].layers[0].surface);
            interact();
            f.renderTexture(f.player.image.texture,f.player.image.rect,f.player.location.x,f.player.location.y);
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
            check=sqrt(pow(f.player.location.x+f.player.image.rect.w/2-
                           maps[f.player.map_location].interactable[i].location.x-maps[f.player.map_location].interactable[i].rect.w/2,2)+
                       pow(f.player.location.y+f.player.image.rect.h/2-
                           maps[f.player.map_location].interactable[i].location.y-maps[f.player.map_location].interactable[i].rect.h/2,2));
            if(check<f.player.image.rect.h/2&&check<smallestDistance){
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
}
