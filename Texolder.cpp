#include "Texolder.h"
#include "functions.h"
#include <algorithm>

Texolder::Texolder(functions* fp){
    f=fp;
}

void Texolder::renderTextures(){
    if(!sorted) sortTextures();
    for(TH &n : texture){
        if(n.which) n.texolderp->renderTextures();
        else{
            if(n.relativeTo!=""){
                SDL_Rect to=*n.to;
                TH &relative=texture[findTexture(n.relativeTo)];
                to.x+=relative.location.x;
                to.y+=relative.location.y;
                f->renderTexture(n.layerp,*n.from,to);
            }
            else f->renderTexture(n.layerp,*n.from,*n.to);
        }
    }
}
void Texolder::sortTextures(){
    std::sort(texture.begin(),texture.end(),sortByLayerId());
    sorted=true;
}
int* Texolder::findLayer(std::string layerName){
    for(LH &n : layers){
        if(n.name==layerName){
            return &n.id;
        }
    }
}
int* Texolder::addLayer(std::string layerName){
    LH tempL;
    tempL.name=layerName;
    tempL.id=layers.size();
    layers.push_back(tempL);
    return &layers[layers.size()].id;
}
int Texolder::findTexture(std::string textureName){
    for(int i=0; i<(int)texture.size(); i++){
        if(texture[i].name==textureName){
            return i;
        }
    }
    return -1;
}
int Texolder::findTexture(int layerId){
    for(int i=0; i<(int)texture.size(); i++){
        if(*texture[i].layerId==layerId){
            return i;
        }
    }
    return -1;
}
void Texolder::setTHx(TH& thl, int x){
    thl.location.x-=thl.to->x; thl.to->x=x; thl.location.x+=thl.to->x;
}
void Texolder::setTHy(TH& thl, int y){
    thl.location.y-=thl.to->y; thl.to->y=y; thl.location.x+=thl.to->y;
}
void Texolder::addTexture(layer* l, int* layerId, std::string name, SDL_Rect &from, SDL_Rect &to, std::string relativeTo){
    sorted=false;
    TH tempTH;
    tempTH.layerp=l;
    tempTH.which=false;
    tempTH.layerId=layerId;
    tempTH.name=name;
    tempTH.from=&from;
    tempTH.to=&to;
    tempTH.relativeTo=relativeTo;
    if(relativeTo!=""){
        tempTH.location.x=tempTH.to->x+texture[findTexture(tempTH.relativeTo)].location.x;
        tempTH.location.y=tempTH.to->y+texture[findTexture(tempTH.relativeTo)].location.y;
    }
    else{
        tempTH.location.x=tempTH.to->x;
        tempTH.location.y=tempTH.to->y;
    }
    texture.push_back(tempTH);
}
void Texolder::addTexture(Texolder* t, int* layerId, std::string name, SDL_Rect &from, SDL_Rect &to, std::string relativeTo){
    sorted=false;
    TH tempTH;
    tempTH.texolderp=t;
    tempTH.which=true;
    tempTH.layerId=layerId;
    tempTH.name=name;
    tempTH.from=&from;
    tempTH.to=&to;
    tempTH.relativeTo=relativeTo;
    if(relativeTo!=""){
        tempTH.location.x=tempTH.to->x+texture[findTexture(tempTH.relativeTo)].location.x;
        tempTH.location.y=tempTH.to->y+texture[findTexture(tempTH.relativeTo)].location.y;
    }
    else{
        tempTH.location.x=tempTH.to->x;
        tempTH.location.y=tempTH.to->y;
    }
    texture.push_back(tempTH);
}