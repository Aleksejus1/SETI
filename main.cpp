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
#include "SDL_opengl.h"
#include "GL\gl.h"
#include "GL\GLU.h"
#include "functionsR.h"

functionsR fR;
functions f(&fR); //Main way of accessing variables and functions in main.cpp
std::vector<map> maps;//Holder for all existing maps in the game

void createMap(std::string name, std::string id);//Adds a new map to the maps variable, requires a long identifier "name" and a short one "id"
void createBattleZone(std::string name, std::string id,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8,int x9,int y9,int x0,int y0);
void interact();//checks for any key-presses that are being searched for and does the corresponding actions
void battle(); //render all enemies and other battle stuffs
void gather();
void regrow();

int WINAPI WinMain (HINSTANCE hThisInstance,HINSTANCE hPrevInstance,LPSTR lpszArgument,int nCmdShow){
    fR.getF(&f);
	if(f.initialize()){//Continue if succeeds to initiate SDL and other modules
        f.loadMedia();//Pre-load images and variables
        if(f.GLStage==f.STAGE_SDL){
        if(true){//create maps
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
            maps[maps.size()-1].createGatherable(500,320,false,1,0,"harvesting");
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].events.createGatherEvent(maps[maps.size()-1].gatherable.size()-1);
            maps[maps.size()-1].addGatherableReturnItemStack(1,f.items[f.findItem("Berry")],maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].addStage(-1,true,true,"qpm\\bush_full.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
                maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
            maps[maps.size()-1].addStage(1,false,false,"qpm\\bush_half.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
                maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
            maps[maps.size()-1].addStage(1,true,false,"qpm\\bush_empty.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
                maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);

            createMap("The second map", "Caves");
            maps[maps.size()-1].createLayer("qpm\\secret2.png");
            maps[maps.size()-1].createLayer("qpm\\bc2.png");
            maps[maps.size()-1].createInteractable("qpm\\caveEntrance.png",300,440,false);
            maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createEnterEvent(1,620,380);
            maps[maps.size()-1].createInteractable("qpm\\caveEntrance.png",1060,500,false);
            maps[maps.size()-1].interactable[maps[maps.size()-1].interactable.size()-1].events.createEnterEvent(1,1020,380);
            maps[maps.size()-1].createGatherable(150,300,false,1,0,"shitGathering");
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].events.createGatherEvent(maps[maps.size()-1].gatherable.size()-1);
            maps[maps.size()-1].addGatherableReturnItemStack(1,f.items[f.findItem("Poop")],maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].addStage(-1,true,true,"qpm\\poop_full.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
            maps[maps.size()-1].addStage(1,false,false,"qpm\\poop_full2.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
            maps[maps.size()-1].addStage(1,false,false,"qpm\\poop_half.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
            maps[maps.size()-1].addStage(1,false,false,"qpm\\poop_half2.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
            maps[maps.size()-1].addStage(1,false,false,"qpm\\poop_empty.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
            maps[maps.size()-1].addStage(1,true,false,"qpm\\poop_empty2.png",maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1]);
            maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.setZoom((float)50/(float)maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages[maps[maps.size()-1].gatherable[maps[maps.size()-1].gatherable.size()-1].stages.size()-1].image.surface->h);
        }
        f.ammountOfMaps=maps.size();
        if(true){//create battle zones
            createBattleZone("The third map", "Pyramids_So_Real",
                             0,0,   0,0,   320,500,   0,0,   0,0,
                             786,533,  797,675,  933,597,  1095,558,  1086,666
                             //393,419,   431,456,   315,387,   387,483,   360,519
                             );
            maps[maps.size()-1].createLayer("qpm\\pyramids_secret.png");
            maps[maps.size()-1].createLayer("qpm\\bc3.png");
            maps[maps.size()-1].createLayer("qpm\\pyramids_transparent.png");
        }
        f.giveItems(f.items[f.findItem("RegularSword")],1);
        }
        while( !f.quit ) { //Event cycle, does once every game tick
            glClear(GL_COLOR_BUFFER_BIT);
            SDL_GetMouseState(&f.mouse.x,&f.mouse.y);
            //read and assign user input events that happened since last activation of this cycle
            while(SDL_PollEvent(&f.e)!=0){//Go through all events accumulated in the previous tick
                if(f.e.type==SDL_QUIT){//If program tries to shut down
                    f.quit = true;//Exit the game loop
                }
                else if(f.e.type==SDL_KEYDOWN){//Checks the pressed buttons
                    for(Uint8 i=1; i<f.buttons.size(); i++){//Goes through all buttons inside the buttons variable
                        if(f.e.key.keysym.sym==f.buttons[i].keycode){//Checks if the event holding the pressed button is the same as the button that is being checked
                            if(f.buttons[i].pressed==0) f.buttons[i].pressed=1;//If the button is unpressed then mark it as pressed
                            i=f.buttons.size();//Exits the check for this event
                        }
                    }
                }
                else if(f.e.type==SDL_KEYUP){//Checks the unpressed buttons
                    for(Uint8 i=1; i<f.buttons.size(); i++){//Goes through all buttons inside the buttons variable
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
                    if(f.e.button.button==SDL_BUTTON_LEFT) f.leftMouseButton=1;
                    else if(f.e.button.button==SDL_BUTTON_RIGHT) f.rightMouseButton=1;
                    f.mouseButton=1;
                }
                else if(f.e.type==SDL_MOUSEBUTTONUP){//Checks if the mouse button was unpressed
                    if(f.e.button.button==SDL_BUTTON_LEFT) f.leftMouseButtonUp=1;
                    else if(f.e.button.button==SDL_BUTTON_RIGHT) f.rightMouseButtonUp=1;
                    f.mouseButton=2;
                }
            }
            interact();
            //finish handling user input
            //-------------------------------------
            if(f.GLStage==f.STAGE_SDL){
            //render Map Details
            for(Uint8 i=1; i<maps[f.player.map_location].layers.size(); i++) f.renderTexture(&maps[f.player.map_location].layers[i],maps[f.player.map_location].layers[i].surface->clip_rect);
            for(Uint8 i=0; i<maps[f.player.map_location].interactable.size(); i++) f.renderTexture(&maps[f.player.map_location].interactable[i],maps[f.player.map_location].interactable[i].surface->clip_rect,maps[f.player.map_location].interactable[i].location.x,maps[f.player.map_location].interactable[i].location.y,maps[f.player.map_location].interactable[i].surface->w,maps[f.player.map_location].interactable[i].surface->h);
            for(Uint8 i=0; i<maps[f.player.map_location].gatherable.size(); i++) f.renderTexture(&maps[f.player.map_location].gatherable[i].stages[maps[f.player.map_location].gatherable[i].currentStage].image,maps[f.player.map_location].gatherable[i].stages[maps[f.player.map_location].gatherable[i].currentStage].image.surface->clip_rect,maps[f.player.map_location].gatherable[i].location.x,maps[f.player.map_location].gatherable[i].location.y);
            //finish rendering map details
            //--------------------------------------
            //Allow user to control what's happening
            if(f.player.gathering!=0) gather();
            else if(f.player.isInBattle!=0) battle();
            else{
                f.moveCharacter(f.bordersAreAThing,maps[f.player.map_location].layers[0].surface);
                regrow();
            }
            //finish user actions
            //---------------------------------------
            //render render player character
            f.renderTexture(&f.player.image,f.player.image.surface->clip_rect,f.player.location.x,f.player.location.y);
            //finish rendering player
            //---------------------------------------
            //render UI
            f.renderUI();
            //finish rendering UI elements
            //---------------------------------------
            //SDL_RenderPresent(f.renderer); // update screen
            SDL_GL_SwapWindow(f.window);
            //finish up this game tick
            }
            else{
                glClear(GL_COLOR_BUFFER_BIT);
                f.renderTexture(&f.imageOpenGL,f.imageOpenGL.surface->clip_rect,-f.imageOpenGL2.surface->w/3,0,f.imageOpenGL.surface->w/2,f.imageOpenGL.surface->h/2);
                f.renderTexture(&f.imageOpenGL2,f.imageOpenGL2.surface->w/2,f.imageOpenGL2.surface->h/2,f.imageOpenGL2.surface->w/2,f.imageOpenGL2.surface->h/2,0,0);
                SDL_GL_SwapWindow(f.window);
            }
            SDL_Delay(f.delay); // control frame rate
            f.reset();
            //end of game tick
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
    if(f.buttons[f.findButton("E")].pressed==1&&maps[f.player.map_location].interactable.size()>0&&f.player.gathering==0){
        f.buttons[f.findButton("E")].pressed=2;
        float smallestDistance=pow(10,3);
        float check;
        int id=-1;
        for(Uint8 i=0; i<maps[f.player.map_location].interactable.size(); i++){
            check=sqrt(pow(f.player.location.x+f.player.image.w/2-
                           maps[f.player.map_location].interactable[i].location.x-maps[f.player.map_location].interactable[i].w/2,2)+
                       pow(f.player.location.y+f.player.image.h/2-
                           maps[f.player.map_location].interactable[i].location.y-maps[f.player.map_location].interactable[i].h/2,2));
            /*f.error(f.toString(check)+"=sqrt(pow("+
                    f.toString(f.player.location.x)+"+"+
                    f.toString(f.player.image.w)+"/2-"+
                    f.toString(maps[f.player.map_location].interactable[i].location.x)+"-"+
                    f.toString(maps[f.player.map_location].interactable[i].w)+"/2,2)+pow("+
                    f.toString(f.player.location.y)+"+"+
                    f.toString(f.player.image.h)+"/2-"+
                    f.toString(maps[f.player.map_location].interactable[i].location.y)+"-"+
                    f.toString(maps[f.player.map_location].interactable[i].h)+"/2,2)");
                    */
            if(check<f.player.image.h/2&&check<smallestDistance){
                smallestDistance=check;
                id=i;
            }
        }
        if(id!=-1) f.callEvent(maps[f.player.map_location].interactable[id].events.type, maps[f.player.map_location].interactable[id].events.information);
        else{
            for(Uint8 i=0; i<maps[f.player.map_location].gatherable.size(); i++){
                if(maps[f.player.map_location].gatherable[i].stages[maps[f.player.map_location].gatherable[i].currentStage].isItGatherable){
                    check=sqrt(pow(f.player.location.x+f.player.image.w/2-
                                   maps[f.player.map_location].gatherable[i].location.x-
                                   maps[f.player.map_location].gatherable[i].stages[maps[f.player.map_location].gatherable[i].currentStage].image.w/2,2)+
                               pow(f.player.location.y+f.player.image.h/2-
                                   maps[f.player.map_location].gatherable[i].location.y-
                                   maps[f.player.map_location].gatherable[i].stages[maps[f.player.map_location].gatherable[i].currentStage].image.h/2,2));
                    /*f.error(f.toString(check)+"=sqrt(pow("+
                            f.toString(f.player.location.x)+"+"+
                            f.toString(f.player.image.w)+"/2-"+
                            f.toString(maps[f.player.map_location].gatherable[i].location.x)+"-"+
                            f.toString(maps[f.player.map_location].gatherable[i].stages[maps[f.player.map_location].gatherable[i].currentStage].image.w)+"/2,2)+pow("+
                            f.toString(f.player.location.y)+"+"+
                            f.toString(f.player.image.h)+"/2-"+
                            f.toString(maps[f.player.map_location].gatherable[i].location.y)+"-"+
                            f.toString(maps[f.player.map_location].gatherable[i].stages[maps[f.player.map_location].gatherable[i].currentStage].image.h)+"/2,2)");
                            */
                    if(check<f.player.image.h/2&&check<smallestDistance){
                        smallestDistance=check;
                        id=i;
                    }
                }
            }
            if(id!=-1) f.callEvent(maps[f.player.map_location].gatherable[id].events.type, maps[f.player.map_location].gatherable[id].events.information);
        }
    }
    if(f.buttons[f.findButton("I")].pressed==1){
        f.buttons[f.findButton("I")].pressed=2;
        f.player.inventory.open=!f.player.inventory.open;
        f.player.inventory.update=true;
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
        f.player.addHealth(-2);
        f.player.addMana(2);
        f.player.addExperience(100);
    }
    if(f.buttons[f.findButton("Z")].pressed==1){
        f.error("["+f.toString(f.battleEnemies[0].location.x)+";"+f.toString(f.battleEnemies[0].location.y)+"]=0\n"+
                "["+f.toString(f.battleEnemies[1].location.x)+";"+f.toString(f.battleEnemies[1].location.y)+"]=1\n"+
                "["+f.toString(f.battleEnemies[2].location.x)+";"+f.toString(f.battleEnemies[2].location.y)+"]=2\n"+
                "["+f.toString(f.battleEnemies[3].location.x)+";"+f.toString(f.battleEnemies[3].location.y)+"]=3\n"+
                "["+f.toString(f.battleEnemies[4].location.x)+";"+f.toString(f.battleEnemies[4].location.y)+"]=4\n"+
                "selected="+f.toString(f.selectedId));
    }
    if(f.buttons[f.findButton("Q")].pressed==1){
        //f.buttons[f.findButton("Q")].pressed=0;
        f.rotationAngle+=360.f/f.FPS/4.f;
        if(f.rotationAngle>360.f) f.rotationAngle-=360.f;
    }
    if(f.buttons[f.findButton("R")].pressed==1){
        f.buttons[f.findButton("R")].pressed=0;
        if(f.moveObject==f.OBJECT_PLAYER) f.moveObject=f.OBJECT_SCREEN;
        else f.moveObject=f.OBJECT_PLAYER;
    }
}
void battle(){
    if(f.player.isInBattle==1){//initialize the battle
        //set player' location
            f.player.location.x=maps[f.player.map_location].platforms[2].x-f.player.image.w/2;
            f.player.location.y=maps[f.player.map_location].platforms[2].y-f.player.image.h;
        //set allies location [allies not yet implemented into the game
        //set enemies locations
            for(Uint8 i=0; ((i<f.battleEnemies.size())&&(i<5)); i++){
                f.battleEnemies[i].location.x=maps[f.player.map_location].platforms[i+5].x-f.battleEnemies[i].image.w/2;
                f.battleEnemies[i].location.y=maps[f.player.map_location].platforms[i+5].y-f.battleEnemies[i].image.h;
            }
            f.player.isInBattle=2;
        //done initializing the battle
    }
    if(f.player.isInBattle==2){//battle in progress
        int base=f.findImage("base");
        for(Uint8 i=0;((i<f.battleEnemies.size())&&(i<5)); i++){
            if(f.mouseButton==2){
                if(f.pointInsideRect(f.mouse,f.getRect(f.battleEnemies[i].location.x+f.battleEnemies[i].image.surface->w*f.battleEnemies[i].legCenter.x-f.images[base].image.surface->w/2,f.battleEnemies[i].location.y+f.battleEnemies[i].image.surface->h*f.battleEnemies[i].legCenter.y-f.images[base].image.surface->h/2,f.images[base].image.surface->w,f.images[base].image.surface->h))||
                   f.pointInsideRect(f.mouse,f.getRect(f.battleEnemies[i].location.x,f.battleEnemies[i].location.y,f.battleEnemies[i].image.surface->w,f.battleEnemies[i].image.surface->h))){
                       f.selectedId=i;
                }
            }
            f.renderTexture(&f.images[base].image,f.images[base].image.surface->clip_rect,f.battleEnemies[i].location.x+f.battleEnemies[i].image.w*f.battleEnemies[i].legCenter.x-f.images[base].image.w/2,f.battleEnemies[i].location.y+f.battleEnemies[i].image.h*f.battleEnemies[i].legCenter.y-f.images[base].image.h/2);
            f.renderTexture(&f.battleEnemies[i].image,f.battleEnemies[i].image.surface->clip_rect,f.battleEnemies[i].location.x,f.battleEnemies[i].location.y);
        }
        if(f.selectedId!=-1){
            if(f.movePoint(&(maps[f.player.map_location].platforms[f.selectedId+5]),3)) f.player.isInBattle=1;
        }
        int battleUI=f.findImage("battleUI");
        f.renderTexture(&f.images[battleUI].image,f.images[battleUI].image.surface->clip_rect,0,(f.SCREEN_HEIGHT-f.images[battleUI].image.h));
        for(int i = 0; i < 4; i++)
        {
             f.renderTexture(&f.Spells[0].icon_active,f.Spells[0].icon_active.surface->clip_rect, 615+i*57, 645);
             if(f.pointInsideRect(f.mouse,f.getRect(615, 645, 50, 50))&&((f.leftMouseButton==1)||(f.leftMouseButton==2)))
             {
                 f.leftMouseButton=2;
                 int *x,*y;
                 f.renderTexture(&f.Spells[0].icon_cooldown,f.Spells[0].icon_cooldown.surface->clip_rect, 615, 645);

             }
        }

    }
}
void gather(){
    if(f.player.gathering==1){//initialize gathering
        f.player.gatherTime=maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime;
        f.player.gathering=2;
        f.player.gatherStartStage=maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage;
    }
    if(f.player.gathering==2){//render and calculate the process bar of gathering
        f.player.gatherTime-=(float)(1)/f.FPS;
        if((1-f.player.gatherTime/maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime)>=(float)1/(f.findNextStage(maps[f.player.map_location].gatherable[f.player.gatherableId].stages,maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage)-f.player.gatherStartStage)){
           maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage=f.player.gatherStartStage+(int)(((1-f.player.gatherTime/maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime))/((float)1/(f.findNextStage(maps[f.player.map_location].gatherable[f.player.gatherableId].stages,maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage)-f.player.gatherStartStage)));
        }
        f.renderTexture(&f.images[f.findImage("progressBarFrame")].image,f.images[f.findImage("progressBarFrame")].image.surface->clip_rect,(f.SCREEN_WIDTH-f.images[f.findImage("progressBarFrame")].image.surface->w)/2,f.SCREEN_HEIGHT-f.images[f.findImage("progressBarFrame")].image.surface->h-20);
        f.renderTexture(&f.images[f.findImage("progressBarInside")].image,0,0,f.images[f.findImage("progressBarInside")].image.surface->w*(1-f.player.gatherTime/maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime),f.images[f.findImage("progressBarInside")].image.surface->h,(f.SCREEN_WIDTH-f.images[f.findImage("progressBarFrame")].image.surface->w)/2,f.SCREEN_HEIGHT-f.images[f.findImage("progressBarFrame")].image.surface->h-20);
        if(f.player.gatherTime<=0){
            f.player.gatherTime=0;
            for(Uint8 i=0; i<maps[f.player.map_location].gatherable[f.player.gatherableId].returnItems.size(); i++){
                f.giveItems(maps[f.player.map_location].gatherable[f.player.gatherableId].returnItems[i]);
            }
            maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage=f.findNextStage(maps[f.player.map_location].gatherable[f.player.gatherableId].stages,f.player.gatherStartStage);
            maps[f.player.map_location].gatherable[f.player.gatherableId].timeUntilRegrow=maps[f.player.map_location].gatherable[f.player.gatherableId].stages[maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage].timeUntilNextStage;
            f.player.gathering=0;
        }
    }
}
void regrow(){
    for(int i=0; i<maps.size(); i++){
        for(int o=0; o<maps[i].gatherable.size(); o++){
            if(maps[i].gatherable[o].currentStage!=0){
                maps[i].gatherable[o].timeUntilRegrow-=(float)(1)/f.FPS;
                if(maps[i].gatherable[o].timeUntilRegrow<=0){
                    maps[i].gatherable[o].currentStage--;
                    maps[i].gatherable[o].timeUntilRegrow=maps[i].gatherable[o].stages[maps[i].gatherable[o].currentStage].timeUntilNextStage;
                }
            }
        }
    }
}
