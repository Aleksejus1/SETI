#ifndef VARIABLES_H
#define VARIABLES_H

#include "libs.h"
#include "character.h"
#include "keyboard.h"
#include "info.h"
#include "spell.h"
#include "item.h"
#include "userInterface.h"
#include "Texolder.h"
#include "map.h"

class variables{
    public:
        variables(); //Initialization function
        //-Console-----------------------------------------
        struct consoleMsg{bool update=true; SDL_Surface* surface=NULL; SDL_Texture* texture=NULL; std::vector<std::string> textInfo;};
        consoleMsg consoleVariables,consoleMessages;
        bool consoleShow=false,consoleOnce[1];
        SDL_Window* console_window=NULL; //Console window
        std::string consoleScreenName="Console";
        const int CONSOLE_SCREEN_WIDTH=500;
        const int CONSOLE_SCREEN_HEIGHT=500;
        SDL_SysWMinfo ConsoleWindowInfo; //Console window information holder
        HWND console_hwnd; //Console window handler/owner
        SDL_Renderer* consoleRenderer=NULL; //Console's palette used for presenting the console with pixel data
        SDL_Surface *consoleSurface=NULL;
        SDL_Texture* consoleTexture=NULL;
        SDL_Rect consoleRect;
        //-OpenGL------------------------------------------
        layer imageOpenGL,imageOpenGL2;
        enum stages{
            STAGE_SDL,
            STAGE_OPENGL
        };
        int GLStage=STAGE_SDL;
        //-Other-------------------------------------------
        layer iconMain,iconDebug;
        enum menus{
            MENU_START,
            MENU_GAME
        };
		int currentMenu = MENU_GAME;
        enum renderTypes{
            RENDER_MIPMAP,
            RENDER_NEAREST
        };
        int RenderType=RENDER_MIPMAP;
        enum enumObjects{
            OBJECT_PLAYER,
            OBJECT_SCREEN
        };
        int moveObject=OBJECT_PLAYER;
        GLfloat rotationAngle=0.f;
        SDL_GLContext GLContext;
        SDL_Renderer* renderer=NULL; //The main palette used for presenting the main application with pixel data
        SDL_Window* window=NULL; //Main application window
        SDL_SysWMinfo WindowInfo; //Application window information holder
        SDL_Event e; //User input event holder
        TTF_Font* font=NULL;//font for regular numbers [for now only used in inventory]
            int fontSize=14;
        TTF_Font* font_calibri=NULL;//font for bars' numbers
            int font_calibriSize=36;
        TTF_Font* font_lithosPro=NULL;//font for the name of the class/rank and level in character UI
		int font_lithosProSize = 36;
        TTF_Font* font_lithosProForLevel=NULL;//font for the name of the class/rank and level in character UI
		int font_lithosProForLevelSize = 50;
        float characterUiZoom=(float)1/(float)3;
        layer message,message2,messageSlash;
		SDL_Color messageColor,messageColorPressed,additionColor,levelColor;
        HWND hwnd; //Main application window handler/owner
        std::vector<map> maps;
        std::vector<int> battleEnemiesIds;//hold the ids' for the enemies that are being fought;
        std::vector<SDL_Color> obstructions; //Color holder for those colors which should be impossible to pass for the player [should be used for secret layer]
        std::vector<keyboard> buttons; //Button information holder, used to detect if the user is pressing a specific button on keyboard
        std::vector<SDL_Color> Colors; //Color holder for different areas/zones
        std::vector<spell> Spells; // The spells will be placed here
        std::vector<entity> battleEnemies; //Holder for the enemies during the battle
        std::vector<entity> entities; //Holds all in-game entities
        std::vector<item> items;//Holds all in-game items
        layer progressBar;
        SDL_Surface* slotFrameWithItem=NULL;
        layer itemImage;
		struct img{ layer image; std::string id; }; std::vector<img> images;//Hold all extra images
        bool fullscreen=false; //flag that defines whether or not the application should be launched in full-screen mode
        bool quit=false; //flag that controls the program
        bool bordersAreAThing=true; //you did not see this =.=
        int timeStamp=0; //current time for program
        int frame=0; //current frame;
        int mouseButton=0;
        int leftMouseButton=0;
        int rightMouseButton=0;
        int leftMouseButtonUp=0;
        int rightMouseButtonUp=0;
		SDL_Point mouse, offset, mouseOffsetFromMovableObject,
				  screenStartPosition; //[x;y] point that defines where the main application window should start relatively to the top left corner of the main screen
		int doubleLeftClick=-1;
        int selectedId=-1;
        int antialiasing=1;
        int ammountOfMaps=0; //holder for how many maps there are
        int battleZoneId=0; //Holds information in witch zone, corresponding to this ID,  the battle is taking place in
        int FPS=60; //Amount of frames in a second
        int delay=1000/FPS; //Amount of time to wait before going to the next frame in milliseconds
        int SCREEN_WIDTH=1280; //Application screen width in pixels
        int SCREEN_HEIGHT=720; //Application screen height in pixels
        int mouseWheelMotion=0; //Holder of mouse wheel interaction
        int sections=0; //Amount of rows in the inventory
        int sliderCountForOneRow=5;
        float sliderSpeed=10; //Speed that the slider goes in;
        float tatssbatm=0; //Total Amount The Slider Should Be Able To Move - TATSSBATM
        bool blend=false;
        std::string screenName="SP [Summer-Project]"; //The name of the applications' main window
        std::string clickedOn="";
		struct mo{ layer* layerp = nullptr; std::string objectName = ""; itemStack* ist; SDL_Rect From; int slotId; space* inventory; };//movable object
		mo drag;
        MSG messages; //Some kind of weird windows thing that should be left alone
        //-Menu--------------------------------------------
        struct chance{int from,width;};
        struct buttn{
            layer button[2];
        };
        struct fl{
            SDL_Point startPoint,endPoint,location;
            bool direction,rotationDirection;
			int lifetime, creationTimeStamp, flameId, rotationSpeed;
			float delta, initialSize, endingSize, oscillationSpeed, oscillationInitialAmplitude, oscillationEndingAmplitude, r = 255.f, g = 255.f, b = 255.f;
        };
        struct mnu{
            int chanceToCreateFlameEachFrame;
            chance flameStartLine,flameEndLine,flameLifeTime;
            buttn about,close,options,play;
            layer background,gradient,logo,flameParticle[3];
            std::vector<fl> flames;
        };
        mnu menu;
        //-------------------------------------------------
};

#endif // VARIABLES_H
