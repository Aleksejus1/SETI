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
			bool open = false;
		};
		struct Cat{
			layer image;
			std::string name="";
		};
		struct StatsTab : tab{
			Uint8 currentSubTab = 0;
			SDL_Point topLeftLocationOfStats;
			float distanceBetweenStats = 0;
			int distanceBetweenCats = 0,
				catsTopYLocation = 0;
			Cat category[3];
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
};

#endif // USERINTERFACE_H