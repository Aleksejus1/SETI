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
#include "quest.h"

class variables{
    public:
        variables(); //Initialization function
        /*OpenGL*/	
        layer imageOpenGL,imageOpenGL2;
        enum stages{
            STAGE_SDL,
            STAGE_OPENGL
        };
        int GLStage=STAGE_SDL;
        /*Other*/   
		/*enum*/		
		enum menus{ MENU_START, MENU_GAME };
		enum enumObjects{ OBJECT_PLAYER, OBJECT_SCREEN };
		enum taskTypes{TASK_GET_ITEM, TASK_ENUM_COUNT};
		/*struct*/		
		struct img{ layer image; std::string id; }; std::vector<img> images;//Hold all extra images
		struct mo{ layer* layerp = nullptr; std::string objectName = ""; itemStack* ist; SDL_Rect From; int slotId; space* inventory; };//movable object
		struct channe{ int startMenu = -2; } channel;
		struct chance{ int from, width; };
		struct buttn{ layer button[2]; };
		struct fl{
			SDL_Point startPoint, endPoint, location;
			bool direction, rotationDirection;
			int lifetime, creationTimeStamp, flameId, rotationSpeed;
			float delta, initialSize, endingSize, oscillationSpeed, oscillationInitialAmplitude, oscillationEndingAmplitude, r = 255.f, g = 255.f, b = 255.f;
		};
		struct mnu{
			float pulseMaxAlpha = 0.5f;
			bool pulseState = true;
			int chanceToCreateFlameEachFrame,
				pulseLength = 0,
				pulseTimeStamp = 0;
			chance flameStartLine, flameEndLine, flameLifeTime;
			buttn about, close, options, play;
			layer background, gradient, logo, flameParticle[3], pulse;
			std::vector<fl> flames;
		};
		libs::SDL_Colorf
			colorfSliderBC = { 0.f, 0.f, 0.f, 94.f / 255.f },
			colorfSliderBar = { 0.f, 0.f, 0.f, 220.f / 255.f };
		layer			
			iconMain, //main window icon
			iconDebug, //debug window icon
			cursorImage, //cursor image
			message, //message layer holder #1
			message2, //message layer holder #2
			messageSlash, //layer holder of "/" symbol
			empty, //empty texture that has 1x1 white pixel
			progressBar; //progress bar holder of all info that makes the progress bar
		int				
			currentMenu = MENU_GAME,
			moveObject = OBJECT_PLAYER,
			fontSize = 14,
			milisecond = 0,
			font_calibriSize = 36,
			font_lithosProSize = 36,
			font_lithosProForStatsSize = 64,
			font_lithosProForLevelSize = 50,
			timeStamp = 0, //current time for program
			frame = 0, //current frame;
			mouseButton = 0,
			leftMouseButton = 0,
			rightMouseButton = 0,
			leftMouseButtonUp = 0,
			rightMouseButtonUp = 0,
			doubleLeftClick = -1,
			selectedId = -1,
			antialiasing = 1,
			ammountOfMaps = 0, //holder for how many maps there are
			battleZoneId = 0, //Holds information in witch zone, corresponding to this ID,  the battle is taking place in
			FPS = 60, //Amount of frames in a second
			SCREEN_WIDTH = 1280, //Application screen width in pixels
			SCREEN_HEIGHT = 720, //Application screen height in pixels
			mouseWheelMotion = 0, //Holder of mouse wheel interaction
			sections = 0; //Amount of rows in the inventory
		GLfloat			
			rotationAngle=0.f;
		SDL_GLContext	
			GLContext;
		SDL_Renderer	
			*renderer=NULL; //The main palette used for presenting the main application with pixel data
		SDL_Window		
			*window=NULL; //Main application window
		SDL_SysWMinfo	
			WindowInfo; //Application window information holder
		SDL_Event		
			e; //User input event holder
		TTF_Font		
			*font_calibri = NULL,//font for bars' numbers
			*font_lithosPro = NULL,//font for the name of the class/rank and level in character UI
			*font_lithosProForStats = NULL,//font for the name of the class/rank and level in character UI
			*font_lithosProForLevel = NULL;//font for the name of the class/rank and level in character UI
		SDL_Color		
			messageColorPressed,
			additionColor,
			levelColor;
		/*std::vector*/	
		std::vector<std::string> taskType;
		std::vector<quest> quests;
		std::vector<map> maps;
        std::vector<int> battleEnemiesIds;//hold the ids' for the enemies that are being fought;
        std::vector<SDL_Color> obstructions; //Color holder for those colors which should be impossible to pass for the player [should be used for secret layer]
        std::vector<keyboard> buttons; //Button information holder, used to detect if the user is pressing a specific button on keyboard
        std::vector<SDL_Color> Colors; //Color holder for different areas/zones
        std::vector<spell> Spells; // The spells will be placed here
        std::vector<entity> battleEnemies, //Holder for the enemies during the battle
                            entities; //Holds all in-game entities
        std::vector<item> items;//Holds all in-game items
		bool			
			fullscreen=false, //flag that defines whether or not the application should be launched in full-screen mode
			quit = false, //flag that controls the program
			bordersAreAThing = true, //you did not see this =.=
			blend = false;
		float const		
			LAYER_UI = -1.f,
			LAYER_ENTITY = -2.f,
			LAYER_BACKGROUND = -3.f;
		float			
			characterUiZoom = 1.f / 3.f,
			milisecondOffset = 0,
			delay = 1000.f / FPS, //Amount of time to wait before going to the next frame in milliseconds
			tatssbatm = 0.f; //Total Amount The Slider Should Be Able To Move - TATSSBATM
		POINT			
			mousePoint;
		SDL_Point		
			windowPos,
			mouse,
			offset,
			mouseOffsetFromMovableObject,
			screenStartPosition; //[x;y] point that defines where the main application window should start relatively to the top left corner of the main screen
		std::string		
			screenName="SP [Summer-Project]", //The name of the applications' main window
			clickedOn = "";
		mo				
			drag;
		MSG				
			messages; //Some kind of weird windows thing that should be left alone
        mnu				
			menu;
		Mix_Music		
			*musicStartMenu = NULL;
		Mix_Chunk		
			*sfxStartMenu = NULL;
};

#endif // VARIABLES_H