#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "libs.h"
#include "layer.h"
#include "variables.h"
#include "spell.h"
#include "gather.h"
#include "stage.h"

class functions: public variables{
    public:
        functions(); //Initialization function
        //
        userInterface UI;
        character player; //Player information holder
        Texolder menuTxl;
        //
		void renderEquipment(bool =false);
		void moveLayerWithinBorder(layer&, SDL_Rect, SDL_Point&);
		void renderStat(character::stat&, SDL_Point, float);
		void renderStats(bool =false);
		void menuPulse();
		void swapItemStacks(itemStack&, itemStack&);
		void clipLayer(layer&, SDL_Rect);
		void clip(SDL_Rect, SDL_Rect, SDL_Rect&, SDL_Point&);
		int convertNumbersByRelativity(int, int, int);
		void createTexture(layer&);
		void writeMessage(std::string, layer&, SDL_Color = variables::messageColor, TTF_Font* = variables::font);
		void renderItem(itemStack&, SDL_Rect&, SDL_Point, int =0);//renderType - 0=default, 1=only item, 2=only item count
		void renderSlots(space&,bool =false);
        void spawnFlameParticle();
        void renderFlameParticles();
        int getColorAlpha(SDL_Color);
        map* createBattleZone(std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
        map* createMap(std::string, std::string);
        void addGatherableReturnItemStack(int, item, gather&);
        gather* createGatherable(int, int, int, bool, float, int, std::string);
        stage* addStage(float, bool, bool, std::string, gather&);
        void createZone(int, std::string, std::string);
        interact* createInteractable(int, std::string, int, int, bool);
        interact* createInteractable(int, std::string, int, int, int, int, bool);
        void createObject(int, std::string, int, int, bool);
        void createLayer(int, std::string);
        void sendMessageToConsole(std::string, int =0);
        void console();
        void reset();
        GLuint convertSurfaceToOpenGLTexture(SDL_Surface*);
        void affectStats(item*, bool);
        void unequipItem(int, int =-1);
		bool equipItem(itemStack&, space* =nullptr, int =NULL);
		void removeItem(int, int, space&);
		void removeItem(itemStack&, int, space&);
        void affectStat(std::string, float);
        void createSurface(SDL_Surface**, int, int);
        SDL_Surface* createSurface(int, int);
        void renderUI();
        void giveItems(itemStack&);
        void giveItems(item&, int);
        void giveItems(item&, int, itemStack&);
        int findNextStage(std::vector<stage>&, int);
        int findItem(std::string);
        void addItem(std::string, std::string, std::string);
        bool movePoint(SDL_Point*, int);
        SDL_Point getPoint(int, int);
		SDL_Rect getRect(SDL_Point, int, int);
        SDL_Rect getRect(int, int, int, int);
        bool pointInsideRect(SDL_Point, SDL_Rect);
        int findImage(std::string);
        void createImage(std::string, std::string);
        void addEnemyId(std::string);
        int findEntity(std::string);//Returns the id of an entity with the same name
        void renderInventory(bool);//Presents renderer with all the necessary inventory pixel information
        void callEvent(std::string, info&);//Depending on the type given will call the representing even function
		void callEventEquip(info&);
        void callEventEnter(info&);//Event function used for entering different territories/maps
        void callEventBattle(info&);//Event function used for entering battle
        void callEventGather(info&);//Event function used for initiating a gathering process
        void getEntityCornerColors(SDL_Surface*, SDL_Color[4], SDL_Point[4]);//gets the colors of all the four corners of the player
        void getEntityCorner(int, SDL_Point, SDL_Rect&, SDL_Point&);//gets the corner corresponding to the corner variable: 1-top-left, 2-top-right, 3-bottom-right, 4-bottom-left
        void addObstruction(int, int, int, int);//Add a color to the list of obstruction colors by giving rgba values
        void addObstruction(SDL_Color);//Add a color to the list of obstruction colors by giving a SDL_Color value
        int findButton(std::string);//Returns the id of the button that has the specified name as its' name
        void moveCharacter(bool, SDL_Surface*);//Moves the player entity if the player does not collide with a color from the obstruction color list
        void moveCharacter();//Moves character depending on which buttons are being pressed
        void loadMedia();//Pre-loads all the pictures and prepares some values
        void copySurface(SDL_Surface*, SDL_Surface*, SDL_Rect&,SDL_Rect&);//Same as for the textures below, this is used to copy one surface onto another
        void copySurface(SDL_Surface*, SDL_Surface*, SDL_Rect&);
        void copySurface(SDL_Surface*, SDL_Surface*, SDL_Rect&, bool);
        void copySurface(SDL_Surface*, SDL_Surface*, int, int, int, int, int, int);
        void copySurface(SDL_Surface*, SDL_Surface*, int, int, int, int, int, int, int, int);
        void copySurface(SDL_Surface*, SDL_Surface*, SDL_Rect&, int, int, int, int);
        void copySurface(SDL_Surface*, SDL_Surface*, SDL_Rect&, int, int);
        void renderTexture(layer*, SDL_Rect&, SDL_Rect&);//Render the texture from the given source rectangle to the given destination rectangle
        void renderTexture(layer*, SDL_Rect&);//Render the texture from the given rectangle - to the given rectangle
		void renderTexture(layer*, SDL_Rect&, SDL_Point);//Render the texture from the given source rectangle to the given destination point [keeps the same size]
		void openGLRender(layer*, SDL_Rect*, SDL_Rect*);
        std::string toString(int);//Return the string value of the given number
        std::string toString(double);//Return the string value of the given number
        std::string toString(int*);//Return the string value of the given number pointer
        bool equalColors(SDL_Color, SDL_Color);//Checks if both colors are equal/same
        void addColor(int, int, int, int);//Adds a color to the color list used for zones/areas by giving the rgba values
        void addColor(int, int, int);//Adds a color to the color list used for zones/areas by giving the rgb values, alpha value is 255 - [full] by default
        bool initialize();//Used to initialize SDL2 and its' modules
        bool initGL();//Used to initialize OpenGL stuffs
        void close();//Used to close some important variables and also SDL2 and its' modules
        void error(int);//Used to print out an error corresponding to the give value
        void error(std::string);//Used to print out the given error message or simply any message
        int loadImage(std::string, layer&);//Fills the SDL_Surface and SDL_Texture of the given layer by an image given in the path variable, if succeeds, returns 0, else 1, 2.
        int getZoneId(SDL_Surface*);//Return the value of the corresponding zone id based on the players' current location and the given server layer. If fails to find a color between zone colors, returns -1
        SDL_Color getColor(int);//Return the SDL_Color value of the zone based on the given zone id
        Uint32 getPixel(SDL_Surface*, int, int);//Return a Uint32 value pixel holder in the given coordinate of the given surface
		void getPixelColors(SDL_Surface*, int, int, SDL_Color&);//Places the color of the given surface at the given coordinates to the given color holder
		SDL_Color getPixelColors(SDL_Surface*, int, int);//Returns a SDL_Color value of the color of the given surface at the given coordinates
        void addButton(std::string, SDL_Keycode);//Adds a button to the button check list, name corresponds its' shortcut name, and the second variable is the SDL_Keycode variable which always looks like this: SDLK_
        void addSpell(std::string, float, float, std::string, std::string, std::string, int, int); //Adds spell to ...
        void addEntity(float, float, float, std::string, std::string, double, double); //Adds entities in-game
};

#endif // FUNCTIONS_H
