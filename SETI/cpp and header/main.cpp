#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include "libs.h"
#include "functions.h"
#include "map.h"

functions f; //Main way of accessing variables and functions in main.cpp

void interact_();//checks for any key-presses that are being searched for and does the corresponding actions
void battle_(); //render all enemies and other battle stuffs
void gather_();
void regrow_();

int main(int argc, char **argv){
	if (!f.initialize()) goto exit;//try to initialize SDL if fails, quit the program
    f.loadMedia();//Pre-load images and variables
    if(f.GLStage==f.STAGE_SDL){//give items for testing
        f.giveItems(f.items[f.findItem("RegularSword")],1);
		f.giveItems(f.items[f.findItem("RegularSword")], 1, f.player.inventory.itemStacks[37].ist);
	}
	//init before first frame 
	glClear(GL_COLOR_BUFFER_BIT
		| GL_DEPTH_BUFFER_BIT
		);
	SDL_GetMouseState(&f.mouse.x, &f.mouse.y);
    while( !f.quit ) { //Event cycle, does once every game tick
        //read and assign user input events that happened since last activation of this cycle
		f.milisecond = SDL_GetTicks();
		while(SDL_PollEvent(&f.e)!=0){//Go through all events accumulated in the previous tick
            if(f.e.type==SDL_QUIT){//If program tries to shut down
                f.quit = true;//Exit the game loop
            }
            else if(f.e.type==SDL_KEYDOWN){//Checks the pressed buttons
				for (keyboard& n: f.buttons){//Goes through all buttons inside the buttons variable
                    if(f.e.key.keysym.sym==n.keycode){//Checks if the event holding the pressed button is the same as the button that is being checked
                        if(n.pressed==0) n.pressed=1;//If the button is unpressed then mark it as pressed
						goto quitLookingForPressedButtons;//Exits the check for this event
                    }
				quitLookingForPressedButtons:;
                }
            }
            else if(f.e.type==SDL_KEYUP){//Checks the unpressed buttons
				for (keyboard& n : f.buttons){//Goes through all buttons inside the buttons variable
                    if(f.e.key.keysym.sym==n.keycode){//Checks if the event holding the unpressed button is the same as the button that is being checked
                        n.pressed=0;//Marks the button as unpressed
						goto quitLookingForUnpressedButtons;//Exits the check for this event
					}
				quitLookingForUnpressedButtons:;
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
		interact_();
        //finish handling user input
        //-------------------------------------
        if(f.GLStage==f.STAGE_SDL){
        if(f.currentMenu==f.MENU_GAME){

        //render Map Details
		for (Uint8 i = 1; i < f.maps[f.player.map_location].layers.size(); i++){
			layer &n = f.maps[f.player.map_location].layers[i];
			f.renderTexture(&n, n.surface->clip_rect);
		}
		for (layer& n : f.maps[f.player.map_location].interactable) f.renderTexture(&n,n.surface->clip_rect,f.getRect(n.offset,n.surface->w,n.surface->h));
		for (gather& n : f.maps[f.player.map_location].gatherable) f.renderTexture(&n.stages[n.currentStage].image,n.stages[n.currentStage].image.surface->clip_rect,n.offset);
		//finish rendering map details
        /*--------------------------------------*/
        //Allow user to control what's happening
        if(f.player.gathering!=0) gather();
		else if (f.player.isInBattle != 0) battle_();
        else{
            f.moveCharacter(f.bordersAreAThing,f.maps[f.player.map_location].layers[0].surface);
			regrow_();
        }
        //finish user actions
        //---------------------------------------
        //render render player character
        f.renderTexture(&f.player.image,f.player.image.surface->clip_rect,f.player.location);

        //finish rendering player
        //---------------------------------------
        //render UI
        f.renderUI();
        //finish rendering UI elements
        //---------------------------------------
        }
        else if(f.currentMenu==f.MENU_START){
			f.renderMenuPulse();
            f.menuTxl.renderTextures();
			f.renderFlameParticles();
		}
		f.controlMusic();
		f.renderTexture(&f.cursorImage, f.cursorImage.surface->clip_rect, f.mouse);
        //SDL_RenderPresent(f.renderer); // update screen
		SDL_GL_SwapWindow(f.window);
        //finish up this game tick
        }
        else{
            glClear(GL_COLOR_BUFFER_BIT);
            f.renderTexture(&f.imageOpenGL,f.imageOpenGL.surface->clip_rect,f.getRect(-f.imageOpenGL2.surface->w/3,0,f.imageOpenGL.surface->w/2,f.imageOpenGL.surface->h/2));
            f.renderTexture(&f.imageOpenGL2,f.getRect(f.imageOpenGL2.surface->w/2,f.imageOpenGL2.surface->h/2,f.imageOpenGL2.surface->w/2,f.imageOpenGL2.surface->h/2),f.getPoint(0,0));
            SDL_GL_SwapWindow(f.window);
        }
		f.milisecondOffset = (float)(SDL_GetTicks() - f.milisecond);
		if (f.milisecondOffset > f.delay) f.milisecondOffset = f.delay;
		SDL_Delay((Uint32)(f.delay - f.milisecondOffset)); // control frame rate
        /*end of game tick*/
		f.reset();//initialize the new frame
    }
    f.close(); //Free resources and close SDL
	exit:
    return f.messages.wParam;
}
void interact_(){
    if(f.buttons[f.findButton("Esc")].pressed==1){
        f.quit=true;
    }
    if(f.currentMenu==f.MENU_GAME){
    if(f.buttons[f.findButton("E")].pressed==1&&f.maps[f.player.map_location].interactable.size()>0&&f.player.gathering==0){
        f.buttons[f.findButton("E")].pressed=2;
        float smallestDistance=pow(10.f,3.f);
        float check;
        int id=-1;
        for(Uint8 i=0; i<f.maps[f.player.map_location].interactable.size(); i++){
            check=sqrt((float)pow(f.player.location.x+f.player.image.w/2-
                       f.maps[f.player.map_location].interactable[i].offset.x-f.maps[f.player.map_location].interactable[i].w/2,2)+
                       (float)pow(f.player.location.y+f.player.image.h/2-
					   f.maps[f.player.map_location].interactable[i].offset.y - f.maps[f.player.map_location].interactable[i].h / 2.f, 2));
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
						f.maps[f.player.map_location].gatherable[i].offset.x -
                                 f.maps[f.player.map_location].gatherable[i].stages[f.maps[f.player.map_location].gatherable[i].currentStage].image.w/2,2)+
								 (float)pow(f.player.location.y + f.player.image.h / 2 -
								 f.maps[f.player.map_location].gatherable[i].offset.y -
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
	if (f.buttons[f.findButton("I")].pressed == 1){
		f.buttons[f.findButton("I")].pressed = 2;
		f.player.inventory.open = !f.player.inventory.open;
		f.player.inventory.update = true;
	}
	if (f.buttons[f.findButton("O")].pressed == 1){
		f.buttons[f.findButton("O")].pressed = 2;
		f.UI.TabStats.open = !f.UI.TabStats.open;
	}
	if (f.buttons[f.findButton("P")].pressed == 1){
		f.buttons[f.findButton("P")].pressed = 2;
		f.UI.TabQuests.open = !f.UI.TabQuests.open;
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
        if(f.buttons[f.findButton("Left Shift")].pressed==1) f.player.stats[0][0].levelBase--;
		else f.player.stats[0][0].levelBase++;
		f.player.stats[0][0].updateLevelBaseLayer = true;
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
void battle_(){
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
				if (f.pointInsideRect(f.mouse, f.getRect((int)(f.battleEnemies[i].location.x + f.battleEnemies[i].image.surface->w*f.battleEnemies[i].legCenter.x - f.images[base].image.surface->w / 2), (int)(f.battleEnemies[i].location.y + f.battleEnemies[i].image.surface->h*f.battleEnemies[i].legCenter.y - f.images[base].image.surface->h / 2), f.images[base].image.surface->w, f.images[base].image.surface->h)) || 
					f.pointInsideRect(f.mouse, f.getRect(f.battleEnemies[i].location.x, f.battleEnemies[i].location.y, f.battleEnemies[i].image.surface->w, f.battleEnemies[i].image.surface->h))){
                       f.selectedId=i;
                }
            }
			f.renderTexture(&f.images[base].image,f.images[base].image.surface->clip_rect,f.getPoint((int)(f.battleEnemies[i].location.x + f.battleEnemies[i].image.w*f.battleEnemies[i].legCenter.x - f.images[base].image.w / 2),(int)(f.battleEnemies[i].location.y + f.battleEnemies[i].image.h*f.battleEnemies[i].legCenter.y - f.images[base].image.h / 2)));
			f.renderTexture(&f.battleEnemies[i].image, f.battleEnemies[i].image.surface->clip_rect, f.battleEnemies[i].location);
        }
        if(f.selectedId!=-1){
            if(f.movePoint(&(f.maps[f.player.map_location].platforms[f.selectedId+5]),3)) f.player.isInBattle=1;
        }
        int battleUI=f.findImage("battleUI");
        f.renderTexture(&f.images[battleUI].image,f.images[battleUI].image.surface->clip_rect,f.getPoint(0,f.SCREEN_HEIGHT-f.images[battleUI].image.h));
        for(int i = 0; i < 4; i++){
             f.renderTexture(&f.Spells[0].icon_active,f.Spells[0].icon_active.surface->clip_rect, f.getPoint(615+i*57, 645));
             if(f.pointInsideRect(f.mouse,f.getRect(615, 645, 50, 50))&&((f.leftMouseButton==1)||(f.leftMouseButton==2))){
                 f.leftMouseButton=2;
                 f.renderTexture(&f.Spells[0].icon_cooldown,f.Spells[0].icon_cooldown.surface->clip_rect, f.getPoint(615, 645));
             }
        }

    }
}
void gather_(){
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
        f.renderTexture(&f.images[f.findImage("progressBarFrame")].image,f.images[f.findImage("progressBarFrame")].image.surface->clip_rect,f.getPoint((f.SCREEN_WIDTH-f.images[f.findImage("progressBarFrame")].image.surface->w)/2,f.SCREEN_HEIGHT-f.images[f.findImage("progressBarFrame")].image.surface->h-20));
		f.renderTexture(&f.images[f.findImage("progressBarInside")].image, f.getRect(0, 0, (int)(f.images[f.findImage("progressBarInside")].image.surface->w*(1 - f.player.gatherTime / f.maps[f.player.map_location].gatherable[f.player.gatherableId].gatherTime)), f.images[f.findImage("progressBarInside")].image.surface->h), f.getPoint((f.SCREEN_WIDTH - f.images[f.findImage("progressBarFrame")].image.surface->w) / 2, f.SCREEN_HEIGHT - f.images[f.findImage("progressBarFrame")].image.surface->h - 20));
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
void regrow_(){
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