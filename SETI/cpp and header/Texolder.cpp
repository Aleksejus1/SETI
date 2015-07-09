#include "Texolder.h"
#include "functions.h"
#include <algorithm>

Texolder::Texolder(functions* fp){
    f=fp;
}

void Texolder::setLocationX(TH& THRef, int coordinate){
    THRef.to->x+=coordinate-getLocationX(THRef);
}
void Texolder::setLocationY(TH& THRef, int coordinate){
    THRef.to->y+=coordinate-getLocationY(THRef);
}
int Texolder::getLocationX(TH& THRef){
    int ret=THRef.to->x;
    if(THRef.relativeTo!="") ret+=getLocationX(texture[findTexture(THRef.relativeTo)]);
    return ret;
}
int Texolder::getLocationY(TH& THRef){
    int ret=THRef.to->y;
    if(THRef.relativeTo!="") ret+=getLocationY(texture[findTexture(THRef.relativeTo)]);
    return ret;
}
void Texolder::renderTextures(){
    if(!sorted) sortTextures();
    for(TH &n : texture){
        if(n.render){
            if(n.which) n.texolderp->renderTextures();
            else{
                if(n.relativeTo!=""){
                    SDL_Rect to=*n.to;
                    TH &relative=texture[findTexture(n.relativeTo)];
                    to.x+=getLocationX(relative);
                    to.y+=getLocationY(relative);
                    f->renderTexture(n.layerp,*n.from,to);
                }
                else f->renderTexture(n.layerp,*n.from,*n.to);
            }
        }
    }
}
void Texolder::sortTextures(){
    int i,j,texLength=texture.size(); TH temp; bool flag=true;
    for(i=1;(i<=texLength)&&flag;i++){
        flag=false;
        for(j=0;j<(texLength-1);j++){
            if(*texture[j+1].layerId<*texture[j].layerId){
                temp=texture[j];
                texture[j]=texture[j+1];
                texture[j+1]=temp;
                flag=true;
            }
        }
    }
    sorted=true;
}
int* Texolder::findLayer(std::string layerName){
    for(LH &n : layers){
        if(n.name==layerName){
            return &n.id;
        }
    }
    f->error("layer "+layerName+" does not exist. Fix the program!");
    return NULL;
}
int* Texolder::addLayer(std::string layerName){
	LH tempL;
	tempL.name = layerName;
	tempL.id = layers.size();
	layers.push_back(tempL);
	return &layers[layers.size()-1].id;
}
int Texolder::findTexture(std::string textureName){
    for(int i=0; i<(int)texture.size(); i++){
        if(texture[i].name==textureName){
            return i;
        }
    }
    f->error("texture "+textureName+" was not found. Fix the program!");
    return -1;
}
int Texolder::findTexture(int layerId){
    for(int i=0; i<(int)texture.size(); i++){
        if(*texture[i].layerId==layerId){
            return i;
        }
    }
    f->error("texture with layer Id "+f->toString(layerId)+" does not exist. Fix the program!");
    return -1;
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
    texture.push_back(tempTH);
}