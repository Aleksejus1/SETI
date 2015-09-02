#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "libs.h"
#include "layer.h"

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
		struct scrollBar{
			int			
				sliderWidth = 0;
			float		
				speed = 0.f,
				barHeight = 0.f,
				bubbleHeight = 0.f,
				overallHeight = 0.f,
				defaultHeight = 0.f,
				ratioBetweenBarAndOther = 0.f,
				countOfSlidesForOneUnit = 0.f,
				furthestPossibleSliderLocation = 0.f,
				unitConversionValue = 0.f,
				barOffset = 0.f;
			SDL_Point	
				location;
			void initialize(float BubbleHeight, int SliderWidth, float DefaultHeight, float OverallHeight, float UnitConversionValue, float CountOfSlidesForOneUnit, bool update = true){
				bubbleHeight = BubbleHeight;
				sliderWidth = SliderWidth;
				defaultHeight = DefaultHeight;
				overallHeight = OverallHeight;
				unitConversionValue = UnitConversionValue;
				countOfSlidesForOneUnit = CountOfSlidesForOneUnit;
				if(update) updateValues();
			}
			void updateValues(){
				if (overallHeight <= defaultHeight) defaultHeight = overallHeight;
				barHeight = bubbleHeight / (1 + overallHeight - defaultHeight);
				speed = barHeight / countOfSlidesForOneUnit;
				furthestPossibleSliderLocation = bubbleHeight - barHeight;
				if (barOffset > furthestPossibleSliderLocation) barOffset = furthestPossibleSliderLocation;
				ratioBetweenBarAndOther = (overallHeight - defaultHeight)*unitConversionValue / furthestPossibleSliderLocation;
			}
		};
		struct QuestsTab : tab, closeButton{
			scrollBar ScrollBar;
			layer details;
			int questsIconWH = 0, //quests icons width and height
				distanceBetweenQuests = 0;
			float QRectW = 0.f,
				  QRectH = 0.f;
			std::string 
				clickedQuest;
			bool 
				expand;
			SDL_Point questIconOffset;
			SDL_Rect questsRenderArea;
		};
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