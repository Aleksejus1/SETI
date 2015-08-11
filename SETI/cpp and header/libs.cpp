#include "libs.h"
#include "layer.h"

SDL_Color libs::messageColor = { 255, 255, 255, 255 };
TTF_Font* libs::font = NULL;
HWND libs::hwnd = NULL;
int libs::RenderType = RENDER_MIPMAP;

libs::libs(){}

int libs::loadImage(std::string path, layer &layererer, int RenderType){
	layererer.surface = NULL;
	layererer.surface = IMG_Load(path.c_str());
	if (layererer.surface == NULL){
		error("image in this directory: " + path + "was not found.");
		return 1;
	}
	else{
		layererer.updateSize();
		layererer.textureOpenGL = convertSurfaceToOpenGLTexture(layererer.surface, RenderType);
		layererer.offset.x = 0;
		layererer.offset.y = 0;
	}
	return 0;
}
void libs::error(int errorNumber){
	switch (errorNumber){
	case 1:
		MessageBoxA(hwnd, "Linear texture filtering not enabled!", "Warning:", MB_OK);
		break;
	}
}
void libs::error(std::string errorMessage){
	MessageBoxA(hwnd, errorMessage.c_str(), NULL, MB_OK);
}
GLuint libs::convertSurfaceToOpenGLTexture(SDL_Surface* surface, int RenderType){
	GLuint texture;
	GLenum texture_format;
	GLint nOfColors = surface->format->BytesPerPixel;

	if (nOfColors == 4){
		if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGBA;
		else texture_format = GL_BGRA;
	}
	else if (nOfColors == 3){
		if (surface->format->Rmask == 0x000000ff) texture_format = GL_RGB;
		else texture_format = GL_BGR;
	}
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	if (RenderType == RENDER_MIPMAP){
		glTexParameterf(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
	else if (RenderType == RENDER_NEAREST) glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels);
	return texture;
};
void libs::writeMessage(std::string message, layer& layeRef, SDL_Color color, TTF_Font* messageFont){
	layeRef.free();
	layeRef.surface = TTF_RenderText_Blended(messageFont, message.c_str(), color);
	layeRef.updateSize();
	createTexture(layeRef);
}
void libs::writeWrappedMessage(std::string message, layer& layeRef, int pixelLengthUntilWrap, SDL_Color color, TTF_Font* messageFont){
	layeRef.free();
	layeRef.surface = TTF_RenderText_Blended_Wrapped(messageFont, message.c_str(), color, pixelLengthUntilWrap);
	layeRef.updateSize();
	createTexture(layeRef);
}
void libs::createTexture(layer &layeRef){
	layeRef.textureOpenGL = convertSurfaceToOpenGLTexture(layeRef.surface);
}