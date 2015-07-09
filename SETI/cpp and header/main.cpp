#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include "libs.h"
#include "functions.h"
#include "map.h"

functions f; //Main way of accessing variables and functions in main.cpp

void createMap(std::string name, std::string id);//Adds a new map to the maps variable, requires a long identifier "name" and a short one "id"
//void createBattleZone(std::string name, std::string id,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8,int x9,int y9,int x0,int y0);
void interact();//checks for any key-presses that are being searched for and does the corresponding actions
void battle(); //render all enemies and other battle stuffs
void gather();
void regrow();

int main(int argc, char **argv){
	if(f.initialize()){//Continue if succeeds to initiate SDL and other modules
        f.loadMedia();//Pre-load images and variables
        if(f.GLStage==f.STAGE_SDL){
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
            if(f.currentMenu==f.MENU_GAME){

            //render Map Details
            for(Uint8 i=1; i<f.maps[f.player.map_location].layers.size(); i++) f.renderTexture(&f.maps[f.player.map_location].layers[i],f.maps[f.player.map_location].layers[i].surface->clip_rect);
            for(Uint8 i=0; i<f.maps[f.player.map_location].interactable.size(); i++) f.renderTexture(&f.maps[f.player.map_location].interactable[i],f.maps[f.player.map_location].interactable[i].surface->clip_rect,f.maps[f.player.map_location].interactable[i].location.x,f.maps[f.player.map_location].interactable[i].location.y,f.maps[f.player.map_location].interactable[i].surface->w,f.maps[f.player.map_location].interactable[i].surface->h);
            for(Uint8 i=0; i<f.maps[f.player.map_location].gatherable.size(); i++) f.renderTexture(&f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].image,f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].image.surface->clip_rect,f.maps[f.player.map_location].gatherable[i].location.x,f.maps[f.player.map_location].gatherable[i].location.y);
            //finish rendering map details
            //--------------------------------------
            //Allow user to control what's happening
            if(f.player.gathering!=0) gather();
            else if(f.player.isInBattle!=0) battle();
            else{
                f.moveCharacter(f.bordersAreAThing,f.maps[f.player.map_location].layers[0].surface);
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
            }
            else if(f.currentMenu==f.MENU_START){
                f.menuTxl.renderTextures();
                f.renderFlameParticles();
            }
            //SDL_RenderPresent(f.renderer); // update screen
            SDL_GL_SwapWindow(f.window);
            f.console();
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
void interact(){
    if(f.buttons[f.findButton("Esc")].pressed==1){
        f.quit=true;
    }
    if(f.buttons[f.findButton("Z")].pressed==1){
        f.buttons[f.findButton("Z")].pressed=0;
        f.consoleOnce[0]=true;
        f.consoleShow=!f.consoleShow;
    }
    if(f.currentMenu==f.MENU_GAME){
    if(f.buttons[f.findButton("E")].pressed==1&&f.maps[f.player.map_location].interactable.size()>0&&f.player.gathering==0){
        f.buttons[f.findButton("E")].pressed=2;
        float smallestDistance=pow(10.f,3.f);
        float check;
        int id=-1;
        for(Uint8 i=0; i<f.maps[f.player.map_location].interactable.size(); i++){
            check=sqrt((float)pow(f.player.location.x+f.player.image.w/2-
                       f.maps[f.player.map_location].interactable[i].location.x-f.maps[f.player.map_location].interactable[i].w/2,2)+
                       (float)pow(f.player.location.y+f.player.image.h/2-
                       f.maps[f.player.map_location].interactable[i].location.y-f.maps[f.player.map_location].interactable[i].h/2.f,2));
            /*f.error(f.toString(check)+"=sqrt(pow("+
                    f.toString(f.player.location.x)+"+"+
                    f.toString(f.player.image.w)+"/2-"+
                    f.toString(f.maps[f.player.map_location].interactable[i].location.x)+"-"+
                    f.toString(f.maps[f.player.map_location].interactable[i].w)+"/2,2)+pow("+
                    f.toString(f.player.location.y)+"+"+
                    f.toString(f.player.image.h)+"/2-"+
                    f.toString(f.maps[f.player.map_location].interactable[i].location.y)+"-"+
                    f.toString(f.maps[f.player.map_location].interactable[i].h)+"/2,2)");
                    */
            if(check<f.player.image.h/2&&check<smallestDistance){
                smallestDistance=check;
                id=i;
            }
        }
        if(id!=-1) f.callEvent(f.maps[f.player.map_location].interactable[id].events.type, f.maps[f.player.map_location].interactable[id].events.information);
        else{
            for(Uint8 i=0; i<f.maps[f.player.map_location].gatherable.size(); i++){
                if(f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].isItGatherable){
					check = sqrt((float)pow(f.player.location.x + f.player.image.w / 2 -
                                 f.maps[f.player.map_location].gatherable[i].location.x-
                                 f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].image.w/2,2)+
								 (float)pow(f.player.location.y + f.player.image.h / 2 -
                                 f.maps[f.player.map_location].gatherable[i].location.y-
                                 f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].image.h/2,2));
                    /*f.error(f.toString(check)+"=sqrt(pow("+
                            f.toString(f.player.location.x)+"+"+
                            f.toString(f.player.image.w)+"/2-"+
                            f.toString(f.maps[f.player.map_location].gatherable[i].location.x)+"-"+
                            f.toString(f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].image.w)+"/2,2)+pow("+
                            f.toString(f.player.location.y)+"+"+
                            f.toString(f.player.image.h)+"/2-"+
                            f.toString(f.maps[f.player.map_location].gatherable[i].location.y)+"-"+
                            f.toString(f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].image.h)+"/2,2)");
                            */
                    if(check<f.player.image.h/2&&check<smallestDistance){
                        smallestDistance=check;
                        id=i;
                    }
                }
            }
            if(id!=-1) f.callEvent(f.maps[f.player.map_location].gatherable[id].events.type, f.maps[f.player.map_location].gatherable[id].events.information);
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
    if(f.buttons[f.findButton("G")].pressed==1){
        f.buttons[f.findButton("G")].pressed=0;
        if(f.buttons[f.findButton("Left Shift")].pressed==1) f.player.stats[0].levelBase--;
        else f.player.stats[0].levelBase++;
        f.player.stats[0].update=true;
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
    else if(f.currentMenu==f.MENU_START){
        if(f.leftMouseButton||f.leftMouseButtonUp){
            Texolder& txl=f.menuTxl; SDL_Point location; Texolder::TH* THp; std::string buttonName; bool checkAlpha; variables::buttn* buttonp;
            for(int i=0; i<4&&(f.leftMouseButton||f.leftMouseButtonUp); i++){
                switch(i){
                    case 0: buttonName="close";   checkAlpha=true;  buttonp=&f.menu.close;   break;
                    case 1: buttonName="play";    checkAlpha=false; buttonp=&f.menu.play;    break;
                    case 2: buttonName="options"; checkAlpha=false; buttonp=&f.menu.options; break;
                    case 3: buttonName="about";   checkAlpha=false; buttonp=&f.menu.about;   break;
                }
                buttonName="button "+buttonName;
                THp=&txl.texture[txl.findTexture(buttonName)];
                location.x=txl.getLocationX(THp); location.y=txl.getLocationY(THp);
                if(f.pointInsideRect(f.mouse,f.getRect(location.x,location.y,THp->to->w,THp->to->h))&&(!checkAlpha||f.getColorAlpha(f.getPixelColors(THp->layerp->surface,f.mouse.x-location.x,f.mouse.y-location.y))!=0)){
                    if(f.leftMouseButtonUp&&f.clickedOn==buttonName){
                        switch(i){
                            case 0: f.quit=true; break;
                            case 1: f.currentMenu=f.MENU_GAME; break;
                            case 2: f.error("options"); break;
                            case 3: f.error("about"); break;
                        }
                        f.leftMouseButtonUp=false;
                        THp->layerp=&buttonp->button[0];
                        f.clickedOn="";
                    }
                    if(f.leftMouseButton&&f.clickedOn==""){
                        f.leftMouseButton=false;
                        THp->layerp=&buttonp->button[1];
                        f.clickedOn=buttonName;
                    }
                }
                else{
                    if(f.leftMouseButtonUp&&f.clickedOn==buttonName){
                        f.leftMouseButtonUp=false;
                        THp->layerp=&buttonp->button[0];
                        f.clickedOn="";
                    }
                }
            }
        }
    }
}
void battle(){
    if(f.player.isInBattle==1){//initialize the battle
        //set player' location
            f.player.location.x=f.maps[f.player.map_location].platforms[2].x-f.player.image.w/2;
            f.player.location.y=f.maps[f.player.map_location].platforms[2].y-f.player.image.h;
        //set allies location [allies not yet implemented into the game
        //set enemies locations
            for(Uint8 i=0; ((i<f.battleEnemies.size())&&(i<5)); i++){
                f.battleEnemies[i].location.x=f.maps[f.player.map_location].platforms[i+5].x-f.battleEnemies[i].image.w/2;
                f.battleEnemies[i].location.y=f.maps[f.player.map_location].platforms[i+5].y-f.battleEnemies[i].image.h;
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
            if(f.movePoint(&(f.maps[f.player.map_location].platforms[f.selectedId+5]),3)) f.player.isInBattle=1;
        }
        int battleUI=f.findImage("battleUI");
        f.renderTexture(&f.images[battleUI].image,f.images[battleUI].image.surface->clip_rect,0,(f.SCREEN_HEIGHT-f.images[battleUI].image.h));
        for(int i = 0; i < 4; i++){
             f.renderTexture(&f.Spells[0].icon_active,f.Spells[0].icon_active.surface->clip_rect, 615+i*57, 645);
             if(f.pointInsideRect(f.mouse,f.getRect(615, 645, 50, 50))&&((f.leftMouseButton==1)||(f.leftMouseButton==2))){
                 f.leftMouseButton=2;
                 f.renderTexture(&f.Spells[0].icon_cooldown,f.Spells[0].icon_cooldown.surface->clip_rect, 615, 645);
             }
        }

    }
}
void gather(){
    if(f.player.gathering==1){//initialize gathering
        f.player.gatherTime=f.maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime;
        f.player.gathering=2;
        f.player.gatherStartStage=f.maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage;
    }
    if(f.player.gathering==2){//render and calculate the process bar of gathering
        f.player.gatherTime-=(float)(1)/f.FPS;
        if((1-f.player.gatherTime/f.maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime)>=(float)1/(f.findNextStage(f.maps[f.player.map_location].gatherable[f.player.gatherableId].stages,f.maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage)-f.player.gatherStartStage)){
           f.maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage=f.player.gatherStartStage+(int)(((1-f.player.gatherTime/f.maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime))/((float)1/(f.findNextStage(f.maps[f.player.map_location].gatherable[f.player.gatherableId].stages,f.maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage)-f.player.gatherStartStage)));
        }
        f.renderTexture(&f.images[f.findImage("progressBarFrame")].image,f.images[f.findImage("progressBarFrame")].image.surface->clip_rect,(f.SCREEN_WIDTH-f.images[f.findImage("progressBarFrame")].image.surface->w)/2,f.SCREEN_HEIGHT-f.images[f.findImage("progressBarFrame")].image.surface->h-20);
        f.renderTexture(&f.images[f.findImage("progressBarInside")].image,0,0,f.images[f.findImage("progressBarInside")].image.surface->w*(1-f.player.gatherTime/f.maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime),f.images[f.findImage("progressBarInside")].image.surface->h,(f.SCREEN_WIDTH-f.images[f.findImage("progressBarFrame")].image.surface->w)/2,f.SCREEN_HEIGHT-f.images[f.findImage("progressBarFrame")].image.surface->h-20);
        if(f.player.gatherTime<=0){
            f.player.gatherTime=0;
            for(Uint8 i=0; i<f.maps[f.player.map_location].gatherable[f.player.gatherableId].returnItems.size(); i++){
                f.giveItems(f.maps[f.player.map_location].gatherable[f.player.gatherableId].returnItems[i]);
            }
            f.maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage=f.findNextStage(f.maps[f.player.map_location].gatherable[f.player.gatherableId].stages,f.player.gatherStartStage);
            f.maps[f.player.map_location].gatherable[f.player.gatherableId].timeUntilRegrow=f.maps[f.player.map_location].gatherable[f.player.gatherableId].stages[f.maps[f.player.map_location].gatherable[f.player.gatherableId].currentStage].timeUntilNextStage;
            f.player.gathering=0;
        }
    }
}
void regrow(){
    for(int i=0; i<(int)f.maps.size(); i++){
        for(int o=0; o<(int)f.maps[i].gatherable.size(); o++){
            if(f.maps[i].gatherable[o].currentStage!=0){
                f.maps[i].gatherable[o].timeUntilRegrow-=(float)(1)/f.FPS;
                if(f.maps[i].gatherable[o].timeUntilRegrow<=0){
                    f.maps[i].gatherable[o].currentStage--;
                    f.maps[i].gatherable[o].timeUntilRegrow=f.maps[i].gatherable[o].stages[f.maps[i].gatherable[o].currentStage].timeUntilNextStage;
                }
            }
        }
    }
}
