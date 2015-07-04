#ifndef LAYER_H
#define LAYER_H

#include "libs.h"

class layer{
    public:
        layer();
        SDL_Surface* surface=NULL;
        GLuint textureOpenGL=0;
        SDL_Rect from,to;
        float zoom=0,zoomWidth=0,zoomHeight=0;
        SDL_Point location;
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
