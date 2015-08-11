#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "libs.h"
#include "layer.h"
#include "Texolder.h"

class functions;

class userInterface{
    public:
        userInterface(functions *fp);
		functions *f;
		struct butt{ layer state[2]; int currentState = 0; };
		struct messageAndCount{ layer message; float* countAmount; bool* update; };
		struct barAndUpdate : messageAndCount { layer bar; };
		struct bars : barAndUpdate { layer max_count; float* max_countAmount; };
		struct tab{
			layer imageMain;
			float zoom;
			SDL_Point location;
			bool open = false;
		};
		struct Cat{
			layer image;
			std::string name="";
		};
		struct closeButton{
			SDL_Point closeButtonOffsetFromTopRight;
			SDL_Rect closeButtonLocation;
		};
		struct StatsTab : tab, closeButton{
			Uint8 currentSubTab = 0;
			SDL_Point topLeftLocationOfStats;
			float distanceBetweenStats = 0;
			int distanceBetweenCats = 0,
				catsTopYLocation = 0;
			Cat category[3];
		};
		struct QuestsTab : tab, closeButton{
			layer details;
			int questsIconWH = 0, //quests icons width and height
				distanceBetweenQuests = 0,
				furthestPossibleSliderLocation = 0;
			float QRectW = 0.f,
				  QRectH = 0.f,
				  scrollBarOffset = 0.f,
				  sliderSpeed = 0.f;
			std::string clickedQuest;
			bool expand;
			SDL_Point questIconOffset,
					  slotLocationTopLeftBase;
			SDL_Rect questsRenderArea;
		};
        Texolder botUItxl;
        layer bar_empty,
			  characterUI,
			  botUI,
			  topUIReflection;
		int botUIDistanceBetweenButtons = 0, 
			topUIDistanceBetweenButtons[3];
        SDL_Point botUIButtonsTopLeftLocation,
			      topUIButtonsTopLeftLocation;
        butt botUIButtons[4],
			 topUIButtons[3];
        messageAndCount level;
        barAndUpdate bar_green;
        bars bar_red,
			 bar_blue,
			 bar_grey;
        bars* all[3];
		StatsTab TabStats;
		QuestsTab TabQuests;
};

#endif // USERINTERFACE_H