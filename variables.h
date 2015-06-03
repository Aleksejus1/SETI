#ifndef VARIABLES_H
#define VARIABLES_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_syswm.h"
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
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <commdlg.h>
#include "character.h"
#include "keyboard.h"
#include "info.h"
#include "spell.h"
#include "item.h"

class variables
{
    public:
        variables(); //Initialization function
        SDL_Renderer* renderer=NULL; //The main palette used for presenting the main application with pixel data
        SDL_Window* window=NULL; //Main application window
        SDL_SysWMinfo WindowInfo; //Application window information holder
        SDL_Event e; //User input event holder
        TTF_Font* font=NULL;
        int fontSize=14;
        SDL_Surface* message;
        SDL_Color messageColor={255,255,255,255};
        HWND hwnd; //Main application window handler/owner
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
        struct image{layer image;std::string id;}; std::vector<image> images;//Hold all extra images
        bool fullscreen=false; //flag that defines whether or not the application should be launched in full-screen mode
        bool quit=false; //flag that controls the program
        bool bordersAreAThing=true; //you did not see this =.=
        int mouseButton=0;
        SDL_Point mouse;
        int selectedId=-1;
        int antialiasing=0;
        int ammountOfMaps=0; //holder for how many maps there are
        int battleZoneId=0; //Holds information in witch zone, corresponding to this ID,  the battle is taking place in
        int FPS=60; //Amount of frames in a second
        int delay=1000/FPS; //Amount of time to wait before going to the next frame in milliseconds
        int SCREEN_WIDTH=1280; //Application screen width in pixels
        int SCREEN_HEIGHT=720; //Application screen height in pixels
        int mouseWheelMotion=0; //Holder of mouse wheel interaction
        int inventorySlotsPerRow=4; //Amount of slots in a single inventory row
        int distanceBetweenSlots=0; //Pixel distance between slots in the inventory
        int sections=0; //Amount of rows in the inventory
        float sliderSpeed=10; //Speed that the slider goes in;
        float tatssbatm=0; //Total Amount The Slider Should Be Able To Move - TATSSBATM
        SDL_Point screenStartPosition={128,130}; //[x;y] point that defines where the main application window should start relatively to the top left corner of the main screen
        std::string screenName="SP [Summer-Project]"; //The name of the applications' main window
        character player; //Player information holder
        MSG messages; //Some kind of weird windows thing that should be left alone
};

#endif // VARIABLES_H
