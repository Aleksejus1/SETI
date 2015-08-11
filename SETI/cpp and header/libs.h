#ifndef LIBS_H
#define LIBS_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_syswm.h>
#include <SDL_mixer.h>
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
//#include <dirent.h>
//#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <commdlg.h>
#include "SDL2_rotozoom.h"
#include "SDL_opengl.h"
#include "GL\gl.h"
#include "GL\GLU.h"
#include <cstdlib>

class layer;

class libs{
public:
	libs();
	static HWND hwnd;
	static int RenderType;
	static TTF_Font *font;
	static SDL_Color messageColor;
	struct fo{ SDL_Rect from, to; };
	enum renderTypes{ RENDER_MIPMAP, RENDER_NEAREST };
	GLuint convertSurfaceToOpenGLTexture(SDL_Surface*, int =RENDER_MIPMAP);
	void error(int);//Used to print out an error corresponding to the give value
	void error(std::string);//Used to print out the given error message or simply any message
	int loadImage(std::string, layer&, int = RENDER_MIPMAP);//Fills the SDL_Surface and SDL_Texture of the given layer by an image given in the path variable, if succeeds, returns 0, else 1, 2.
	void writeMessage(std::string, layer&, SDL_Color = messageColor, TTF_Font* = font);
	void writeWrappedMessage(std::string, layer&, int, SDL_Color = messageColor, TTF_Font* = font);
	void createTexture(layer&);
};

#endif // LIBS_H
