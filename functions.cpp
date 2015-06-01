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
#include "variables.h"
#include "layer.h"
#include "spell.h"

functions::functions()
{
    functions::addColor(0,0,0);
    functions::addColor(255,0,0);
    functions::addColor(0,255,0);
    functions::addColor(0,0,255);
}

void functions::renderInventory(){
    if(functions::player.inventory.open){
        if(functions::player.inventory.offsetY+functions::mouseWheelMotion*functions::sliderSpeed<=0&&
           functions::player.inventory.offsetY+functions::mouseWheelMotion*functions::sliderSpeed>=functions::player.inventory.backPanel.rect.h-functions::sections*functions::player.inventory.slotFrame.rect.h-(functions::sections+1)*distanceBetweenSlots)
            functions::player.inventory.offsetY+=functions::mouseWheelMotion*functions::sliderSpeed;
        functions::player.inventory.inventoryL.surface=SDL_ConvertSurface(functions::player.inventory.frame.surface,functions::player.inventory.frame.surface->format,0);
        functions::copySurface(functions::player.inventory.backPanel.surface,
                               functions::player.inventory.inventoryL.surface,
                               functions::player.inventory.backPanel.rect,
                               functions::player.inventory.backPanelOffset.x,
                               functions::player.inventory.backPanelOffset.y);
        int y2,x2;
        for(int i=0; i<functions::sections; i++){
            y2=i*functions::player.inventory.slotFrame.rect.h+(i+1)*distanceBetweenSlots+functions::player.inventory.backPanelOffset.y;
            y2+=functions::player.inventory.offsetY;
            if(y2<functions::player.inventory.backPanelOffset.y+functions::player.inventory.backPanel.rect.h&&
                y2+functions::player.inventory.slotFrame.rect.h>functions::player.inventory.backPanelOffset.y){
                for(int o=0; o<functions::inventorySlotsPerRow; o++){
                    if(i*functions::inventorySlotsPerRow+o+1>functions::player.inventory.slots.size())o=functions::inventorySlotsPerRow;
                    else{
                        x2=o*functions::player.inventory.slotFrame.rect.w+(o+1)*distanceBetweenSlots+functions::player.inventory.backPanelOffset.x;
                        if(y2<functions::player.inventory.backPanelOffset.y){
                            //------------------------------------------------------------------------------------------------//
                            functions::copySurface(functions::player.inventory.slotFrame.surface,//from
                                                   functions::player.inventory.inventoryL.surface,//to
                                                   functions::player.inventory.slotFrame.rect.x,//from x
                                                   functions::player.inventory.backPanelOffset.y-y2,//from y
                                                   functions::player.inventory.slotFrame.rect.w,//width
                                                   functions::player.inventory.slotFrame.rect.h-functions::player.inventory.backPanelOffset.y+y2,//height
                                                   x2,//to x
                                                   functions::player.inventory.backPanelOffset.y);//to y
                            //------------------------------------------------------------------------------------------------//
                        }
                        else if(y2+functions::player.inventory.slotFrame.rect.h>functions::player.inventory.backPanelOffset.y+functions::player.inventory.backPanel.rect.h){
                            //------------------------------------------------------------------------------------------------//
                            functions::copySurface(functions::player.inventory.slotFrame.surface,//from
                                                   functions::player.inventory.inventoryL.surface,//to
                                                   functions::player.inventory.slotFrame.rect.x,
                                                   functions::player.inventory.slotFrame.rect.y,
                                                   functions::player.inventory.slotFrame.rect.w,
                                                   functions::player.inventory.backPanelOffset.y+functions::player.inventory.backPanel.rect.h-y2,
                                                   x2,
                                                   y2);
                            //------------------------------------------------------------------------------------------------//
                        }
                        else {
                            functions::copySurface(functions::player.inventory.slotFrame.surface,//from
                                                   functions::player.inventory.inventoryL.surface,//to
                                                   functions::player.inventory.slotFrame.rect,
                                                   x2,
                                                   y2);
                        }
                    }
                }
            }
        }
        functions::copySurface(functions::player.inventory.frame.surface,functions::player.inventory.inventoryL.surface,functions::player.inventory.inventoryL.surface->clip_rect);
        if(functions::player.inventory.ammountOfIntersections>=0){
            functions::copySurface(functions::player.inventory.slider.surface,
                                   functions::player.inventory.inventoryL.surface,0,0,
                                   functions::player.inventory.slider.rect.w,
                                   functions::player.inventory.slider.rect.h/2,
                                   functions::player.inventory.sliderOffset.x,
                                   functions::player.inventory.sliderOffset.y-functions::player.inventory.offsetY);
            functions::copySurface(functions::player.inventory.slider.surface,
                                   functions::player.inventory.inventoryL.surface,0,
                                   functions::player.inventory.slider.rect.h/2+1,
                                   functions::player.inventory.slider.rect.w,
                                   functions::player.inventory.slider.rect.h/2,
                                   functions::player.inventory.sliderOffset.x,
                                   functions::player.inventory.sliderOffset.y+functions::player.inventory.ammountOfIntersections+functions::player.inventory.slider.rect.h/2-functions::player.inventory.offsetY);
            for(int i=0; i<=functions::player.inventory.ammountOfIntersections; i++){
                functions::copySurface(functions::player.inventory.slider.surface,
                                       functions::player.inventory.inventoryL.surface,0,
                                       functions::player.inventory.slider.rect.h/2+1,
                                       functions::player.inventory.slider.rect.w,1,
                                       functions::player.inventory.sliderOffset.x,
                                       functions::player.inventory.sliderOffset.y+functions::player.inventory.slider.rect.h/2+i-functions::player.inventory.offsetY,
                                       functions::player.inventory.slider.rect.w,1);
            }
        }
        else{
            functions::copySurface(functions::player.inventory.slider.surface,
                                   functions::player.inventory.inventoryL.surface,
                                   functions::player.inventory.slider.rect,
                                   functions::player.inventory.sliderOffset.x,
                                   functions::player.inventory.sliderOffset.y-functions::player.inventory.offsetY*(functions::tatssbatm/(functions::tatssbatm-functions::player.inventory.ammountOfIntersections)));
        }
        functions::renderSurface(functions::player.inventory.inventoryL.surface,functions::player.inventory.inventoryL.surface->clip_rect,functions::player.inventory.frame.location.x,functions::player.inventory.frame.location.y);
    }
}

void functions::callEvent(std::string type, info &information){
    if(type=="Enter"){
        functions::callEventEnter(information);
    }
}

void functions::callEventEnter(info &information){
    functions::player.map_location=information.intInfo[0];
    functions::player.location.x=information.intInfo[1];
    functions::player.location.y=information.intInfo[2];
}

void functions::getEntityCornerColors(SDL_Surface* surface, SDL_Color colorHolder[4], SDL_Point pixelLocation[4]){
    std::stringstream ss;
    for(int i=0; i<4; i++) {
        functions::getEntityCorner(i+1,functions::player.location,functions::player.image.rect,pixelLocation[i]);
        pixelLocation[i].x=pixelLocation[i].x*surface->w/functions::SCREEN_WIDTH;
        pixelLocation[i].y=pixelLocation[i].y*surface->h/functions::SCREEN_HEIGHT;
        functions::getPixelColors(surface,pixelLocation[i].x,
                                          pixelLocation[i].y,
                                          colorHolder[i]);
        if(functions::buttons[functions::findButton("F")].pressed==1) ss << "[" << pixelLocation[i].x << ";" << pixelLocation[i].y << "]=[" << functions::toString(colorHolder[i].r) << "," << functions::toString(colorHolder[i].g) << "," << functions::toString(colorHolder[i].b) << "," << functions::toString(colorHolder[i].a) << "]\n";
    }
    if(functions::buttons[functions::findButton("F")].pressed==1) functions::error(ss.str());
}

void functions::getEntityCorner(int corner, SDL_Point entityLocation, SDL_Rect& entityRect, SDL_Point &locationHolder){
    locationHolder=entityLocation;
    switch(corner){
    case 2:
        locationHolder.x+=entityRect.w;
        break;
    case 3:
        locationHolder.x+=entityRect.w;
        locationHolder.y+=entityRect.h;
        break;
    case 4:
        locationHolder.y+=entityRect.h;
        break;
    }
}

void functions::addObstruction(int r, int g, int b, int a){
    SDL_Color color;
    color.r=r;
    color.g=g;
    color.b=b;
    color.a=a;
    functions::obstructions.push_back(color);
}

void functions::addObstruction(SDL_Color color){
    functions::obstructions.push_back(color);
}

int functions::findButton(std::string name){
    for(int i=1; i<functions::buttons.size(); i++){
        if(functions::buttons[i].name==name){
            return i;
        }
    }
    functions::error("Button by the name of "+name+" was not found, fix the program!");
    return 0;
}

void functions::moveCharacter(bool withObstructions, SDL_Surface* surfaceOfObstructions){
    if(withObstructions){
        SDL_Color currentColor[4]; SDL_Point pixelLocation[4];
        SDL_Point savedLocation=functions::player.location;
        functions::moveCharacter();
        SDL_Point movedLocation=functions::player.location;
        SDL_Point doneLocation=movedLocation;

        functions::player.location.x=movedLocation.x;
        functions::player.location.y=savedLocation.y;
        functions::getEntityCornerColors(surfaceOfObstructions,currentColor,pixelLocation);
        for(int i=0; i<obstructions.size(); i++){
            if(functions::equalColors(currentColor[0],obstructions[i])||
               functions::equalColors(currentColor[1],obstructions[i])||
               functions::equalColors(currentColor[2],obstructions[i])||
               functions::equalColors(currentColor[3],obstructions[i])){
                doneLocation.x=savedLocation.x;
                i=obstructions.size();
            }
        }
        functions::player.location.x=savedLocation.x;
        functions::player.location.y=movedLocation.y;
        functions::getEntityCornerColors(surfaceOfObstructions,currentColor,pixelLocation);
        for(int i=0; i<obstructions.size(); i++){
            if(functions::equalColors(currentColor[0],obstructions[i])||
               functions::equalColors(currentColor[1],obstructions[i])||
               functions::equalColors(currentColor[2],obstructions[i])||
               functions::equalColors(currentColor[3],obstructions[i])){
                doneLocation.y=savedLocation.y;
                i=obstructions.size();
            }
        }
        functions::player.location=doneLocation;
    }
    else{
        functions::moveCharacter();
    }
}

void functions::moveCharacter(){
    if(functions::buttons[functions::findButton("D")].pressed==1 || functions::buttons[functions::findButton("Right")].pressed==1) functions::player.location.x+=functions::player.movementSpeed;
    if(functions::buttons[functions::findButton("A")].pressed==1 || functions::buttons[functions::findButton("Left")].pressed==1)  functions::player.location.x-=functions::player.movementSpeed;
    if(functions::buttons[functions::findButton("S")].pressed==1 || functions::buttons[functions::findButton("Down")].pressed==1)  functions::player.location.y+=functions::player.movementSpeed;
    if(functions::buttons[functions::findButton("W")].pressed==1 || functions::buttons[functions::findButton("Up")].pressed==1)    functions::player.location.y-=functions::player.movementSpeed;
}

void functions::addSpell(std::string type, float damage, float manaCost, std::string path){
    spell spell_temp;
    spell_temp.elementType=type;
    spell_temp.damage=damage;
    spell_temp.manaCost=manaCost;
    if (functions::loadImage(path, spell_temp.shape)==0){functions::Spells.push_back(spell_temp);};
}

void functions::loadMedia(){
    functions::loadImage("qpm\\player.png",functions::player.image);
    functions::loadImage("qpm\\inventoryFrame.png",functions::player.inventory.frame);
    functions::player.inventory.setLocations(functions::SCREEN_WIDTH-functions::player.inventory.frame.rect.w-50,50);
    functions::loadImage("qpm\\inventoryBackPanel.png",functions::player.inventory.backPanel);
    functions::loadImage("qpm\\inventorySlot.png",functions::player.inventory.slotFrame);
    functions::loadImage("qpm\\inventorySlider.png",functions::player.inventory.slider);
    functions::addButton("Always false",SDLK_d);
    functions::addButton("D",SDLK_d);
    functions::addButton("A",SDLK_a);
    functions::addButton("S",SDLK_s);
    functions::addButton("W",SDLK_w);
    functions::addButton("Right",SDLK_RIGHT);
    functions::addButton("Left",SDLK_LEFT);
    functions::addButton("Down",SDLK_DOWN);
    functions::addButton("Up",SDLK_UP);
    functions::addButton("F",SDLK_f);
    functions::addButton("G",SDLK_g);
    functions::addButton("E",SDLK_e);
    functions::addButton("I",SDLK_i);
    functions::addButton("Left Shift",SDLK_LSHIFT);
    functions::addObstruction(0,0,10,255);
    functions::addObstruction(0,0,200,255);
    functions::distanceBetweenSlots=(functions::player.inventory.backPanel.rect.w-functions::player.inventory.slotFrame.rect.w*functions::inventorySlotsPerRow)/(functions::inventorySlotsPerRow+1);
    functions::sections=functions::player.inventory.slots.size()/functions::inventorySlotsPerRow;
    if(functions::player.inventory.slots.size()%functions::inventorySlotsPerRow!=0) functions::sections++;
    functions::player.inventory.ammountOfIntersections=functions::player.inventory.backPanel.rect.h+(2*(functions::player.inventory.backPanelOffset.y-functions::player.inventory.sliderOffset.y))-functions::player.inventory.slider.rect.h/2*2+1+(functions::player.inventory.backPanel.rect.h-functions::sections*functions::player.inventory.slotFrame.rect.h-(functions::sections+1)*distanceBetweenSlots);
    functions::tatssbatm=(functions::player.inventory.slider.location.y+functions::player.inventory.backPanel.rect.h+(2*(functions::player.inventory.backPanelOffset.y-functions::player.inventory.sliderOffset.y))-functions::player.inventory.slider.rect.h/2-1)-(functions::player.inventory.slider.location.y+functions::player.inventory.slider.rect.h/2);
}

void functions::addButton(std::string name, SDL_Keycode key){
    keyboard button_temp;
    button_temp.name=name;
    button_temp.keycode=key;
    functions::buttons.push_back(button_temp);
}

void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,SDL_Rect &destinationRect){
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        functions::error(SDL_GetError());
    }
}

void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceAndDestRect){
    if(SDL_BlitSurface(sourceSurface,&sourceAndDestRect,destinationSurface,&sourceAndDestRect)!=0){
        functions::error(SDL_GetError());
    }
}

void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect, bool fillSurface){
    SDL_Rect destinationRect;
    if(fillSurface){
        destinationRect.x=0;                destinationRect.y=0;
        destinationRect.w=sourceSurface->w; destinationRect.h=sourceSurface->h;
        if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
            functions::error(SDL_GetError());
        }
    }
}

void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1,int x2, int y2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w1; destinationRect.h=h1;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        functions::error(SDL_GetError());
    }
}

void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w2; destinationRect.h=h2;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        functions::error(SDL_GetError());
    }
}

void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,int x, int y, int w, int h){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=w; destinationRect.h=h;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        functions::error(SDL_GetError());
    }
}

void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,int x, int y){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=sourceRect.w; destinationRect.h=sourceRect.h;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        functions::error(SDL_GetError());
    }
}

void functions::renderSurface(SDL_Surface* surface,SDL_Rect &sourceRect,SDL_Rect &destinationRect){
    SDL_Texture* texture=NULL;
    texture=SDL_CreateTextureFromSurface(functions::renderer,surface);
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
    texture=NULL;
}

void functions::renderSurface(SDL_Surface* surface,SDL_Rect &sourceAndDestRect){
    SDL_Texture* texture=NULL;
    texture=SDL_CreateTextureFromSurface(functions::renderer,surface);
    SDL_RenderCopy(renderer,texture,&sourceAndDestRect,&sourceAndDestRect);
    texture=NULL;
}

void functions::renderSurface(SDL_Surface* surface,SDL_Rect &sourceRect, bool fillScreen){
    SDL_Texture* texture=NULL;
    texture=SDL_CreateTextureFromSurface(functions::renderer,surface);
    SDL_Rect destinationRect;
    if(fillScreen){
        destinationRect.x=0;              destinationRect.y=0;
        destinationRect.w=SCREEN_WIDTH; destinationRect.h=SCREEN_HEIGHT;
        if(SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect)!=0){
            functions::error(SDL_GetError());
        }
    }
    texture=NULL;
}

void functions::renderSurface(SDL_Surface* surface,int x1, int y1, int w1, int h1,int x2, int y2){
    SDL_Texture* texture=NULL;
    texture=SDL_CreateTextureFromSurface(functions::renderer,surface);
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w1; destinationRect.h=h1;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
    texture=NULL;
}

void functions::renderSurface(SDL_Surface* surface,int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2){
    SDL_Texture* texture=NULL;
    texture=SDL_CreateTextureFromSurface(functions::renderer,surface);
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w2; destinationRect.h=h2;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
    texture=NULL;
}

void functions::renderSurface(SDL_Surface* surface,SDL_Rect &sourceRect,int x, int y, int w, int h){
    SDL_Texture* texture=NULL;
    texture=SDL_CreateTextureFromSurface(functions::renderer,surface);
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=w; destinationRect.h=h;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
    texture=NULL;
}

void functions::renderSurface(SDL_Surface* surface,SDL_Rect &sourceRect,int x, int y){
    SDL_Texture* texture=NULL;
    texture=SDL_CreateTextureFromSurface(functions::renderer,surface);
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=sourceRect.w; destinationRect.h=sourceRect.h;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
    texture=NULL;
}

void functions::renderTexture(SDL_Texture* texture,SDL_Rect &sourceRect,SDL_Rect &destinationRect){
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
}

void functions::renderTexture(SDL_Texture* texture,SDL_Rect &sourceAndDestRect){
    SDL_RenderCopy(renderer,texture,&sourceAndDestRect,&sourceAndDestRect);
}

void functions::renderTexture(SDL_Texture* texture,SDL_Rect &sourceRect, bool fillScreen){
    SDL_Rect destinationRect;
    if(fillScreen){
        destinationRect.x=0;              destinationRect.y=0;
        destinationRect.w=SCREEN_WIDTH; destinationRect.h=SCREEN_HEIGHT;
        if(SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect)!=0){
            functions::error(SDL_GetError());
        }
    }
}

void functions::renderTexture(SDL_Texture* texture,int x1, int y1, int w1, int h1,int x2, int y2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w1; destinationRect.h=h1;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
}

void functions::renderTexture(SDL_Texture* texture,int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w2; destinationRect.h=h2;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
}

void functions::renderTexture(SDL_Texture* texture,SDL_Rect &sourceRect,int x, int y, int w, int h){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=w; destinationRect.h=h;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
}

void functions::renderTexture(SDL_Texture* texture,SDL_Rect &sourceRect,int x, int y){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=sourceRect.w; destinationRect.h=sourceRect.h;
    SDL_RenderCopy(renderer,texture,&sourceRect,&destinationRect);
}

std::string functions::toString(int number){
    std::stringstream ss;
    ss << number;
    return ss.str();
}

bool functions::equalColors(SDL_Color a, SDL_Color b){
    if(a.r==b.r&&a.g==b.g&&a.b==b.b&&a.a==b.a) return true;
    else return false;
}

void functions::addColor(int r, int g, int b, int a){
    SDL_Color color_temp;
    color_temp.r=r;
    color_temp.g=g;
    color_temp.b=b;
    color_temp.a=a;
    Colors.push_back(color_temp);
}

void functions::addColor(int r, int g, int b){
    SDL_Color color_temp;
    color_temp.r=r;
    color_temp.g=g;
    color_temp.b=b;
    color_temp.a=255;
    Colors.push_back(color_temp);
}

SDL_Color functions::getColor(int id){
    if(id>0&&id<Colors.size()){
        return Colors[id-1];
    }
    functions::error("There's no color with id "+id);
}

int functions::getZoneId(SDL_Surface* secretLayer){ //returns -1 if it doesn't find the corresponding color
    SDL_Color color;
    functions::getPixelColors(secretLayer,player.location.x,player.location.y,color);
    for(int i=0; i<Colors.size(); i++){
        if(functions::equalColors(color,getColor(i))){
            return i;
        }
    }
    functions::error("Color ["+functions::toString(color.r)+","+functions::toString(color.g)+","+functions::toString(color.b)+","+functions::toString(color.a)+"] is not in the color list.");
    return -1;
}

Uint32 functions::getPixel(SDL_Surface *surface, int x, int y){
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

void functions::getPixelColors(SDL_Surface* surface, double x, double y, SDL_Color &colorHolder){
    SDL_PixelFormat *format;
	Uint32 temp, pixel;
	Uint8 color[3];

    format=surface->format;
    SDL_LockSurface(surface);
    pixel=getPixel(surface,x,y);
    SDL_UnlockSurface(surface);

    temp=pixel&format->Rmask; /* Isolate red component */
    temp=temp>>format->Rshift;/* Shift it down to 8-bit */
    temp=temp<<format->Rloss; /* Expand to a full 8-bit number */
    color[0]=(Uint8)temp;

    temp=pixel&format->Gmask; /* Isolate green component */
    temp=temp>>format->Gshift;/* Shift it down to 8-bit */
    temp=temp<<format->Gloss; /* Expand to a full 8-bit number */
    color[1]=(Uint8)temp;

    temp=pixel&format->Bmask; /* Isolate blue component */
    temp=temp>>format->Bshift;/* Shift it down to 8-bit */
    temp=temp<<format->Bloss; /* Expand to a full 8-bit number */
    color[2]=(Uint8)temp;
    colorHolder.r=color[0];
    colorHolder.g=color[1];
    colorHolder.b=color[2];
    colorHolder.a=255;
}

SDL_Color functions::getPixelColors(SDL_Surface* surface, double x, double y){
    SDL_PixelFormat *format;
	Uint32 temp, pixel;
	Uint8 color[3];

    format=surface->format;
    SDL_LockSurface(surface);
    pixel=getPixel(surface,x,y);
    SDL_UnlockSurface(surface);

    temp=pixel&format->Rmask; /* Isolate red component */
    temp=temp>>format->Rshift;/* Shift it down to 8-bit */
    temp=temp<<format->Rloss; /* Expand to a full 8-bit number */
    color[0]=(Uint8)temp;

    temp=pixel&format->Gmask; /* Isolate green component */
    temp=temp>>format->Gshift;/* Shift it down to 8-bit */
    temp=temp<<format->Gloss; /* Expand to a full 8-bit number */
    color[1]=(Uint8)temp;

    temp=pixel&format->Bmask; /* Isolate blue component */
    temp=temp>>format->Bshift;/* Shift it down to 8-bit */
    temp=temp<<format->Bloss; /* Expand to a full 8-bit number */
    color[2]=(Uint8)temp;
    SDL_Color colorHolder;
    colorHolder.r=color[0];
    colorHolder.g=color[1];
    colorHolder.b=color[2];
    colorHolder.a=255;
    return colorHolder;
}

int functions::loadImage(std::string path, layer &layererer){
    layererer.surface=NULL;
    layererer.texture=NULL;
    layererer.surface=IMG_Load(path.c_str());
    if(layererer.surface==NULL){
        functions::error("image in this directory: "+path+"was not found.");
        return 1;
    }
    else{
        layererer.texture=SDL_CreateTextureFromSurface(renderer,layererer.surface);
        if(layererer.texture==NULL){
            functions::error("Failed to create a texture.");
            return 1;
        }
        else{
            layererer.rect.x=0;
            layererer.rect.y=0;
            layererer.rect.w=layererer.surface->w;
            layererer.rect.h=layererer.surface->h;
        }
    }
    return 0;
}

void functions::error(int errorNumber){
    switch(errorNumber){
    case 1:
        MessageBox(hwnd,"Linear texture filtering not enabled!","Warning:",MB_OK);
        break;
    }
}

void functions::error(std::string errorMessage){
    MessageBox(hwnd,errorMessage.c_str(),NULL,MB_OK);
}

bool functions::initialize(){
	bool success=true;
	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)<0) {
        success=false;
        functions::error("SDL could not initialize! SDL Error: "+(*SDL_GetError()));
	}

    //Set texture filtering to linear
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"0")) functions::error(1);

    //Create window
    window = SDL_CreateWindow( screenName.c_str(), screenStartPosition.x, screenStartPosition.y, SCREEN_WIDTH, SCREEN_HEIGHT, fullscreen);
    if(success&&window==NULL){ //error
        functions::error("Window could not be created! SDL Error: "+(*SDL_GetError()));
        success=false;
    }
    else{
        SDL_VERSION(&WindowInfo.version);
        SDL_GetWindowWMInfo(window,&WindowInfo);
        hwnd=WindowInfo.info.win.window;
        //Create renderer for window
        renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if(renderer==NULL) { //error
            functions::error("Renderer could not be created! SDL Error: "+(*SDL_GetError()));
            success=false;
        }
        else{
            //Initialize PNG loading
            int imgFlags = IMG_INIT_PNG;
            if( !(IMG_Init(imgFlags) & imgFlags ) ) {//error
                functions::error("SDL_image could not initialize! SDL_image Error: "+(*IMG_GetError()));
                success=false;
            }
            else{
                if(TTF_Init()<0) {//error
                    functions::error("SDL_ttf could not initialize! SDL_ttf Error: "+(*SDL_GetError()));
                    success = false;
                }
            }
        }
    }
	return success;
}

void functions::close() {
    //Destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window=NULL;
	renderer=NULL;
	//Quit SDL subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}


