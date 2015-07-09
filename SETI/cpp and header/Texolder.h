#ifndef TEXOLDER_H
#define TEXOLDER_H

#include "libs.h"
#include "layer.h"

class functions;

class Texolder{
    public:
        Texolder(functions* fp);
		struct TH{ TH* relativeTo = nullptr; layer* layerp; Texolder* texolderp; bool which, render = true; int *layerId; std::string name, relativeToS = ""; SDL_Rect *from, *to; SDL_Point location, locationUpdateTimeStamp; };
        std::vector<TH> texture;
        struct LH{int id; std::string name;};
        struct sortByLayerId{inline bool operator()(const TH& check1, const TH& check2){return(*(check1.layerId)<*(check2.layerId));}};
        void setLocationX(TH& THRef, int coordinate);
        void setLocationY(TH& THRef, int coordinate);
        int getLocationX(TH* THRef);
        int getLocationY(TH* THRef);
        void renderTextures();
        void sortTextures();
        int* findLayer(std::string layerName);
        int* addLayer(std::string layerName);
        int findTexture(std::string textureName);
        int findTexture(int layerId);
		void addTexture(layer* l, int* layerId, std::string name, SDL_Rect &from, SDL_Rect &to, std::string relativeTo = "");
		void addTexture(Texolder* t, int* layerId, std::string name, SDL_Rect &from, SDL_Rect &to, std::string relativeTo = "");
		void additionBase(int* layerId, std::string name, SDL_Rect &from, SDL_Rect &to, std::string relativeTo);
    private:
        functions* f;
        bool sorted=false;
        std::vector<LH> layers;
};

#endif // TEXOLDER_H
