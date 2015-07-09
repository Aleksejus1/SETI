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
        void spawnFlameParticle();
        void renderFlameParticles();
        int getColorAlpha(SDL_Color color);
        map* createBattleZone(std::string name, std::string id,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8,int x9,int y9,int x0,int y0);
        map* createMap(std::string name, std::string id);
        void addGatherableReturnItemStack(int itemCount,item containingItem,gather &gatherableTypeVar);
        gather* createGatherable(int mapId, int gatherableLocationX, int gatherableLocationY, bool colidable, float gatherTime, int requiredLevel, std::string requiredSkillName);
        stage* addStage(float timeUntilNextStage, bool isItAShortcutStage, bool isItGatherable, std::string imagePath,gather &gatherableTypeVar);
        void createZone(int mapId, std::string owner, std::string zoneName);
        interact* createInteractable(int mapId, std::string imagePath, int interactableLocationX, int interactableLocationY, bool isInteractableColidable);
        interact* createInteractable(int mapId, std::string imagePath, int interactableLocationX, int interactableLocationY, int w, int h, bool isInteractableColidable);
        void createObject(int mapId, std::string imagePath, int objectLocationX, int objectLocationY, bool isObjectColidable);
        void createLayer(int mapId, std::string imagePath);
        void sendMessageToConsole(std::string message, int wait=0);
        void console();
        void reset();
        GLuint convertSurfaceToOpenGLTexture(SDL_Surface* surface);
        void affectStats(item* itemOfWhichEffectsToUse, bool trueForGivingStats_falseForRemovingStats);
        void unequipItem(int equipmentId);
        void equipItem(int itemSlotId);
        void removeItem(int slotId, int ammount);
        void affectStat(std::string statName, float ammount);
        void createSurface(SDL_Surface** surfaceDestination, int width, int height);
        SDL_Surface* createSurface(int width, int height);
        void renderUI();
        void giveItems(itemStack &itemsToGive);
        void giveItems(item &itemToGive, int ammount);
        void giveItems(item &itemToGive, int ammount, itemStack &toWhere);
        int findNextStage(std::vector<stage> &stages, int currentStage);
        int findItem(std::string itemName);
        void addItem(std::string name, std::string type, std::string imagePath);
        bool movePoint(SDL_Point *point, int movementSpeed);
        SDL_Point getPoint(int x, int y);
        SDL_Rect getRect(int x, int y, int w, int h);
        bool pointInsideRect(SDL_Point point, SDL_Rect rect);
        int findImage(std::string imageIdInFormOfString);
        void createImage(std::string imagePath, std::string imageIdInFormOfString);
        void addEnemyId(std::string enemyName);
        int findEntity(std::string name);//Returns the id of an entity with the same name
        void renderInventory(bool manageClicks);//Presents renderer with all the necessary inventory pixel information
        void callEvent(std::string type, info &information);//Depending on the type given will call the representing even function
        void callEventEnter(info &information);//Event function used for entering different territories/maps
        void callEventBattle(info &information);//Event function used for entering battle
        void callEventGather(info &information);//Event function used for initiating a gathering process
        void getEntityCornerColors(SDL_Surface* surface, SDL_Color colorHolder[4], SDL_Point pixelLocation[4]);//gets the colors of all the four corners of the player
        void getEntityCorner(int corner, SDL_Point entityLocation, SDL_Rect& entityRect, SDL_Point &locationHolder);//gets the corner corresponding to the corner variable: 1-top-left, 2-top-right, 3-bottom-right, 4-bottom-left
        void addObstruction(int r, int g, int b, int a);//Add a color to the list of obstruction colors by giving rgba values
        void addObstruction(SDL_Color color);//Add a color to the list of obstruction colors by giving a SDL_Color value
        int findButton(std::string name);//Returns the id of the button that has the specified name as its' name
        void moveCharacter(bool withObstructions, SDL_Surface* surfaceOfObstructions);//Moves the player entity if the player does not collide with a color from the obstruction color list
        void moveCharacter();//Moves character depending on which buttons are being pressed
        void loadMedia();//Pre-loads all the pictures and prepares some values
        void copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,SDL_Rect &destinationRect);//Same as for the textures below, this is used to copy one surface onto another
        void copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceAndDestRect);
        void copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect, bool fillSurface);
        void copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1,int x2, int y2);
        void copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2);
        void copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,int x, int y, int w, int h);
        void copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,int x, int y);
        void renderTexture(layer* texture,SDL_Rect &sourceRect,SDL_Rect &destinationRect);//Render the texture from the given source rectangle to the given destination rectangle
        void renderTexture(layer* texture,SDL_Rect &sourceAndDestRect);//Render the texture from the given rectangle - to the given rectangle
        void renderTexture(layer* texture,int x, int y, int w, int h);//Render the texture from the given rectangle - to the given rectangle
        void renderTexture(layer* texture,SDL_Rect &sourceRect, bool fillScreen);//Render the texture from the given source rectangle to the whole screen if the second variable is true
        void renderTexture(layer* texture,int x1, int y1, int w1, int h1,int x2, int y2);//Render the texture from the given source coordinates and size of the texture to the given destination point [keeps the same size]
        void renderTexture(layer* texture,int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2);//Render the texture from the given coordinates and size of the texture to the given point and size
        void renderTexture(layer* texture,SDL_Rect &sourceRect,int x, int y, int w, int h);//Render the texture from the given source rectangle to the give point and size
        void renderTexture(layer* texture,SDL_Rect &sourceRect,int x, int y);//Render the texture from the given source rectangle to the given destination point [keeps the same size]
        void openGLRender(layer* texture,SDL_Rect* sourceRect,SDL_Rect* destRect);
        std::string toString(int number);//Return the string value of the given number
        std::string toString(double number);//Return the string value of the given number
        std::string toString(int* number);//Return the string value of the given number pointer
        bool equalColors(SDL_Color a, SDL_Color b);//Checks if both colors are equal/same
        void addColor(int r, int g, int b, int a);//Adds a color to the color list used for zones/areas by giving the rgba values
        void addColor(int r, int g, int b);//Adds a color to the color list used for zones/areas by giving the rgb values, alpha value is 255 - [full] by default
        bool initialize();//Used to initialize SDL2 and its' modules
        bool initGL();//Used to initialize OpenGL stuffs
        void close();//Used to close some important variables and also SDL2 and its' modules
        void error(int errorNumber);//Used to print out an error corresponding to the give value
        void error(std::string errorMessage);//Used to print out the given error message or simply any message
        int loadImage(std::string path, layer &layererer);//Fills the SDL_Surface and SDL_Texture of the given layer by an image given in the path variable, if succeeds, returns 0, else 1, 2.
        int getZoneId(SDL_Surface* secretLayer);//Return the value of the corresponding zone id based on the players' current location and the given server layer. If fails to find a color between zone colors, returns -1
        SDL_Color getColor(int id);//Return the SDL_Color value of the zone based on the given zone id
        Uint32 getPixel(SDL_Surface *surface, int x, int y);//Return a Uint32 value pixel holder in the given coordinate of the given surface
        void getPixelColors(SDL_Surface* surface, double x, double y, SDL_Color &colorHolder);//Places the color of the given surface at the given coordinates to the given color holder
        SDL_Color getPixelColors(SDL_Surface* surface, double x, double y);//Returns a SDL_Color value of the color of the given surface at the given coordinates
        void addButton(std::string name, SDL_Keycode key);//Adds a button to the button check list, name corresponds its' shortcut name, and the second variable is the SDL_Keycode variable which always looks like this: SDLK_
        void addSpell(std::string type, float damage, float manaCost, std::string base, std::string icon_active, std::string icon_cooldown, int x, int y); //Adds spell to ...
        void addEntity(float healthPoints,int level,float manaPoints,std::string name, std::string imagePath, double legCenterX, double legCenterY); //Adds entities in-game
};

#endif // FUNCTIONS_H