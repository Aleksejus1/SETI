#ifndef LAYER_H
#define LAYER_H

#include "libs.h"

class layer{
    public:
        layer();
        SDL_Surface* surface=nullptr;
        GLuint textureOpenGL=0;
        SDL_Rect from,to;
		libs::SDL_Colorf color;
        float zoom=0.f,zoomWidth=0.f,zoomHeight=0.f,rotation=0.f,z=-1.f;
		SDL_Point offset;
		bool rotate = false;
        int w=0,h=0;
        void updateSize();
        void setWidthZoom(float number);
        void setHeightZoom(float number);
        void setZoom(float number);
        void free();
        void freeSurface();
        void freeTexture();
};

#endif // LAYER_H
