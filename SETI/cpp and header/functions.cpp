#include "functions.h"

functions::functions():
UI(this),
player(this){
    if(true){//stuff
		for (int i = 0; i < TASK_ENUM_COUNT; i++){
			taskType.push_back("");
		}
		for (int i = 0; i < 3; i++){
			userInterface::bars &bar = *UI.all[i];
			switch (i){
			case 0:
				bar.update			= &player.updateHealth;
				bar.countAmount		= &player.healthPoints;
				bar.max_countAmount = &player.healthPointsMax;
				break;
			case 1:
				bar.update			= &player.updateMana;
				bar.countAmount		= &player.manaPoints;
				bar.max_countAmount = &player.manaPointsMax;
				break;
			case 2:
				bar.update			= &player.updateExperience;
				bar.countAmount		= &player.experiencePoints;
				bar.max_countAmount = &player.experienceRequiredForNextLevel;
				break;
			}
			bar.max_count.z = LAYER_UI;
			bar.message.z	= LAYER_UI;
		}
        UI.bar_green.update=&player.updateType;
		UI.bar_green.message.z = LAYER_UI;
		UI.level.update = &player.updateLevel; UI.level.countAmount = &player.level;
		UI.level.message.z = LAYER_UI;
        player.healthPointsMax=999.0;
        player.addHealth(player.healthPointsMax-333);
        player.manaPointsMax=820.0;
        player.addMana(player.manaPointsMax-800);
        player.experienceRequiredForNextLevel=100.0;
        player.addExperience(125.0);
        player.location.x=320;//sets the starting x position of the player
        player.location.y=420;//sets the starting y position of the player
        player.map_location=1;//sets the starting map id of the player
        player.inventory.addItemStacks(
			(2+8)*4+2
			//10
			);
        player.setType("EGYPTIAN WARRIOR");
        addColor(0,0,0);
        addColor(255,0,0);
        addColor(0,255,0);
        addColor(0,0,255);
    }
    if(true){//flame particle stuff
		if (menu.type == menu.OLD) {
			menu.chanceToCreateFlameEachFrame=FPS/10;
			menu.flameStartLine.from = { 0 , SCREEN_HEIGHT + SCREEN_HEIGHT / 2 };
			menu.flameStartLine.to = { SCREEN_WIDTH * 1 / 3 , menu.flameStartLine.from.y };
			menu.flameEndLine.from = { 0 , (int)(SCREEN_HEIGHT * 1.1) };
			menu.flameEndLine.to = { SCREEN_WIDTH * 5 / 8 , menu.flameEndLine.from.y };
			menu.flameLifeTime = { 600 , 1400 };
		}
		else {
			menu.chanceToCreateFlameEachFrame = FPS / 10;
			menu.flameStartLine.from = { SCREEN_WIDTH * (-1) / 3 , SCREEN_HEIGHT + 200 };
			menu.flameStartLine.to = { menu.flameStartLine.from.x * (-2) + SCREEN_WIDTH , menu.flameStartLine.from.y };
			menu.flameEndLine.from = { 0 , 0 };
			menu.flameEndLine.to = { SCREEN_WIDTH , 0 };
			menu.flameLifeTime = { 600 , 1400 };
		}
    }
}

//operators			
bool operator==(const layer& layer1, const layer& layer2){
	if (layer1.textureOpenGL == layer2.textureOpenGL &&
		layer1.surface == layer2.surface &&
		layer1.zoomWidth == layer2.zoomWidth &&
		layer1.zoom == layer2.zoom &&
		layer1.zoomHeight == layer2.zoomHeight &&
		layer1.color.r == layer2.color.r &&
		layer1.color.g == layer2.color.g &&
		layer1.color.b == layer2.color.b &&
		layer1.color.a == layer2.color.a)
		return true;
	return false;
}
bool operator!=(const layer& layer1, const layer& layer2){
	return(!(layer1 == layer2));
}
bool operator==(const item& item1, const item& item2){
	if (item1.name == item2.name&&
		item1.damage == item2.damage &&
		item1.image == item2.image &&
		item1.type == item2.type &&
		item1.affectedStats.size() == item2.affectedStats.size()){
		for (Uint8 i = 0; i < item1.affectedStats.size(); i++){
			if (item1.affectedStats[i].ammount != item2.affectedStats[i].ammount ||
				item1.affectedStats[i].statName != item2.affectedStats[i].statName)
				return false;
		}
		return true;
	}
	return false;
}
bool operator!=(const item& item1, const item& item2){
	return(!(item1 == item2));
}
SDL_Point operator*(const SDL_Point& point1, const int& int2){
	return{ point1.x * int2, point1.y * int2 };
}
SDL_Point operator+(const SDL_Point& point1, const int& int2){
	return { point1.x + int2, point1.y + int2 };
}
SDL_Point operator*(const SDL_Point& point1, const float& float2){
	return{ (int)(point1.x * float2), (int)(point1.y * float2) };
}
SDL_Point operator+(const SDL_Point& point1, const SDL_Point& point2){
	return{ point1.x + point2.x, point1.y + point2.y };
}
SDL_Point operator-(const SDL_Point& point1, const SDL_Point& point2){
	return{ point1.x - point2.x, point1.y - point2.y };
}
SDL_Point operator+(const SDL_Point& point1, const SDL_Rect& rect2){
	return{ point1.x + rect2.x, point1.y + rect2.y };
}
SDL_Point operator-(const SDL_Point& point1, const SDL_Rect& rect2){
	return point1*(-1)+rect2;
}
SDL_Rect operator+(const SDL_Rect& rect, const SDL_Point& point){
	return{ rect.x + point.x, rect.y + point.y, rect.w, rect.h };
}
SDL_Rect operator*(const SDL_Rect& rect, const float& fl){
	return{ (int)(rect.x*fl), (int)(rect.y*fl), rect.w, rect.h };
}

void functions::loadMedia(){
	player.inventory.location = { 50,50 };
	//add buttons			
	addButton("Always false",	SDLK_d);
	addButton("D",				SDLK_d);
	addButton("A",				SDLK_a);
	addButton("S",				SDLK_s);
	addButton("W",				SDLK_w);
	addButton("Right",			SDLK_RIGHT);
	addButton("Left",			SDLK_LEFT);
	addButton("Down",			SDLK_DOWN);
	addButton("Up",				SDLK_UP);
	addButton("F",				SDLK_f);
	addButton("G",				SDLK_g);
	addButton("E",				SDLK_e);
	addButton("I",				SDLK_i);
	addButton("O",				SDLK_o);
	addButton("Left Shift",		SDLK_LSHIFT);
	addButton("N",				SDLK_n);
	addButton("Esc",			SDLK_ESCAPE);
	addButton("Z",				SDLK_z);
	addButton("Q",				SDLK_q);
	addButton("R",				SDLK_r);
	addButton("P",				SDLK_p);
	addButton("Tab",			SDLK_TAB);
	addButton("1",				SDLK_KP_1);
	addButton("2",				SDLK_KP_2);
	addButton("3",				SDLK_KP_3);
	addButton("4",				SDLK_KP_4);
	addButton("5",				SDLK_KP_5);
	addButton("6",				SDLK_KP_6);
	addButton("7",				SDLK_KP_7);
	addButton("8",				SDLK_KP_8);
	addButton("9",				SDLK_KP_9);
	addButton("+",				SDLK_KP_PLUS);
	addButton("-",				SDLK_KP_MINUS);
	addButton("Enter",			SDLK_RETURN);
	addButton("NUM_Enter",		SDLK_KP_ENTER);
	//extra					
	loadImage("Graphics\\empty.png", empty);
	//load audio			
	/*music*/				     
	loadSoundEffect(sfxStartMenu, "Audio\\Music\\3.wav");
	/*sound effect*/
	//create TASK_TYPES     
	taskType[TASK_GET_ITEM] = "GET_ITEM";
	//create Quests			
	for (int i = 0; i < 3; i++){
		quest& q = createQuest();
		switch (i){
		case 0:
			loadImage("qpm\\questIcon.png", q.icon); q.icon.z = LAYER_UI;
			q.setDescription("This is actually a lot of writing for me :(");
			q.setShortDescription(("#01 A sphinx is a mythical creature with, as a minimum, the head of a human and the bodyb of a lion\n"
				"In Greek tradition, it has the head of a guman, the haynches of a lion andd sometimes the wings of a bird. it is mythicised as treacherous and merciless. Those who cannot answer its riddle suffer a fate typical in such mythological stories, as they are killed and eaten by this .ravenous monster"
				"In Greek tradition, it has the head of a guman, the haynches of a lion andd sometimes the wings of a bird. it is mythicised as treacherous and merciless. Those who cannot answer its riddle suffer a fate typical in such mythological stories, as they are killed and eaten by this .ravenous monster"));
			q.addTask(taskType[TASK_GET_ITEM], createTask_GetItem("Berry", 2));
			q.setName("#01 Awenge the lost soul!");
			break;
		case 1:
			loadImage("qpm\\questIcon.png", q.icon); q.icon.z = LAYER_UI;
			q.setDescription("This is actually a lot of writing for me :(");
			q.setShortDescription(("#02 A sphinx is a mythical creature with, as a minimum, the head of a human and the bodyb of a lion\n"
				"In Greek tradition, it has the head of a guman, the haynches of a lion andd sometimes the wings of a bird. it is mythicised as treacherous and merciless. Those who cannot answer its riddle suffer a fate typical in such mythological stories, as they are killed and eaten by this .ravenous monster"
				"In Greek tradition, it has the head of a guman, the haynches of a lion andd sometimes the wings of a bird. it is mythicised as treacherous and merciless. Those who cannot answer its riddle suffer a fate typical in such mythological stories, as they are killed and eaten by this .ravenous monster"));
			q.addTask(taskType[TASK_GET_ITEM], createTask_GetItem("Berry", 2));
			q.setName("#02 Return to the cave...");
			break;
		case 2:
			loadImage("qpm\\questIcon.png", q.icon); q.icon.z = LAYER_UI;
			q.setDescription("This is actually a lot of writing for me :(");
			q.setShortDescription(("#03 A sphinx is a mythical creature with, as a minimum, the head of a human and the bodyb of a lion\n"
				"In Greek tradition, it has the head of a guman, the haynches of a lion andd sometimes the wings of a bird. it is mythicised as treacherous and merciless. Those who cannot answer its riddle suffer a fate typical in such mythological stories, as they are killed and eaten by this .ravenous monster"
				"In Greek tradition, it has the head of a guman, the haynches of a lion andd sometimes the wings of a bird. it is mythicised as treacherous and merciless. Those who cannot answer its riddle suffer a fate typical in such mythological stories, as they are killed and eaten by this .ravenous monster"));
			q.addTask(taskType[TASK_GET_ITEM], createTask_GetItem("Berry", 2));
			q.setName("#03 Return from the village?");
			break;
		}
	}
	//create player         
    loadImage("qpm\\player.png",player.image);
	player.image.z = LAYER_ENTITY;
	player.quests.push_back(quests[0]);
	player.quests.push_back(quests[1]);
	player.quests.push_back(quests[2]);
	//add obstructions      
    addObstruction(0,0,10,255);
    addObstruction(0,0,200,255);
	//add spells/attacks	
    addSpell("Spell", 1337, 0, "qpm\\1st spell.png", "qpm\\icon_active.png", "qpm\\icon_cooldown.png", 50,50);
    Spells[0].icon_active.setWidthZoom((float)50/(float)Spells[0].icon_active.surface->w);
    Spells[0].icon_active.setHeightZoom((float)50/(float)Spells[0].icon_active.surface->h);
    Spells[0].icon_cooldown.setWidthZoom((float)50/(float)Spells[0].icon_cooldown.surface->w);
    Spells[0].icon_cooldown.setHeightZoom((float)50/(float)Spells[0].icon_cooldown.surface->h);
	//create entities/mobs  
	for (int i = 0; i < 7; i++){
		std::string name; SDL_Point legCenter;
		switch (i){
		case 0: name = "Zombie";		legCenter = { 184, 478 }; break;
		case 1: name = "Zombie_mini";	legCenter = { 184, 478 }; break;
		case 2: name = "debug_1";		legCenter = { 147, 488 }; break;
		case 3: name = "debug_2";		legCenter = { 147, 488 }; break;
		case 4: name = "debug_3";		legCenter = { 147, 488 }; break;
		case 5: name = "debug_4";		legCenter = { 147, 488 }; break;
		case 6: name = "debug_5";		legCenter = { 147, 488 }; break;
		}
		if(i!=1) addEntity(20.0, 1, 0.0, name, "qpm\\" + name + ".png", legCenter.x, legCenter.y);
		else  addEntity(20.0, 1, 0.0, name, "qpm\\Zombie.png", legCenter.x, legCenter.y);
		entities[entities.size() - 1].image.setZoom((float)player.image.surface->h / (float)entities[entities.size() - 1].image.surface->w);
		entities[entities.size() - 1].image.z = LAYER_ENTITY;
	}
	//create images         
    createImage("qpm\\base.png","base");
    images[images.size()-1].image.setZoom(0.35f);
    createImage("qpm\\progressBarFrame.png","progressBarFrame");
    createImage("qpm\\progressBarInside.png","progressBarInside");
	/*create UI*/	        
	//create Battle UI           
    createImage("qpm\\BattleUI.png","battleUI");
    images[images.size()-1].image.setZoom((float)SCREEN_WIDTH/(float)images[images.size()-1].image.surface->w);
	images[images.size() - 1].image.z = LAYER_UI;
	//create Character UI        
	for (int i = 0; i < 6; i++){
		std::string name; layer *layerp; float offset;
		switch (i){
		case 0: name = "ui_character_v1";	layerp = &UI.characterUI;						break;
		case 1: name = "empty_bar";			layerp = &UI.bar_empty;							break;
		case 2: name = "red_bar";			layerp = &UI.bar_red.bar;	 offset = 192.f;	break;
		case 3: name = "blue_bar";			layerp = &UI.bar_blue.bar;	 offset = 237.f;	break;
		case 4: name = "grey_bar";			layerp = &UI.bar_grey.bar;	 offset = 281.f;	break;
		case 5: name = "green_bar";			layerp = &UI.bar_green.bar;	 offset = 343.f;	break;
		}
		loadImage("Graphics\\Top Left UI\\" + name + ".png", *layerp);
		layerp->setZoom(characterUiZoom);
		layerp->z = LAYER_UI;
		if (i > 1){
			layerp->offset.x = (int)(UI.characterUI.w * 360.f / 1113.f);
			layerp->offset.y = (int)(UI.characterUI.h * offset / 471.f);
		}
	}
	//create Inventory Interface 
    /*set some values*/             
	characterSpace &pi = player.inventory;
	pi.slotsInOneRow	= 4;
	pi.name				= "Player Inventory";
	pi.rowsInInventory	= pi.itemStacks.size() / pi.slotsInOneRow;
	if (pi.itemStacks.size() % pi.slotsInOneRow != 0) pi.rowsInInventory++;
	pi.distanceBetweenSlots			=	(int)(pi.zoom * 267);
	pi.distanceBetweenEquipmentSlots=	(int)(pi.zoom * 264);
	pi.scrollBar.initialize(400, 5, 8, (float)pi.rowsInInventory, (float)pi.distanceBetweenSlots, 5.f);
	pi.distanceBetweenStats			=	(int)(pi.zoom * 144);
	pi.closeLocation				= { (int)(pi.zoom * 2120),	(int)(pi.zoom * 105)	};
	pi.statTopLeftLocation			= { (int)(pi.zoom * 215),	(int)(pi.zoom * 1516)	};
	pi.slotLocationTopLeftBase		= { (int)(pi.zoom * 1298),	(int)(pi.zoom * 185)	};
	pi.scrollBar.location			= { (int)(pi.zoom * 2354),	pi.slotLocationTopLeftBase.y };
	pi.equipmentTopLeftLocation		= { (int)(pi.zoom * 297),	(int)(pi.zoom * 181)	};
	//load images                   
	std::string prePath = "Graphics\\equipment ui slice\\", endingPath = ".png", text; layer* layeRef; //Texolder& txl = pi.txl;
	for(int i=0; i<pi.equipmentCount; i++){
        loadImage(prePath+pi.equipmentAll[i]->typeName+endingPath,pi.equipmentAll[i]->image);
            pi.equipmentAll[i]->image.setZoom(pi.zoom);
			pi.equipmentAll[i]->image.z = LAYER_UI;
	}
	for(int i=0; i<3; i++){
        switch(i){
            case 0: layeRef=&pi.imageInventorySlot[0]; text="inventory_slot";         break;
            case 1: layeRef=&pi.imageInventorySlot[1]; text="inventory_slot_pressed"; break;
            case 2: layeRef=&pi.imageMain;             text="main_body";              break;
        }
        loadImage(prePath+text+endingPath,*layeRef);
            layeRef->setZoom(pi.zoom);
			layeRef->z = LAYER_UI;
	}
	for(int i=0; i<(int)player.stats[0].size(); i++){
		loadImage(prePath + "abilities\\" + toString(i + 1) + endingPath, player.stats[0][i].image);
		player.stats[0][i].image.z = LAYER_UI;
	}
	for(int i=0; i<4; i++){
        std::string color;
        int type=0;
        switch(i){
            case 0: color="green";  type=1; break;
            case 1: color="grey";   type=1; break;
            case 2: color="blue";   break;
            case 3: color="orange"; break;
        }
        characterSpace::bars bar;
        if(type==0){
            loadImage(prePath+"bars\\"+color+" gradient"+endingPath,bar.gradient);
                //bar.gradient.setZoom(pi.zoom*zoomMulti);
            bar.gradient.textureOpenGL=convertSurfaceToOpenGLTexture(bar.gradient.surface);
			bar.gradient.z = LAYER_UI;
        }
        loadImage(prePath+"bars\\"+color+" left"+endingPath,bar.left);
        loadImage(prePath+"bars\\"+color+" mid"+endingPath,bar.mid);
        loadImage(prePath+"bars\\"+color+" right"+endingPath,bar.right);
        createSurface(&bar.full.surface,bar.left.surface->w+bar.right.surface->w+444,bar.mid.surface->h);
        copySurface(bar.left.surface,bar.full.surface,bar.left.surface->clip_rect);
        copySurface(bar.right.surface,bar.full.surface,bar.right.surface->clip_rect,bar.full.surface->w-bar.right.surface->w,0);
        for(int o=0; o<bar.full.surface->w-bar.left.surface->w-bar.right.surface->w; o++) copySurface(bar.mid.surface,bar.full.surface,bar.mid.surface->clip_rect,bar.left.surface->w+o,0);
        bar.full.textureOpenGL=convertSurfaceToOpenGLTexture(bar.full.surface);
		bar.full.z = LAYER_UI;
        if(i!=0) pi.statsBar.push_back(bar);
        else pi.additionBar=bar;
	}
	//calculate stuff               
	for (int i = 0; i<pi.slotsInOneRow; i++) pi.slotsLocationsX.push_back((pi.slotLocationTopLeft.x + pi.distanceBetweenSlots*i));
	pi.slotBoundary.w = (pi.slotsInOneRow - 1)*pi.distanceBetweenSlots + pi.imageInventorySlot[0].w;
	pi.slotBoundary.h = 7 * pi.distanceBetweenSlots + pi.imageInventorySlot[0].w;
    //create Bot UI              
		UI.botUIButtonsTopLeftLocation.x = (int)(73 * characterUiZoom);
		UI.botUIButtonsTopLeftLocation.y = (int)(143 * characterUiZoom);
		UI.botUIDistanceBetweenButtons = (int)(202 * characterUiZoom);
        loadImage("Graphics\\Bot UI\\bot_ui_frame.png",UI.botUI);
            UI.botUI.setZoom(characterUiZoom);
			UI.botUI.z = LAYER_UI;
        UI.botUI.to=getRect((SCREEN_WIDTH-UI.botUI.w)/2,SCREEN_HEIGHT-UI.botUI.h,UI.botUI.surface->w,UI.botUI.surface->h);
        std::string UIBotUIName;
        for(int i=0; i<4; i++){
            switch(i){
                case 0: UIBotUIName="inventory"; break;
                case 1: UIBotUIName="stats";     break;
                case 2: UIBotUIName="skills";    break;
                case 3: UIBotUIName="quests";    break;
            }
            loadImage("Graphics\\Bot UI\\icons\\"+UIBotUIName+" idle.png",UI.botUIButtons[i].state[0]);
                UI.botUIButtons[i].state[0].setZoom(characterUiZoom);
				UI.botUIButtons[i].state[0].z = LAYER_UI;
			loadImage("Graphics\\Bot UI\\icons\\" + UIBotUIName + " pressed.png", UI.botUIButtons[i].state[1]);
				UI.botUIButtons[i].state[1].setZoom(characterUiZoom);
				UI.botUIButtons[i].state[1].z = LAYER_UI;
            UI.botUIButtons[i].state[0].from=UI.botUIButtons[i].state[0].surface->clip_rect;
            UI.botUIButtons[i].state[0].to=getRect(UI.botUI.to.x + UI.botUIButtonsTopLeftLocation.x+i*UI.botUIDistanceBetweenButtons,
												   UI.botUI.to.y + UI.botUIButtonsTopLeftLocation.y,
                                                   UI.botUIButtons[i].state[0].surface->w,
                                                   UI.botUIButtons[i].state[0].surface->h);
        }
	//create Top UI              
    loadImage("Graphics\\top menu buttons\\reflection below.png",UI.topUIReflection);
        UI.topUIReflection.setZoom(characterUiZoom);
		UI.topUIReflection.z = LAYER_UI;
    std::string UITopUIName;
    for(int i=0; i<3; i++){
        switch(i){
            case 0: UITopUIName="shop";     break;
            case 1: UITopUIName="settings"; break;
            case 2: UITopUIName="exit";     break;
        }
		for (int o = 0; o < 2; o++){
			std::string state;
			switch (o){
			case 0: state = "idle";  break;
			case 1: state = "click"; break;
			}
			loadImage("Graphics\\top menu buttons\\" + UITopUIName + " " + state + ".png", UI.topUIButtons[i].state[o]);
			UI.topUIButtons[i].state[o].setZoom(characterUiZoom);
			UI.topUIButtons[i].state[o].z = LAYER_UI;
		}
    }
	UI.topUIDistanceBetweenButtons[0] = (int)(0 * characterUiZoom);
	UI.topUIDistanceBetweenButtons[1] = (int)(177 * characterUiZoom);
	UI.topUIDistanceBetweenButtons[2] = (int)(214 * characterUiZoom + UI.topUIDistanceBetweenButtons[1]);
    UI.topUIButtonsTopLeftLocation.x=SCREEN_WIDTH-UI.topUIDistanceBetweenButtons[2]-UI.topUIButtons[0].state[0].w;
    UI.topUIButtonsTopLeftLocation.y=0;
	//load Fonts            
	font = TTF_OpenFont("ttf\\DroidSerif.ttf", fontSize);
	TTF_SetFontStyle(font, TTF_STYLE_BOLD);
	//-------------------------------------------------------------------------------------
	font_calibriSize = (int)(font_calibriSize*characterUiZoom);
	font_calibri = TTF_OpenFont("ttf\\Calibri.ttf", font_calibriSize);
	TTF_SetFontStyle(font_calibri, TTF_STYLE_BOLD);
	//-------------------------------------------------------------------------------------
	font_lithosProSize = (int)(font_lithosProSize*characterUiZoom);
	font_lithosPro = TTF_OpenFont("ttf\\LithosPro.otf", font_lithosProSize);
	TTF_SetFontStyle(font_lithosPro, TTF_STYLE_BOLD);
	//-------------------------------------------------------------------------------------
	font_lithosProForStats = TTF_OpenFont("ttf\\LithosPro.otf", font_lithosProForStatsSize);
	TTF_SetFontStyle(font_lithosProForStats, TTF_STYLE_BOLD);
	//-------------------------------------------------------------------------------------
	font_lithosProForLevel = TTF_OpenFont("ttf\\LithosPro.otf", font_lithosProForLevelSize);
	TTF_SetFontStyle(font_lithosProForLevel, TTF_STYLE_BOLD);
	//-------------------------------------------------------------------------------------
	//create Stats Tab      
	userInterface::StatsTab &UT = UI.TabStats;
	loadImage("Graphics\\rest of ui\\stats\\stats background.png", UT.imageMain);
	UT.zoom = 1.f / 3.f;
	UT.imageMain.setZoom(UT.zoom);
	UT.imageMain.z = LAYER_UI;
	UT.topLeftLocationOfStats = { 150,262 };
	UT.topLeftLocationOfStats = UT.topLeftLocationOfStats * UT.imageMain.zoom;
	UT.distanceBetweenStats = 148 * UT.imageMain.zoom;
	UT.distanceBetweenCats = (int)(50 * UT.imageMain.zoom);
	UT.catsTopYLocation = (int)(186 * UT.imageMain.zoom);
	int total=2*UT.distanceBetweenCats;
	for (int i = 0; i < 3; i++){
		std::string name;
		switch (i){
		case 0: name = "Long ass name"; break;
		case 1: name = "shorter"; break;
		case 2: name = "Sh"; break;
		}
		UT.category[i].name = name;
		writeMessage(name, UT.category[i].image, messageColor, font_lithosProForStats);
		UT.category[i].image.setZoom(3.f/5.f*UT.imageMain.zoom);
		UT.category[i].image.z = LAYER_UI;
		total += UT.category[i].image.w;
	}
	for (int i = 0; i < 3; i++){
		if(i==0) UT.category[i].image.to.x = (UT.imageMain.w-total)/2;
		else UT.category[i].image.to.x = UT.category[i - 1].image.to.x + UT.category[i - 1].image.w + UT.distanceBetweenCats;
	}
	character::stat* ps;//player.stats[0][i];
	characterSpace::bars& pis = player.inventory.statsBar[1];
	for (Uint8 i = 0; i < player.stats[0].size(); i++){
		ps = &player.stats[0][i];
		ps->statNameLayer.to.x = ps->image.w;
		ps->statNameLayer.z = LAYER_UI;
		ps->levelBaseLayer.to.x = ps->statNameLayer.to.x + 500;
		ps->levelBaseLayer.z = LAYER_UI;
		ps->levelAdditionLayer.z = LAYER_UI;
		ps->mainBar.from = pis.full.surface->clip_rect;
		ps->mainBar.to = getRect(ps->levelBaseLayer.to.x - pis.full.surface->w / 10, 0, ps->mainBar.from.w, ps->mainBar.from.h);
		ps->additionBar.from = player.inventory.additionBar.full.surface->clip_rect;
		ps->additionBar.to = getRect(ps->mainBar.to.x, 0, ps->additionBar.from.w, ps->additionBar.from.h);
		ps->gradientBar.from = pis.gradient.surface->clip_rect; ps->gradientBar.from.w -= 1; ps->gradientBar.from.x += 1;
		ps->gradientBar.to = getRect(0, 0, ps->gradientBar.from.w, ps->gradientBar.from.h);
		ps->backgroundBar.from = pis.full.surface->clip_rect;
		ps->backgroundBar.to = getRect(0, 0, 0, ps->backgroundBar.from.h);
	}
	//create Quests Tab		
	userInterface::QuestsTab &TQ = UI.TabQuests;
	loadImage("Graphics\\rest of ui\\quests\\quests.png", TQ.imageMain);
	TQ.imageMain.z = LAYER_UI;
	TQ.imageMain.setZoom(TQ.zoom);
	TQ.QRectW = (float)(TQ.imageMain.surface->w - TQ.questsIconWH * 2);
	loadImage("Graphics\\rest of ui\\quests\\click for detalis.png", TQ.details);
	TQ.details.z = LAYER_UI;
	TQ.details.setZoom(TQ.zoom);
	//create items          
    addItem("Poop","ingredient","qpm\\item_poop.png");
    addItem("Berry",player.inventory.equipmentHandRight.typeName,"qpm\\item_berry.png");
    addItem("RegularSword",player.inventory.equipmentHandRight.typeName,"qpm\\regularSword.png"); items[items.size()-1].damage=5; affectStat("Strength",5); affectStat("Health",25);
	//load messages         
    writeMessage("close X", player.inventory.closeButton, messageColor, font_lithosProForStats);
	player.inventory.closeButton.z = LAYER_UI;
	writeMessage("/", messageSlash, messageColor, font_calibri);
	messageSlash.z = LAYER_UI;
	//create maps           
    interact *interPnt; gather* gatherPnt; int mapId; stage* stagePnt;

    createMap("Place holder", "error");
    createMap("The first map ever", "First"); mapId=maps.size()-1;
    createLayer(mapId,"qpm\\secret.png");
    createLayer(mapId,"qpm\\bc.png");
    createLayer(mapId,"qpm\\Roks.png");
    interPnt=createInteractable(mapId,"qpm\\caveEntrance.png",600,400,false);
    interPnt->events.createEnterEvent(2,320,420);
    interPnt=createInteractable(mapId,"qpm\\caveEntrance.png",1000,400,false);
    interPnt->events.createEnterEvent(2,1080,480);
    interPnt=createInteractable(mapId,"qpm\\battle_trigger.png",300,440,50,50,false);
    //addEnemyId("debug_1"); addEnemyId("debug_2"); addEnemyId("debug_3"); addEnemyId("debug_4"); addEnemyId("debug_5");
    addEnemyId("Zombie"); addEnemyId("Zombie"); addEnemyId("Zombie_mini"); addEnemyId("Zombie"); addEnemyId("Zombie");
    interPnt->events.createBattleEvent(0,battleEnemiesIds);
    interPnt=createInteractable(mapId,"qpm\\battle_trigger.png",160,240,50,50,false);
    interPnt->events.createEnterEvent(1,320,420);
    gatherPnt=createGatherable(mapId,500,320,false,1,0,"harvesting");
    gatherPnt->events.createGatherEvent(maps[mapId].gatherable.size()-1);
    addGatherableReturnItemStack(1,items[findItem("Berry")],*gatherPnt);
    stagePnt=addStage(-1,true,true,"qpm\\bush_full.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    stagePnt=addStage(1,false,false,"qpm\\bush_half.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    stagePnt=addStage(1,true,false,"qpm\\bush_empty.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    createMap("The second map", "Caves"); mapId=maps.size()-1;
    createLayer(mapId,"qpm\\secret2.png");
    createLayer(mapId,"qpm\\bc2.png");
    interPnt=createInteractable(mapId,"qpm\\caveEntrance.png",300,440,false);
    interPnt->events.createEnterEvent(1,620,380);
    interPnt=createInteractable(mapId,"qpm\\caveEntrance.png",1060,500,false);
    interPnt->events.createEnterEvent(1,1020,380);
    gatherPnt=createGatherable(mapId,150,300,false,1,0,"shitGathering");
    gatherPnt->events.createGatherEvent(maps[mapId].gatherable.size()-1);
    addGatherableReturnItemStack(1,items[findItem("Poop")],*gatherPnt);
    stagePnt=addStage(-1,true,true,"qpm\\poop_full.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    stagePnt=addStage(1,false,false,"qpm\\poop_full2.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    stagePnt=addStage(1,false,false,"qpm\\poop_half.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    stagePnt=addStage(1,false,false,"qpm\\poop_half2.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    stagePnt=addStage(1,false,false,"qpm\\poop_empty.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    stagePnt=addStage(1,true,false,"qpm\\poop_empty2.png",*gatherPnt);
        stagePnt->image.setZoom((float)50/(float)stagePnt->image.surface->h);
    //ending point
    ammountOfMaps=maps.size();
	//create battle zones   
    createBattleZone("The third map", "Pyramids_So_Real",
                        0,0,   0,0,   320,500,   0,0,   0,0,
                        786,533,  797,675,  933,597,  1095,558,  1086,666
                        //393,419,   431,456,   315,387,   387,483,   360,519
                        ); mapId=maps.size()-1;
    createLayer(mapId,"qpm\\pyramids_secret.png");
    createLayer(mapId,"qpm\\bc3.png");
    createLayer(mapId,"qpm\\pyramids_transparent.png");
	//create menu			
    std::string pathStart="Graphics\\menu slices\\",pathEnd=".png",path; layer *layerr; variables::buttn* buttonp;
    for(int i=0; i<=9; i++){
        switch(i){
			case 0: path = "close";        buttonp = &menu.close;                                  break;
			case 1: path = "play";         buttonp = &menu.play;                                   break;
			case 2: path = "options";      buttonp = &menu.options;                                break;
			case 3: path = "about";        buttonp = &menu.about;                                  break;
			case 4: path = "background";   layerr = &menu.background;							   break;
			case 5: path = "logo";         layerr = &menu.logo;                                    break;
			case 6: path = "top_gradient"; layerr = &menu.gradient;                                break;
			case 7: path = "flame 7";      layerr = &menu.flameParticle[0]; layerr->rotate = true; break;
			case 8: path = "flame 7";      layerr = &menu.flameParticle[1]; layerr->rotate = true; break;
			case 9: path = "red glow";     layerr = &menu.pulse;                                   break;
        }
        if(i<4){
            loadImage(pathStart+path+"_idle"+pathEnd,buttonp->button[0]);
            loadImage(pathStart+path+"_press"+pathEnd,buttonp->button[1]);
			buttonp->button[0].z = LAYER_UI;
			buttonp->button[1].z = LAYER_UI;
        }
		else {
			loadImage(pathStart + path + pathEnd, *layerr);
			layerr->z = LAYER_UI;
		}
    }
	menu.background.from = getRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	menu.background.to = getRect(0, 0, menu.background.from.w, menu.background.from.h);
	menu.gradient.from = menu.gradient.surface->clip_rect;
	menu.gradient.to = getRect(0, 0, menu.gradient.from.w, menu.gradient.from.h);
	menu.pulse.from = menu.pulse.surface->clip_rect;
	menu.pulse.to = getRect(0, SCREEN_HEIGHT - SCREEN_WIDTH / 2, SCREEN_WIDTH, SCREEN_WIDTH);
	menu.logo.from = menu.logo.surface->clip_rect;
	menu.logo.to = getRect((SCREEN_WIDTH - menu.logo.from.w) / 2, (SCREEN_HEIGHT - menu.logo.from.h) / 2, menu.logo.w, menu.logo.h);
	menu.close.button[0].from = menu.close.button[0].surface->clip_rect;
	menu.close.button[0].to = getRect(SCREEN_WIDTH - menu.close.button[0].from.w, 0, menu.close.button[0].from.w, menu.close.button[0].from.h);
	menu.play.button[0].from = menu.play.button[0].surface->clip_rect;
	menu.play.button[0].to = getRect(
		menu.logo.to.x + (menu.logo.surface->w - menu.play.button[0].surface->w) / 2,
		menu.logo.to.y + menu.logo.surface->h - 50,
		menu.play.button[0].from.w,
		menu.play.button[0].from.h);
	menu.options.button[0].from = menu.options.button[0].surface->clip_rect;
	menu.options.button[0].to = getRect(
		menu.play.button[0].to.x - (menu.options.button[0].w - menu.play.button[0].w) / 2,
		menu.play.button[0].to.y + menu.play.button[0].surface->h + 10,
		menu.options.button[0].from.w, 
		menu.options.button[0].from.h);
	menu.about.button[0].from = menu.about.button[0].surface->clip_rect;
	menu.about.button[0].to = getRect(
		menu.play.button[0].to.x - (menu.about.button[0].w - menu.play.button[0].w) / 2,
		menu.options.button[0].to.y + menu.options.button[0].surface->h + 10,
		menu.about.button[0].from.w, 
		menu.about.button[0].from.h);
}

//music				
void functions::controlMusic(){
	if (currentMenu == MENU_START){
		if (!Mix_Playing(channel.startMenu)){
			channel.startMenu = Mix_PlayChannel(-1, sfxStartMenu, -1);
			Mix_Volume(channel.startMenu, 20);
		}
	}
	else if (currentMenu == MENU_GAME){
		if (Mix_Playing(channel.startMenu)){
			Mix_FadeOutChannel(channel.startMenu, 2000);
			channel.startMenu = -2;
		}
	}
	else{
		int wtf = 9000 + 1;
	}
}
void functions::loadMusic(Mix_Music *&musicHolder,std::string path){
	musicHolder = NULL;
	musicHolder = Mix_LoadMUS(path.c_str());
	if (musicHolder == NULL){
		error("failed to load a music file located at " + path);
		quit = true;
	}
}
void functions::loadSoundEffect(Mix_Chunk *&musicHolder, std::string path){
	musicHolder = NULL;
	musicHolder = Mix_LoadWAV(path.c_str());
	if (musicHolder == NULL){
		error("failed to load a sound effect file located at " + path);
		quit = true;
	}
}
//move				
bool functions::movePoint(SDL_Point *point, int movementSpeed){
	bool change = false;
	if (buttons[findButton("D")].pressed == 1 || buttons[findButton("Right")].pressed == 1) { point->x += movementSpeed; change = true; }
	if (buttons[findButton("A")].pressed == 1 || buttons[findButton("Left")].pressed == 1)  { point->x -= movementSpeed; change = true; }
	if (buttons[findButton("S")].pressed == 1 || buttons[findButton("Down")].pressed == 1)  { point->y += movementSpeed; change = true; }
	if (buttons[findButton("W")].pressed == 1 || buttons[findButton("Up")].pressed == 1)    { point->y -= movementSpeed; change = true; }
	return change;
}
void functions::moveCharacter(bool withObstructions, SDL_Surface* surfaceOfObstructions){
	if (withObstructions){
		SDL_Color currentColor[4]; SDL_Point pixelLocation[4];
		SDL_Point savedLocation = player.location;
		moveCharacter();
		SDL_Point movedLocation = player.location;
		SDL_Point doneLocation = movedLocation;

		player.location.x = movedLocation.x;
		player.location.y = savedLocation.y;
		getEntityCornerColors(surfaceOfObstructions, currentColor, pixelLocation);
		for (Uint8 i = 0; i<obstructions.size(); i++){
			if (equalColors(currentColor[0], obstructions[i]) ||
				equalColors(currentColor[1], obstructions[i]) ||
				equalColors(currentColor[2], obstructions[i]) ||
				equalColors(currentColor[3], obstructions[i])){
				doneLocation.x = savedLocation.x;
				i = (Uint8)obstructions.size();
			}
		}
		player.location.x = savedLocation.x;
		player.location.y = movedLocation.y;
		getEntityCornerColors(surfaceOfObstructions, currentColor, pixelLocation);
		for (Uint8 i = 0; i<obstructions.size(); i++){
			if (equalColors(currentColor[0], obstructions[i]) ||
				equalColors(currentColor[1], obstructions[i]) ||
				equalColors(currentColor[2], obstructions[i]) ||
				equalColors(currentColor[3], obstructions[i])){
				doneLocation.y = savedLocation.y;
				i = (Uint8)obstructions.size();
			}
		}
		player.location = doneLocation;
	}
	else{
		moveCharacter();
	}
}
void functions::moveCharacter(){
	SDL_Point* movedObject;
	if (moveObject == OBJECT_PLAYER) movedObject = &player.location;
	else if (moveObject == OBJECT_SCREEN) movedObject = &offset;
	if (player.isInBattle == 0){
		if (buttons[findButton("D")].pressed == 1 || buttons[findButton("Right")].pressed == 1) movedObject->x += (int)(player.movementSpeed);
		if (buttons[findButton("A")].pressed == 1 || buttons[findButton("Left")].pressed == 1)  movedObject->x -= (int)(player.movementSpeed);
		if (buttons[findButton("S")].pressed == 1 || buttons[findButton("Down")].pressed == 1)  movedObject->y += (int)(player.movementSpeed);
		if (buttons[findButton("W")].pressed == 1 || buttons[findButton("Up")].pressed == 1)    movedObject->y -= (int)(player.movementSpeed);
	}
}
//items & stats		
void functions::swapItemStacks(itemStack& itemStack1, itemStack& itemStack2){
	itemStack isTemp;
	isTemp = itemStack2;
	itemStack2 = itemStack1;
	itemStack1 = isTemp;
}
void functions::affectStats(item* itemOfWhichEffectsToUse, bool trueForGivingStats_falseForRemovingStats){
	int multi = 1; if (!trueForGivingStats_falseForRemovingStats) multi = -1;
	for (int i = 0; i<(int)itemOfWhichEffectsToUse->affectedStats.size(); i++){//go through all the effects for stats in that item
		for (int o = 0; o<(int)player.stats[0].size(); o++){//go through all the existing stats to see if this effect is for that specific stat
			if (player.stats[0][o].name == itemOfWhichEffectsToUse->affectedStats[i].statName){ //check if the effected stat and the checked stat are the same
				player.stats[0][o].updateAddition = true;
				player.addStatAddition((int)(itemOfWhichEffectsToUse->affectedStats[i].ammount*multi), player.stats[0][o].name);//if so then add the effected stat amount to the addition variable that let's the program know by how much the stat is increased from it's base value
				o = player.stats[0].size();
			}
		}
	}
}
void functions::unequipItem(int equipmentId, int toSlot){
	if (toSlot == -1) giveItems(player.inventory.equipmentAll[equipmentId]->item);//copy the item from your equipment slot to you inventory
	else{
		if (player.inventory.itemStacks[toSlot].ist.itemCount>0){
			if (player.inventory.itemStacks[toSlot].ist.containingItem == player.inventory.equipmentAll[equipmentId]->item.containingItem){
				giveItems(player.inventory.equipmentAll[equipmentId]->item.containingItem, player.inventory.equipmentAll[equipmentId]->item.itemCount + player.inventory.itemStacks[toSlot].ist.itemCount, player.inventory.itemStacks[toSlot].ist);
				goto unequipItemAffectStats;
			}
			else{
				if (!equipItem(player.inventory.itemStacks[toSlot].ist)) unequipItem(equipmentId);
				goto quitUnequipingItem;
			}
		}
		else giveItems(player.inventory.equipmentAll[equipmentId]->item.containingItem, player.inventory.equipmentAll[equipmentId]->item.itemCount, player.inventory.itemStacks[toSlot].ist);//copy the item from your equipment slot to you inventory
	}
unequipItemAffectStats:
	affectStats(&player.inventory.equipmentAll[equipmentId]->item.containingItem, false);//remove the stat effects that were given by this item
	player.inventory.equipmentAll[equipmentId]->item.reset();//remove the item from your equipment slot
quitUnequipingItem:
	player.inventory.update = true;
}
bool functions::equipItem(itemStack& item, space* inventory, int slotId){
	for (int i = 0; i<player.inventory.equipmentCount; i++){//find in which equipment slot this item should be put
		if (item.containingItem.type == player.inventory.equipmentAll[i]->typeName){//see if this equipment slot is the one to be used
			itemStack itemHolder = item;
			itemHolder.itemCount = 1;
			if (inventory == nullptr) removeItem(item, 1, player.inventory);//remove the item from the inventory
			else removeItem(slotId, 1, *inventory);
			if (player.inventory.equipmentAll[i]->item.itemCount != 0){//if there is already an item equipped there
				unequipItem(i);//take off that item
			}
			player.inventory.equipmentAll[i]->item.containingItem = itemHolder.containingItem;//copy the item from players' inventory to the equipment slot
			player.inventory.equipmentAll[i]->item.itemCount = 1;//make sure that there is only one item in the equipment slot
			affectStats(&player.inventory.equipmentAll[i]->item.containingItem, true);
			return true;
		}
	}
	return false;
}
void functions::removeItem(int slotId, int ammount, space& inventory){
	itemStack &currentIS = inventory.itemStacks[slotId].ist;
	if (currentIS.itemCount>0){
		if (currentIS.itemCount < ammount){
			currentIS.itemCount = 0;
		}
		else {
			currentIS.itemCount -= ammount;
		}
		currentIS.updateItem = true;
		if (currentIS.itemCount == 0){
			currentIS.reset();
			if (inventory.pressedId == slotId) inventory.pressedId = -1;
		}
		if (inventory.name == "Player Inventory") player.inventory.update = true;
	}
}
void functions::removeItem(itemStack& item, int ammount, space& inventory){
	itemStack *currentIS;
	for (int i = 0; i < (int)inventory.itemStacks.size(); i++){
		currentIS = &inventory.itemStacks[i].ist;
		if (item.itemCount>0 && item.containingItem == currentIS->containingItem){
			if (currentIS->itemCount < ammount){
				ammount -= currentIS->itemCount;
				currentIS->itemCount = 0;
			}
			else {
				currentIS->itemCount -= ammount;
				ammount = 0;
			}
			if (currentIS->itemCount == 0 && inventory.pressedId == i) inventory.pressedId = -1;
			currentIS->updateItem = true;
			if (inventory.name == "Player Inventory") player.inventory.update = true;
			if (ammount == 0) goto stopRemovingItems;
		}
	}
stopRemovingItems:;
}
void functions::affectStat(std::string statName, float ammount){
	item::affect affectedStat;
	affectedStat.statName = statName; affectedStat.ammount = ammount;
	items[items.size() - 1].affectedStats.push_back(affectedStat);
}
void functions::giveItems(item &itemToGive, int ammount, itemStack &toWhere){
	toWhere.itemCount = ammount;
	toWhere.containingItem = itemToGive;
	toWhere.updateItem = true;
	player.inventory.update = true;
}
void functions::giveItems(itemStack &itemsToGive){
	for (Uint8 i = 0; i<player.inventory.itemStacks.size(); i++){
		if (player.inventory.itemStacks[i].ist.containingItem == itemsToGive.containingItem){
			giveItems(itemsToGive.containingItem, player.inventory.itemStacks[i].ist.itemCount + itemsToGive.itemCount, player.inventory.itemStacks[i].ist);
			goto doneGivingItems1;
		}
	}
	for (Uint8 i = 0; i < player.inventory.itemStacks.size(); i++){
		if (player.inventory.itemStacks[i].ist.itemCount == 0){
			player.inventory.itemStacks[i].ist = itemsToGive;
			goto doneGivingItems1;
		}
	}
doneGivingItems1:
	player.inventory.update = true;
}
void functions::giveItems(item &itemToGive, int ammount){
	itemStack temp;
	temp.containingItem = itemToGive;
	temp.itemCount = ammount;
	giveItems(temp);
}
//call				
/*event*/			   
void functions::callEvent(std::string type, info &information){
	if (type == "Enter"){
		callEventEnter(information);
	}
	else if (type == "Battle"){
		callEventBattle(information);
	}
	else if (type == "Gather"){
		callEventGather(information);
	}
	else{
		error(type + "was not added to the callEvent function.\nFix the program you lazy programmer!");
	}
}
void functions::callEventGather(info &information){
	player.gathering = 1;
	player.gatherableId = information.intInfo[0];
}
void functions::callEventEnter(info &information){
	player.map_location = information.intInfo[0];
	player.location.x = information.intInfo[1];
	player.location.y = information.intInfo[2];
}
void functions::callEventBattle(info &information){
	battleZoneId = information.intInfo[0];
	for (int i = 0; i<information.intInfo[1]; i++){
		battleEnemies.push_back(entities[information.intInfo[i + 2]]);
	}
	player.isInBattle = 1;
	player.map_location = ammountOfMaps + battleZoneId;
}
//render			
/*Start Screen*/	   
void functions::renderFlameParticles(){
	spawnFlameParticle();
	if (menu.type == menu.OLD) {
		//for(int i=0; i<10; i++) spawnFlameParticle();
		for (int i = 0; i<(int)menu.flames.size(); i++){
			fl &flame = menu.flames[i];
			flame.delta = (float)(timeStamp - flame.creationTimeStamp) / (float)flame.lifetime;
			if (flame.delta>1 || (1 - sqrt(flame.delta))*7.f / 8.f<0) {
				menu.flames.erase(menu.flames.begin() + i, menu.flames.begin() + i + 1);
				i--;
			}
			else{
				flame.location = getPointBetweenTwo(flame.startPoint, flame.endPoint, flame.delta);
				//flame.location.x = (int)(flame.startPoint.x*(1 - flame.delta) + flame.endPoint.x*flame.delta);
				//flame.location.y = (int)(flame.startPoint.y*(1 - flame.delta) + flame.endPoint.y*flame.delta);
				if (flame.direction){
					flame.location.x += (int)(cos(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1 - flame.delta) + flame.oscillationEndingAmplitude*flame.delta));
					flame.location.y += (int)(sin(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1 - flame.delta) + flame.oscillationEndingAmplitude*flame.delta));
				}
				else{
					flame.location.x += (int)(sin(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1 - flame.delta) + flame.oscillationEndingAmplitude*flame.delta));
					flame.location.y += (int)(cos(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1 - flame.delta) + flame.oscillationEndingAmplitude*flame.delta));
				}
				menu.flameParticle[flame.flameId].color.a = (1 - sqrt(flame.delta))*7.f / 8.f;
				menu.flameParticle[flame.flameId].color.r = flame.r / 255.f;
				menu.flameParticle[flame.flameId].color.g = flame.g / 255.f;
				menu.flameParticle[flame.flameId].color.b = flame.b / 255.f;
				menu.flameParticle[flame.flameId].rotation = (timeStamp - flame.creationTimeStamp) % flame.rotationSpeed * 360 / (float)flame.rotationSpeed;
				if (flame.rotationDirection) menu.flameParticle[flame.flameId].rotation *= -1;
				menu.flameParticle[flame.flameId].setZoom(flame.initialSize*(1 - flame.delta) + flame.endingSize*flame.delta);
				renderTexture(&menu.flameParticle[flame.flameId], menu.flameParticle[flame.flameId].surface->clip_rect, flame.location);
			}
		}
	}
	else {
		for (int i = 0; i < (int)menu.flames.size(); i++){
			fl &flame = menu.flames[i];
			if (true||flame.startPoint.x > flame.endPoint.x) {
				flame.delta = (float)(timeStamp - flame.creationTimeStamp) / (float)flame.lifetime;
				if (flame.delta>1) {
					menu.flames.erase(menu.flames.begin() + i, menu.flames.begin() + i + 1);
					i--;
				}
				else {
					flame.location = getPointBetweenTwo(flame.startPoint,flame.endPoint,flame.delta);
					menu.flameParticle[flame.flameId].setZoom(flame.initialSize*(1 - flame.delta) + flame.endingSize * flame.delta);
					renderTexture(&menu.flameParticle[flame.flameId], menu.flameParticle[flame.flameId].surface->clip_rect, flame.location); flame.location.y -= (flame.location.y - SCREEN_HEIGHT / 2) * 2;
					renderTexture(&menu.flameParticle[flame.flameId], menu.flameParticle[flame.flameId].surface->clip_rect, flame.location);
				}
			}
		}
	}
}
void functions::renderMenuPulse(){
	if (timeStamp - menu.pulseTimeStamp > menu.pulseLength*menu.pulseMaxAlpha){
		menu.pulseState = !menu.pulseState;
		menu.pulseTimeStamp = timeStamp;
		menu.pulseLength = (rand() % (FPS * 2) + FPS) * 2;
	}
	menu.pulse.color.a = (float)(timeStamp - menu.pulseTimeStamp) / (float)menu.pulseLength;
	if (menu.pulseState) menu.pulse.color.a = menu.pulseMaxAlpha - menu.pulse.color.a;
	renderTexture(&menu.pulse, menu.pulse.from, menu.pulse.to);
}
void functions::renderStartMenu(){
	renderTexture(&menu.background, menu.background.from, menu.background.to);
	renderFlameParticles();
	renderMenuPulse();
	renderTexture(&menu.logo, menu.logo.from, menu.logo.to);
	renderTexture(&menu.close.button[menu.close.state],	menu.close.button[0].from,		menu.close.button[0].to);
	renderTexture(&menu.play.button[menu.play.state],		menu.play.button[0].from,		menu.play.button[0].to);
	renderTexture(&menu.options.button[menu.options.state],	menu.options.button[0].from,	menu.options.button[0].to);
	renderTexture(&menu.about.button[menu.about.state],	menu.about.button[0].from,		menu.about.button[0].to);
	renderTexture(&menu.gradient, menu.gradient.from, menu.gradient.to);
}
/*UI*/				   
void functions::renderUI(){
	//manage clicks	       	  
	renderQuestsTab(true);
	renderStats(true);
	renderInventory(true);
	//render Bot UI           
	renderTexture(&UI.botUI, UI.botUI.surface->clip_rect, UI.botUI.to);
	for (int i = 0; i<4; i++){
		if (leftMouseButton == 1 || leftMouseButtonUp == 1){
			if (pointInsideRect(mouse, { UI.botUIButtons[i].state[0].to.x, UI.botUIButtons[i].state[0].to.y, UI.botUIButtons[i].state[0].w, UI.botUIButtons[i].state[0].h })) {
				if (leftMouseButton == 1) {
					clickedOn = "botUIButton_" + toString(i);
					leftMouseButton = 0;
					UI.botUIButtons[i].currentState = (int)true;
				}
				else{
					if (clickedOn == ("botUIButton_" + toString(i))){
						switch (i){
						case 0:
							player.inventory.open = !player.inventory.open; // open/close inventory
							break;
						case 1:
							UI.TabStats.open = !UI.TabStats.open;
							break;
						case 2:
							error("open skills menu [needs to be created first]");
							break;
						case 3:
							UI.TabQuests.open = !UI.TabQuests.open;
							break;
						}
						UI.botUIButtons[i].currentState = (int)false;
						leftMouseButtonUp = 0;
						clickedOn = "";
					}
				}
			}
			else{
				if (leftMouseButtonUp == 1 && clickedOn == ("botUIButton_" + toString(i))){
					UI.botUIButtons[i].currentState = (int)false;
					clickedOn = "";
				}
			}
		}
		renderTexture(&UI.botUIButtons[i].state[UI.botUIButtons[i].currentState], UI.botUIButtons[i].state[0].from, UI.botUIButtons[i].state[0].to);
	}
	//render Character UI     
	renderTexture(&UI.characterUI, UI.characterUI.surface->clip_rect);
	for (int i = 0; i<3; i++){//render health/mana/experience bars
		if (*UI.all[i]->update){
			RenderType = RENDER_NEAREST;
			writeMessage(toString(*UI.all[i]->countAmount), UI.all[i]->message, messageColor, font_calibri);
			writeMessage(toString(*UI.all[i]->max_countAmount), UI.all[i]->max_count, messageColor, font_calibri);
			RenderType = RENDER_MIPMAP;
		}
		renderTexture(&UI.bar_empty, UI.bar_empty.surface->clip_rect, UI.all[i]->bar.offset);//render empty
		renderTexture(&UI.all[i]->bar, getRect(0, 0, (int)(UI.all[i]->bar.surface->w*(*UI.all[i]->countAmount) / (*UI.all[i]->max_countAmount)), UI.all[i]->bar.surface->h), UI.all[i]->bar.offset);//render full
		renderTexture(&messageSlash, messageSlash.surface->clip_rect, { UI.all[i]->bar.offset.x + (UI.bar_empty.w - messageSlash.surface->w) / 2, UI.all[i]->bar.offset.y + (UI.bar_empty.h - messageSlash.surface->h) / 2 });//render slash
		renderTexture(&UI.all[i]->max_count, UI.all[i]->max_count.surface->clip_rect, { UI.all[i]->bar.offset.x + (UI.bar_empty.w + messageSlash.surface->w) / 2, UI.all[i]->bar.offset.y + (UI.bar_empty.h - messageSlash.surface->h) / 2 });//render max
		renderTexture(&UI.all[i]->message, UI.all[i]->message.surface->clip_rect, { UI.all[i]->bar.offset.x + (UI.bar_empty.w - messageSlash.surface->w) / 2 - UI.all[i]->message.surface->w, UI.all[i]->bar.offset.y + (UI.bar_empty.h - messageSlash.surface->h) / 2 });//render current
	}
	//render class/rank tablet   
	if (*UI.bar_green.update){
		RenderType = RENDER_NEAREST;
		writeMessage(" " + player.type + " ", UI.bar_green.message, messageColor, font_lithosPro);
		RenderType = RENDER_MIPMAP;
	}
	renderTexture(&UI.bar_green.bar, getRect(0, 0, (int)(UI.bar_green.message.surface->w / characterUiZoom), UI.bar_green.bar.surface->h), UI.bar_green.bar.offset);
	renderTexture(&UI.bar_green.message, UI.bar_green.message.surface->clip_rect, { UI.bar_green.bar.offset.x, (int)(UI.bar_green.bar.offset.y + (UI.bar_green.bar.h - UI.bar_green.message.surface->h + 12 * characterUiZoom) / 2) });
	//render player Level        
	if (*UI.level.update){
		UI.level.message.free();
		UI.level.message.surface = TTF_RenderText_Blended(font_lithosProForLevel, toString(*UI.level.countAmount).c_str(), levelColor);
		while ((UI.level.message.surface->h>84 * UI.characterUI.h / (float)1113) || (UI.level.message.surface->w>84 * UI.characterUI.w / (float)1113)){
			font_lithosProForLevelSize -= 1;
			font_lithosProForLevel = TTF_OpenFont("ttf\\LithosPro.otf", font_lithosProForLevelSize);
			TTF_SetFontStyle(font_lithosProForLevel, TTF_STYLE_BOLD);
			UI.level.message.freeSurface();
			UI.level.message.surface = TTF_RenderText_Blended(font_lithosProForLevel, toString(*UI.level.countAmount).c_str(), levelColor);
		}
		RenderType = RENDER_NEAREST;
		UI.level.message.textureOpenGL = convertSurfaceToOpenGLTexture(UI.level.message.surface);
		RenderType = RENDER_MIPMAP;
	}
	renderTexture(&UI.level.message, UI.level.message.surface->clip_rect, { (int)((UI.characterUI.w*(float)318 / (float)1113) - UI.level.message.surface->w / 2), (int)((UI.characterUI.w*(float)360 / (float)1113) - UI.level.message.surface->h / 2) });
	//render Top UI           
	layer* currentLayer;
	renderTexture(&UI.topUIReflection,
		UI.topUIReflection.surface->clip_rect,
		{ UI.topUIButtonsTopLeftLocation.x,
		(int)(UI.topUIButtonsTopLeftLocation.y + UI.topUIButtons[0].state[0].h + 5 * characterUiZoom) });
	for (int i = 0; i<3; i++){
		currentLayer = &UI.topUIButtons[i].state[UI.topUIButtons[i].currentState];
		renderTexture(currentLayer, currentLayer->surface->clip_rect,
			{ UI.topUIButtonsTopLeftLocation.x + UI.topUIDistanceBetweenButtons[i],
			UI.topUIButtonsTopLeftLocation.y });
	}
	for (int i = 2; i >= 0; i--){
		if (leftMouseButton || leftMouseButtonUp){
			if (pointInsideRect(mouse, getRect(UI.topUIButtonsTopLeftLocation.x + UI.topUIDistanceBetweenButtons[i], UI.topUIButtonsTopLeftLocation.y, UI.topUIButtons[i].state[UI.topUIButtons[i].currentState].w, UI.topUIButtons[i].state[UI.topUIButtons[i].currentState].h))){
				SDL_Color currentColor = getPixelColors(UI.topUIButtons[i].state[UI.topUIButtons[i].currentState].surface, (int)((mouse.location.x - (UI.topUIButtonsTopLeftLocation.x + UI.topUIDistanceBetweenButtons[i])) / characterUiZoom), (int)((mouse.location.y - UI.topUIButtonsTopLeftLocation.y) / characterUiZoom));
				if (currentColor.a != 0){
					if (leftMouseButton){
						clickedOn = "topUIButton_" + toString(i);
						UI.topUIButtons[i].currentState = true;
						leftMouseButton = false;
					}
					if (leftMouseButtonUp&&clickedOn == "topUIButton_" + toString(i)){
						switch (i){
						case 0: error("open shop"); break;
						case 1: error("open settings"); break;
						case 2:
							if (MessageBoxA(hwnd, "Are you sure you want to quit the program and you're not just testing what it does?", "Program:", MB_YESNO) == IDYES){
								if (MessageBoxA(hwnd, "So then you do indeed want to shut this program down?", "Program:", MB_YESNO) == IDYES){
									if (MessageBoxA(hwnd, "...but...you do know that it will kill me right?", "Program:", MB_YESNO) == IDYES){
										MessageBoxA(hwnd, "Okay, okay. [you monster]", "Program:", MB_OK);
										SDL_Delay(1000);
										MessageBoxA(hwnd, "...but...", "Program:", MB_HELP);
										SDL_Delay(500);
										if (MessageBoxA(hwnd, "...are you sure?", "Program:", MB_YESNO) == IDYES){
											MessageBoxA(hwnd, "S", "Program:", MB_OK);
											MessageBoxA(hwnd, "Sh", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shu", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shut", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shutt", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shutti", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shuttin", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shutting", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shutting d", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shutting do", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shutting dow", "Program:", MB_OK);
											MessageBoxA(hwnd, "Shutting down", "Program:", MB_OK);
											quit = true;
										}
										else MessageBoxA(hwnd, "Aborting self destruction mechanism. Thanks for not killing me!", "Program:", MB_OK);
									}
									else MessageBoxA(hwnd, "Well i'm glad i told you then.", "Program:", MB_OK);
								}
								else MessageBoxA(hwnd, "Yeah, didn't think so.", "Program:", MB_OK);
							}
							else MessageBoxA(hwnd, "Well quit it, you're annoying me!", "Program:", MB_OK);
							break;
						}
						UI.topUIButtons[i].currentState = false;
					}
				}
			}
			if (leftMouseButtonUp&&clickedOn == "topUIButton_" + toString(i)){
				clickedOn = "";
				UI.topUIButtons[i].currentState = false;
			}
		}
	}
	//render Inventory        
	renderInventory(false);
	//render draged object    
	if (drag.objectName != "") renderItem(*drag.ist, drag.From, mouse.location - mouseOffsetFromMovableObject, 1);
	//render Stats Tab        
	renderStats();
	//render Quests Tab		  
	renderQuestsTab();
}
void functions::renderInventory(bool manageClicks){
	characterSpace &pi = player.inventory;//player.inventory
	if (pi.open){
		pi.closeButton.setZoom(pi.zoom);
		if (manageClicks){
			if (mouseWheelMotion != 0){//process mouse wheel action [move scroll bar]
				float possibleSliderLocation = player.inventory.scrollBar.barOffset - mouseWheelMotion*pi.scrollBar.speed;
				if (possibleSliderLocation>0){
					if (possibleSliderLocation<player.inventory.scrollBar.furthestPossibleSliderLocation) player.inventory.scrollBar.barOffset = possibleSliderLocation;
					else player.inventory.scrollBar.barOffset = (float)(player.inventory.scrollBar.furthestPossibleSliderLocation);
				}
				else player.inventory.scrollBar.barOffset = 0;
			}
			if (leftMouseButton || leftMouseButtonUp){
				if (pointInsideRect(mouse, getRect(pi.closeLocation + player.inventory.location, pi.closeButton.w, pi.closeButton.h))){
					if (leftMouseButton&&clickedOn == ""){
						clickedOn = "closeInventory";
						leftMouseButton = false;
					}
					else if (leftMouseButtonUp&&clickedOn == "closeInventory"){
						clickedOn = "";
						leftMouseButtonUp = false;
						pi.open = false;
					}
				}
				else if (clickedOn == "closeInventory") clickedOn = "";
			}
			renderSlots(pi, true);
			renderEquipment(true);
			if (leftMouseButton&&clickedOn == ""&&pointInsideRect(mouse, getRect(pi.location, pi.imageMain.w, pi.imageMain.h)) && getColorAlpha(getPixelColors(pi.imageMain.surface, (int)((mouse.location.x - pi.location.x) / pi.zoom), (int)((mouse.location.y - pi.location.y) / pi.zoom))) != 0){
				clickedOn = "moveInventory";
				mouseOffsetFromMovableObject = mouse.location - pi.location;
				leftMouseButton = false;
			}
			else if (leftMouseButtonUp&&clickedOn == "moveInventory"){
				clickedOn = "";
				mouseOffsetFromMovableObject = { 0, 0 };
				leftMouseButtonUp = false;
			}
			if (clickedOn == "moveInventory"){
				pi.location = mouse.location - mouseOffsetFromMovableObject;
				moveLayerWithinBorder(pi.imageMain, getRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), pi.location);
			}
		}
		else{
			//render Main Textures
			renderTexture(&pi.imageMain, pi.imageMain.surface->clip_rect, pi.location);
			//render Scroll Bar   
			renderScrollBar(pi.scrollBar,pi.location);
			//render Close button 
			if (clickedOn == "closeInventory") pi.closeButton.color.a = 0.8f;
			else pi.closeButton.color.a = 1.f;
			renderTexture(&player.inventory.closeButton,
				player.inventory.closeButton.surface->clip_rect,
				player.inventory.closeLocation + player.inventory.location);
			//render Stats 		  
			for (int i = 0; i < (int)player.stats[0].size(); i++){
				renderStat(player.stats[0][i],
					{ player.inventory.statTopLeftLocation.x + player.inventory.location.x,
					player.inventory.statTopLeftLocation.y + player.inventory.location.y + i*player.inventory.distanceBetweenStats },
					player.inventory.zoom);
			}
			//render Slots		  
			renderSlots(pi);
			//render Equipment	  
			renderEquipment();
		}
	}
	else if (manageClicks){
		if (clickedOn == "moveInventory"){
			mouseOffsetFromMovableObject.x = 0;
			mouseOffsetFromMovableObject.y = 0;
			clickedOn = "";
		}
		else if (clickedOn == "closeInventory"){
			clickedOn = "";
		}
	}
	else{
		player.inventory.pressedId = -1;
	}
}
void functions::renderItem(itemStack &item, SDL_Rect &from, SDL_Point location, int renderType){
	if (item.itemCount > 0){
		if (item.updateItem){
			item.updateItem = false;
			writeMessage(toString(item.itemCount), item.itemCountLayer);
			item.itemCountLayer.z = LAYER_UI;
		}
		from.y = convertNumbersByRelativity(from.y, item.containingItem.image.surface->w, from.w);
		from.h = convertNumbersByRelativity(from.h, item.containingItem.image.surface->w, from.w);
		from.w = item.containingItem.image.surface->w;
		if (renderType != 2) renderTexture(&item.containingItem.image, from, location);
		item.itemCountLayer.offset.x = location.x - (int)(from.x*item.containingItem.image.zoom*item.containingItem.image.zoomWidth) + item.containingItem.image.w - item.itemCountLayer.surface->w;
		item.itemCountLayer.offset.y = location.y - (int)(from.y*item.containingItem.image.zoom*item.containingItem.image.zoomHeight) + item.containingItem.image.h - item.itemCountLayer.surface->h;
		clipLayer(item.itemCountLayer, player.inventory.slotBoundary);
		if (item.itemCountLayer.from.h >= 0 && item.itemCountLayer.from.h <= item.itemCountLayer.h&&renderType != 1) renderTexture(&item.itemCountLayer, item.itemCountLayer.from, item.itemCountLayer.offset);
	}
}
void functions::renderSlots(space &Space, bool manageClicks){
	bool pressed = false, stop = false;
	if (Space.pressedId == -1) stop = true;
	Space.slotLocationTopLeft = Space.slotLocationTopLeftBase + Space.location;
	Space.slotBoundary.x = Space.slotLocationTopLeftBase.x + Space.location.x;
	Space.slotBoundary.y = Space.slotLocationTopLeftBase.y + Space.location.y;
	layer* layerp; int itemId;
	for (int y = 0; y < Space.rowsInInventory; y++){
		for (int x = 0; x < Space.slotsInOneRow; x++){
			itemId = y*Space.slotsInOneRow + x;
			if (y == Space.rowsInInventory - 1 && itemId == Space.itemStacks.size()){
				x = Space.slotsInOneRow;
			}
			else{
				if (!stop && itemId == Space.pressedId) pressed = true;
				layerp = &player.inventory.imageInventorySlot[pressed];
				layerp->offset.x = Space.slotLocationTopLeft.x + x*Space.distanceBetweenSlots;
				layerp->offset.y = Space.slotLocationTopLeft.y + y*Space.distanceBetweenSlots - (int)(Space.scrollBar.barOffset *Space.scrollBar.ratioBetweenBarAndOther);
				clipLayer(*layerp, Space.slotBoundary);
				if (layerp->from.h > 0) {
					if (!manageClicks) renderTexture(layerp, layerp->from, layerp->offset);
					else if (leftMouseButton || leftMouseButtonUp){
						SDL_Rect slotRect = getRect(layerp->offset, (int)(layerp->from.w*layerp->zoom*layerp->zoomWidth), (int)(layerp->from.h*layerp->zoom*layerp->zoomHeight));
						if (pointInsideRect(mouse, slotRect)){
							if (leftMouseButtonUp){
								if (clickedOn == Space.name + " slot " + toString(itemId)){
									Space.pressedId = itemId;
									if (doubleLeftClick == -1) doubleLeftClick = FPS / 2;
									else{
										doubleLeftClick = -1;
										if (Space.name == "Player Inventory"){
											equipItem(Space.itemStacks[itemId].ist, &Space, itemId);
											if (drag.objectName == Space.name + " slot " + toString(itemId)) drag.objectName = "";
										}
									}
								clearClicked:
									if (drag.objectName == Space.name + " slot " + toString(itemId)){//finish draging
										drag.objectName = "";
										if (player.inventory.open){
											int itemId2;
											SDL_Rect slotRect2;
											characterSpace& Space2 = player.inventory;
											for (int y2 = 0; y2 < Space2.rowsInInventory; y2++){
												for (int x2 = 0; x2 < Space2.slotsInOneRow; x2++){
													itemId2 = y2*Space2.slotsInOneRow + x2;
													if (y2 == Space2.rowsInInventory - 1 && itemId2 == Space2.itemStacks.size()){
														x2 = Space2.slotsInOneRow;
													}
													else{
														layer tempLayer = player.inventory.imageInventorySlot[0];
														tempLayer.offset.x = Space2.slotLocationTopLeft.x + x2*Space2.distanceBetweenSlots;
														tempLayer.offset.y = Space2.slotLocationTopLeft.y + y2*Space2.distanceBetweenSlots - (int)(Space2.scrollBar.barOffset*Space2.scrollBar.ratioBetweenBarAndOther);
														clipLayer(tempLayer, Space2.slotBoundary);
														if (tempLayer.from.h > 0){
															slotRect2 = getRect(tempLayer.offset, (int)(tempLayer.from.w*tempLayer.zoom*tempLayer.zoomWidth), (int)(tempLayer.from.h*tempLayer.zoom*tempLayer.zoomHeight));
															if (pointInsideRect(mouse, slotRect2)){//swap items [held item with the item in this inventory item slot]
																if (drag.ist->containingItem != Space2.itemStacks[itemId2].ist.containingItem) swapItemStacks(*drag.ist, Space2.itemStacks[itemId2].ist);
																else if (drag.ist != &Space2.itemStacks[itemId2].ist){
																	Space2.itemStacks[itemId2].ist.itemCount += drag.ist->itemCount;
																	Space2.itemStacks[itemId2].ist.updateItem = true;
																	Space2.update = true;
																	drag.ist->reset();
																}
																Space.pressedId = itemId2;
																goto exitThisSearch;
															}
														}
													}
												}
											}
											SDL_Rect& equipmentSlotRect = slotRect2;
											characterSpace::equipment* pie;
											SDL_Point equipStartPoint = Space2.location + Space2.equipmentTopLeftLocation;
											for (int i = 0; i < player.inventory.equipmentCount; i++){
												pie = Space2.equipmentAll[i];
												if (drag.ist->containingItem.type == pie->typeName){
													equipmentSlotRect = getRect(
														equipStartPoint.x + pie->x*Space2.distanceBetweenEquipmentSlots,
														equipStartPoint.y + pie->y*Space2.distanceBetweenEquipmentSlots,
														pie->image.w, pie->image.h);
													if (pointInsideRect(mouse, equipmentSlotRect)){//swap items [held item with the item in this equipment item slot]
														equipItem(*drag.ist, drag.inventory, drag.slotId);
														goto exitThisSearch;
													}
												}
											}
										}
									}
								exitThisSearch:
									clickedOn = "";
									leftMouseButtonUp = false;
								}
							}
							else if (leftMouseButton){
								if (Space.itemStacks[itemId].ist.itemCount > 0){
									if (clickedOn == ""){
										clickedOn = Space.name + " slot " + toString(itemId);
										leftMouseButton = false;
									}
									drag.objectName = clickedOn;
									drag.ist = &Space.itemStacks[itemId].ist;
									drag.slotId = itemId;
									drag.inventory = &Space;
									drag.From = layerp->from;
									mouseOffsetFromMovableObject = mouse.location - layerp->offset;
								}
							}
						}
						else{
							if (leftMouseButtonUp&&clickedOn == Space.name + " slot " + toString(itemId)) goto clearClicked;
						}
					}
					int itemRenderType = 0;
					if (drag.objectName == Space.name + " slot " + toString(itemId)){
						itemRenderType = 2;
					}
					if (!manageClicks) renderItem(Space.itemStacks[itemId].ist, layerp->from, layerp->offset, itemRenderType);
				}
				if (pressed) { pressed = false; stop = true; }
			}
		}
	}
}
void functions::renderStat(character::stat &stat, SDL_Point location, float zoom){
	int id = stat.levelBase / 100 + 1; characterSpace::bars &pi = player.inventory.statsBar[id], &pib = player.inventory.statsBar[id - 1];
	if (stat.updateAddition){
		stat.updateAddition = false; stat.updateLevelBaseLayer = true;
		if (stat.levelAddition != 0){
			writeMessage("+" + toString(stat.levelAddition), stat.levelAdditionLayer, additionColor, font_lithosProForStats);
			stat.additionBarWidth = (int)(ceil(player.inventory.additionBar.full.surface->w*((float)stat.levelAddition / (float)100)));
		}
		else{
			stat.additionBarWidth = 0;
		}
	}
	if (stat.updateName || stat.updateLevelBaseLayer){
		layer* layerp; std::string text; bool *check;
		for (int o = 0; o<2; o++){
			switch (o){
			case 0:
				layerp = &stat.statNameLayer;
				check = &stat.updateName;
				text = stat.name;
				break;
			case 1:
				layerp = &stat.levelBaseLayer;
				check = &stat.updateLevelBaseLayer;
				text = toString(stat.levelBase);
				break;
			}
			if (*check){
				*check = false;
				writeMessage(text, *layerp, messageColor, font_lithosProForStats);
				if (o == 0){
					layerp->offset.y = (layerp->surface->h - stat.image.surface->h) / 2;
				}
				else{
					stat.mainBar.from.w = (int)(pi.full.surface->w*((float)(stat.levelBase % 100) / (float)100));
					stat.mainBar.to.w = stat.mainBar.from.w;
					stat.mainBar.to.y = layerp->surface->h;
					stat.additionBar.from.x = stat.mainBar.from.w;
					stat.additionBar.from.w = pi.full.surface->w - stat.additionBar.from.x;
					if (stat.additionBar.from.w>stat.additionBarWidth) stat.additionBar.from.w = stat.additionBarWidth;
					stat.additionBar.to.w = stat.additionBar.from.w;
					stat.additionBar.to.x = stat.mainBar.to.x + stat.additionBar.from.x;
					stat.additionBar.to.y = stat.mainBar.to.y;
					stat.levelAdditionLayer.to.x = stat.levelBaseLayer.to.x + stat.levelBaseLayer.surface->w;
					stat.gradientBar.to.x = stat.additionBar.to.x;
					stat.gradientBar.to.y = stat.mainBar.to.y;
					stat.backgroundBar.from.w = pi.full.surface->w - stat.additionBar.from.w - stat.mainBar.from.w;
					if (stat.backgroundBar.from.w<0) stat.backgroundBar.from.w = 0;
					stat.backgroundBar.to.y = stat.mainBar.to.y;
					stat.backgroundBar.from.x = pi.full.surface->w - stat.backgroundBar.from.w;
					stat.backgroundBar.to.x = stat.additionBar.to.x + stat.additionBar.from.w;
					stat.backgroundBar.to.w = stat.backgroundBar.from.w;
				}
			}
		}
	}
	stat.image.setZoom(zoom);			renderTexture(&stat.image, stat.image.surface->clip_rect, location);
	stat.statNameLayer.setZoom(zoom);	renderTexture(&stat.statNameLayer, stat.statNameLayer.surface->clip_rect, location + stat.statNameLayer.to*zoom);
	stat.levelBaseLayer.setZoom(zoom);	renderTexture(&stat.levelBaseLayer, stat.levelBaseLayer.surface->clip_rect, location + stat.levelBaseLayer.to*zoom);
	float testf = 1.5f;
	pi.full.setZoom(zoom); pi.full.setHeightZoom(testf);
	if (buttons[findButton("1")].pressed == 0) renderTexture(&pi.full, stat.mainBar.from, stat.mainBar.to*zoom + location);
	if (stat.additionBar.from.w > 0){
		player.inventory.additionBar.full.setZoom(zoom); player.inventory.additionBar.full.setHeightZoom(testf);
		if (buttons[findButton("2")].pressed == 0) renderTexture(&player.inventory.additionBar.full, stat.additionBar.from, stat.additionBar.to*zoom + location);
		stat.levelAdditionLayer.setZoom(zoom); renderTexture(&stat.levelAdditionLayer, stat.levelAdditionLayer.surface->clip_rect, location + stat.levelAdditionLayer.to*zoom);
	}
	pib.full.setZoom(zoom); pib.full.setHeightZoom(testf);
	if (buttons[findButton("3")].pressed == 0) renderTexture(&pib.full, stat.backgroundBar.from, stat.backgroundBar.to*zoom + location);
	if (stat.levelBase % 100 > 1){
		pi.gradient.setZoom(zoom); pi.gradient.setHeightZoom(testf);
		if (buttons[findButton("4")].pressed == 0) renderTexture(&pi.gradient, stat.gradientBar.from, stat.gradientBar.to*zoom + location);
	}
}
void functions::renderStats(bool manageClicks){
	userInterface::StatsTab &UT = UI.TabStats;
	if (UT.open){
		if (clickedOn == "Tab Stats Drag"){
			UT.imageMain.to.x = mouse.location.x + mouseOffsetFromMovableObject.x;
			UT.imageMain.to.y = mouse.location.y + mouseOffsetFromMovableObject.y;
			moveLayerWithinBorder(UT.imageMain, getRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), UT.imageMain.to);
		}
		renderTexture(&UT.imageMain, UT.imageMain.surface->clip_rect, { UT.imageMain.to.x, UT.imageMain.to.y });
		std::vector<character::stat> &statsTab = player.stats[UT.currentSubTab];
		for (Uint8 i = 0; i<statsTab.size(); i++){
			renderStat(statsTab[i],
				{ UT.topLeftLocationOfStats.x + UT.imageMain.to.x,
				UT.topLeftLocationOfStats.y + UT.imageMain.to.y + (int)(i*UT.distanceBetweenStats) },
				UT.imageMain.zoom);
		}
		for (int i = 0; i<3; i++){
			layer &image = UT.category[i].image;
			if (UT.currentSubTab == i) image.color.a = 1.f;
			else image.color.a = 0.6f;
			if (clickedOn == "Stats Tab " + UT.category[i].name) image.color.a += 0.2f;
			renderTexture(&image, image.surface->clip_rect, { image.to.x + UT.imageMain.to.x, UT.catsTopYLocation + UT.imageMain.to.y });
			if (leftMouseButton || leftMouseButtonUp){
				if (pointInsideRect(mouse, getRect(image.to.x + UT.imageMain.to.x, UT.catsTopYLocation + UT.imageMain.to.y, image.w, image.h))){
					if (leftMouseButton&&clickedOn == ""){
						clickedOn = "Stats Tab " + UT.category[i].name;
						leftMouseButton = false;
					}
					else if (leftMouseButtonUp&&clickedOn == "Stats Tab " + UT.category[i].name){
						clickedOn = "";
						UT.currentSubTab = i;
						leftMouseButtonUp = false;
					}
				}
				else if (leftMouseButtonUp&&clickedOn == "Stats Tab " + UT.category[i].name){
					clickedOn = "";
					leftMouseButtonUp = false;
				}
			}
		}
		player.inventory.closeButton.setZoom(UT.imageMain.zoom*0.75f);
		UT.closeButtonLocation = getRect(
			(int)(UT.imageMain.to.x + UT.imageMain.w - player.inventory.closeButton.w - UT.closeButtonOffsetFromTopRight.x * UT.imageMain.zoom),
			(int)(UT.imageMain.to.y + UT.closeButtonOffsetFromTopRight.y * UT.imageMain.zoom),
			player.inventory.closeButton.w,
			player.inventory.closeButton.h);
		if (clickedOn == "Tab Stats Close") player.inventory.closeButton.color.a = 0.6f;
		else player.inventory.closeButton.color.a = 0.8f;
		renderTexture(&player.inventory.closeButton, player.inventory.closeButton.surface->clip_rect, { UT.closeButtonLocation.x, UT.closeButtonLocation.y });
		if (manageClicks){
			if (leftMouseButton && clickedOn == ""){
				if (pointInsideRect(mouse, UT.closeButtonLocation)){
					clickedOn = "Tab Stats Close";
					leftMouseButton = false;
				}
				else if (pointInsideRect(mouse, getRect(UT.imageMain.to.x, UT.imageMain.to.y, UT.imageMain.w, UT.imageMain.h))){
					if (getColorAlpha(getPixelColors(UT.imageMain.surface, (int)((mouse.location.x - UT.imageMain.to.x) / UT.imageMain.zoom), (int)((mouse.location.y - UT.imageMain.to.y) / UT.imageMain.zoom))) != 0){
						clickedOn = "Tab Stats Drag";
						mouseOffsetFromMovableObject = mouse.location - UT.imageMain.to;
						leftMouseButton = false;
					}
				}
			}
			else if (leftMouseButtonUp){
				if (clickedOn == "Tab Stats Drag") {
					mouseOffsetFromMovableObject = { 0, 0 };
					clickedOn = "";
					leftMouseButtonUp = false;
				}
				else if (clickedOn == "Tab Stats Close"){
					if (pointInsideRect(mouse, UT.closeButtonLocation)) UT.open = false;
					clickedOn = "";
					leftMouseButtonUp = false;
				}
			}
		}
	}
	else if (manageClicks){
		if (clickedOn.substr(0, 10) == "Stats Tab " || clickedOn == "Tab Stats Close"){
			clickedOn = "";
		}
		else if (clickedOn == "Tab Stats Drag"){
			clickedOn = "";
			mouseOffsetFromMovableObject = { 0, 0 };
		}
	}
}
void functions::renderMouse(){
	if (mouse.showImage) {
		updateMouseLocation();
		renderTexture(&mouse.image, mouse.image.surface->clip_rect, mouse.location);
	}
}
float functions::renderQuest(quest &Quest, SDL_Point location, bool manageClicks){
	std::string questId = "Quest " + Quest.getName();
	userInterface::QuestsTab &Q = UI.TabQuests; //Quests tab
	SDL_Rectf outlineRect = { location, Q.QRectW*Q.zoom, Q.QRectH*Q.zoom },
			  renderArea = { 0.f, Q.questsRenderArea.y*Q.zoom + Q.location.y, (float)SCREEN_WIDTH, Q.questsRenderArea.h*Q.zoom };
	SDL_Colorf squareColor = { 125.f, 125.f, 255.f, 0.f };
	if(Q.clickedQuest == questId){
		if (!manageClicks){
			squareColor.a = 100.f;
			if (Q.expand) Quest.additionalHeight += 1;
		}
	}
	else if (Quest.collapse){
		if (!manageClicks){
			Quest.additionalHeight -= 1 * 1;
			if (Quest.additionalHeight <= 0) {
				Quest.collapse = false;
				Quest.additionalHeight = 0;
			}
		}
	}
	outlineRect.h += Quest.additionalHeight;
	SDL_Rectf outlineRectHolder = outlineRect;	SDL_Point holderP;	SDL_Rect holderR;
	clip(renderArea, outlineRect, holderR, holderP); outlineRect = { holderP.x, holderP.y, holderR.w, holderR.h };
	if (pointInsideRect(mouse, getRect(outlineRect))){
		if (manageClicks){
			if (leftMouseButton && clickedOn == ""){
				clickedOn = questId;
				leftMouseButton = false;
			}
			else if (leftMouseButtonUp && clickedOn == questId){
				if (Q.clickedQuest != clickedOn){
					Q.clickedQuest = clickedOn;
					Q.expand = true;
					Quest.collapse = true;
				}
				else Q.clickedQuest = "";
				clickedOn = "";
				leftMouseButtonUp = false;
			}
		}
		else if (squareColor.a < 50.f){
			squareColor.a = 50.f;
		}
	}
	else if (manageClicks && leftMouseButtonUp && clickedOn == questId){
		clickedOn = "";
		leftMouseButtonUp = false;
	}
	if (!manageClicks){
		int WH = (int)(Q.questsIconWH*Q.zoom); //icon Width and Height [zoomed]
		SDL_Point qIO = Q.questIconOffset*Q.zoom;//questIconOffset [zoomed]
		int textWidth = (int)(Q.QRectW*Q.zoom - WH - qIO.x * 6);//quest' short description width [zoomed]
		layer &sDesc = *Quest.getShortDescriptionImage((int)(textWidth));
		sDesc.offset = { location.x + qIO.x * 2 + WH, location.y + qIO.y * 2 };
		clip(outlineRectHolder, getRect(sDesc.offset, sDesc.surface->w, sDesc.surface->h), sDesc.from, sDesc.offset);
		if (Q.clickedQuest == questId && Q.expand && (sDesc.from.h == sDesc.surface->h)){
			Q.expand = false;
		}
		clip(renderArea, getRect(sDesc.offset, sDesc.from.w, sDesc.from.h), sDesc.from, sDesc.offset);
		if (clickedOn == questId) squareColor.a += 25.f;
		
		openGLRenderSquare({ squareColor.r / 255.f, squareColor.g / 255.f, squareColor.b / 255.f, squareColor.a / 255.f }, Quest.icon.z, getRect(outlineRect));

		SDL_Rect iconRect = getRect(qIO.x + location.x, qIO.y + location.y + (int)(Quest.additionalHeight / 2), WH, WH);
		clip(renderArea, iconRect, holderR, holderP);
		iconRect = { holderP.x, holderP.y, holderR.w, holderR.h };
		renderTexture(&Quest.icon, getRect((int)(holderR.x*Quest.icon.surface->w / WH), (int)(holderR.y*Quest.icon.surface->h / WH), (int)(iconRect.w*Quest.icon.surface->w / WH), (int)(iconRect.h*Quest.icon.surface->h / WH)), iconRect);

		renderTexture(&sDesc, sDesc.from, sDesc.offset);
	}
	return outlineRectHolder.h;
}
void functions::renderQuestsTab(bool manageClicks){
	userInterface::QuestsTab &Q = UI.TabQuests; //Quests tab
	if (Q.open){
		if (manageClicks){
			if (mouseWheelMotion != 0){//process mouse wheel action [move scroll bar]
				float possibleSliderLocation = Q.ScrollBar.barOffset - mouseWheelMotion*Q.ScrollBar.speed;
				if (possibleSliderLocation>0){
					if (possibleSliderLocation<Q.ScrollBar.furthestPossibleSliderLocation)Q.ScrollBar.barOffset = possibleSliderLocation;
					else Q.ScrollBar.barOffset = (float)(Q.ScrollBar.furthestPossibleSliderLocation);
				}
				else Q.ScrollBar.barOffset = 0;
			}
			SDL_Point questLocation = Q.location + Q.questsRenderArea*Q.zoom; float lastHeights = 0;
			for (Uint8 i = 0; i < player.quests.size(); i++){
				lastHeights += renderQuest(player.quests[i], { questLocation.x, (int)(questLocation.y + i*Q.distanceBetweenQuests*Q.zoom + (Q.ScrollBar.barOffset * Q.ScrollBar.ratioBetweenBarAndOther * -1) + lastHeights) }, manageClicks);
			}
			if (leftMouseButton&&clickedOn == ""){
				if (pointInsideRect(mouse, Q.closeButtonLocation)){
					clickedOn = "Tab Quests Close";
					leftMouseButton = false;
				}
				else if (pointInsideRect(mouse, getRect(Q.location, Q.imageMain.w, Q.imageMain.h))){
					if (getColorAlpha(getPixelColors(Q.imageMain.surface, mouse.location.x - Q.location.x, mouse.location.y - Q.location.y)) != 0){
						mouseOffsetFromMovableObject = mouse.location - Q.location;
						clickedOn = "Tab Quests Drag";
						leftMouseButton = false;
					}
				}
			}
			else if (leftMouseButtonUp){
				if (clickedOn == "Tab Quests Drag"){
					mouseOffsetFromMovableObject = { 0, 0 };
					clickedOn = "";
					leftMouseButtonUp = false;
				}
				else if (clickedOn == "Tab Quests Close"){
					if (pointInsideRect(mouse, Q.closeButtonLocation)) Q.open = false;
					clickedOn = "";
					leftMouseButtonUp = false;
				}
			}
		}
		else{
			//main image   
			if (clickedOn == "Tab Quests Drag") Q.location = mouse.location - mouseOffsetFromMovableObject;
			moveLayerWithinBorder(Q.imageMain, getRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT), Q.location);
			renderTexture(&Q.imageMain, Q.imageMain.surface->clip_rect, Q.location);
			//close button 
			player.inventory.closeButton.setZoom(Q.zoom*0.75f);
			Q.closeButtonLocation = getRect(
				Q.location.x + Q.imageMain.w - player.inventory.closeButton.w - (int)(Q.closeButtonOffsetFromTopRight.x*Q.zoom),
				Q.location.y + (int)(Q.closeButtonOffsetFromTopRight.y*Q.zoom),
				player.inventory.closeButton.w,
				player.inventory.closeButton.h);
			if (clickedOn == "Tab Quests Close") player.inventory.closeButton.color.a = 0.8f;
			else player.inventory.closeButton.color.a = 1.0f;
			renderTexture(&player.inventory.closeButton, player.inventory.closeButton.surface->clip_rect, Q.closeButtonLocation);
			//quests	   
			SDL_Point questLocation = Q.location + Q.questsRenderArea*Q.zoom; float lastHeights = 0;
			for (Uint8 i = 0; i < player.quests.size(); i++){
				lastHeights += renderQuest(player.quests[i], { questLocation.x, (int)(questLocation.y + i*Q.distanceBetweenQuests*Q.zoom + (Q.ScrollBar.barOffset * Q.ScrollBar.ratioBetweenBarAndOther * -1) + lastHeights) });
			}
			lastHeights = lastHeights / Q.zoom / Q.QRectH;
			//scroll  bar
			if (Q.ScrollBar.overallHeight != lastHeights){
				Q.ScrollBar.overallHeight = lastHeights;
				Q.ScrollBar.updateValues();
			}
			renderScrollBar(Q.ScrollBar, Q.location);
		}
	}
	else if (manageClicks){
		if (clickedOn == "Tab Quests Close"){
			clickedOn = "";
		}
		else if (clickedOn == "Tab Quests Drag"){
			mouseOffsetFromMovableObject = { 0, 0 };
			clickedOn = "";
		}
	}
}
void functions::renderScrollBar(userInterface::scrollBar &scrollBar, SDL_Point offset){
	openGLRenderSquare(colorfSliderBC,
		LAYER_UI,
		getRect(
		scrollBar.location + offset,
		scrollBar.sliderWidth,
		(int)scrollBar.bubbleHeight
		)
		);
	openGLRenderSquare(colorfSliderBar,
		LAYER_UI,
		getRect(
		scrollBar.location.x + offset.x,
		scrollBar.location.y + offset.y + (int)scrollBar.barOffset,
		scrollBar.sliderWidth,
		(int)scrollBar.barHeight
		)
		);
}
void functions::renderEquipment(bool manageClicks){
	characterSpace &pi = player.inventory;
	SDL_Point location,
		equipLocStart = pi.equipmentTopLeftLocation + pi.location;
	SDL_Rect slotRect = getRect(0, 0, pi.equipmentAll[0]->image.w, pi.equipmentAll[0]->image.h);
	for (int i = 0; i < pi.equipmentCount; i++){
		location.x = pi.distanceBetweenEquipmentSlots*pi.equipmentAll[i]->x + equipLocStart.x;
		location.y = pi.distanceBetweenEquipmentSlots*pi.equipmentAll[i]->y + equipLocStart.y;
		if (pi.equipmentAll[i]->item.itemCount == 0){
			if (!manageClicks) renderTexture(&pi.equipmentAll[i]->image, pi.equipmentAll[i]->image.surface->clip_rect, location);
		}
		else{
			if (manageClicks && (leftMouseButton || leftMouseButtonUp)){
				slotRect = slotRect + location;
				if (pointInsideRect(mouse, slotRect)){
					if (leftMouseButtonUp){
						if (clickedOn == "Equipment slot " + toString(i)){
							if (doubleLeftClick == -1) doubleLeftClick = FPS / 2;
							else{
								doubleLeftClick = -1;
								unequipItem(i);
							}
						clearEquipClicked:
							if (drag.objectName == "Equipment slot " + toString(i)){//finish draging
								drag.objectName = "";
								if (player.inventory.open){
									int itemId2;
									SDL_Rect slotRect2;
									characterSpace& Space2 = player.inventory;
									for (int y2 = 0; y2 < Space2.rowsInInventory; y2++){
										for (int x2 = 0; x2 < Space2.slotsInOneRow; x2++){
											itemId2 = y2*Space2.slotsInOneRow + x2;
											if (y2 == Space2.rowsInInventory - 1 && itemId2 == Space2.itemStacks.size()){
												x2 = Space2.slotsInOneRow;
											}
											else{
												layer tempLayer = player.inventory.imageInventorySlot[0];
												tempLayer.offset.x = Space2.slotLocationTopLeft.x + x2*Space2.distanceBetweenSlots;
												tempLayer.offset.y = Space2.slotLocationTopLeft.y + y2*Space2.distanceBetweenSlots - (int)(Space2.scrollBar.barOffset*Space2.scrollBar.ratioBetweenBarAndOther);
												clipLayer(tempLayer, Space2.slotBoundary);
												if (tempLayer.from.h > 0){
													slotRect2 = getRect(tempLayer.offset, (int)(tempLayer.from.w*tempLayer.zoom*tempLayer.zoomWidth), (int)(tempLayer.from.h*tempLayer.zoom*tempLayer.zoomHeight));
													if (pointInsideRect(mouse, slotRect2)){//swap items [held item with the item in this inventory item slot]
														unequipItem(i, itemId2);
														goto exitThisEquipSearch;
													}
												}
											}
										}
									}
								}
							exitThisEquipSearch:;
							}
							leftMouseButtonUp = false;
							clickedOn = "";
						}
					}
					else if (leftMouseButton){
						if (clickedOn == ""){
							clickedOn = "Equipment slot " + toString(i);
							leftMouseButton = false;
						}
						if (pi.equipmentAll[i]->item.itemCount > 0){
							drag.objectName = clickedOn;
							drag.ist = &pi.equipmentAll[i]->item;
							drag.From = drag.ist->containingItem.image.surface->clip_rect;
							mouseOffsetFromMovableObject = mouse.location - location;
						}
					}
				}
				else{
					if (leftMouseButtonUp&&clickedOn == "Equipment slot " + toString(i)) goto clearEquipClicked;
				}
			}
			if (!manageClicks) renderTexture(&pi.imageInventorySlot[0], pi.imageInventorySlot[0].surface->clip_rect, location);
			if (drag.objectName != "Equipment slot " + toString(i) && !manageClicks) renderTexture(&pi.equipmentAll[i]->item.containingItem.image, pi.equipmentAll[i]->item.containingItem.image.surface->clip_rect, location);
		}
	}
}
//openGLRender		   
void functions::openGLRender(layer* texture, SDL_Rect* sourceRect, SDL_Rect* destRect){
	if (texture->textureOpenGL != 0){
		openGLRenderSquare(texture->color, texture->z, *destRect, sourceRect, texture);
	}
}
void functions::openGLRenderSquare(SDL_Colorf colorf, float zLocation, SDL_Rect& destRect, SDL_Rect* sourceRect, layer* texture){
	float point[8], cornerX[4], cornerY[4];
	bool hasTexture = sourceRect != nullptr;
	point[0] = 0.f; point[1] = point[0]; point[3] = point[0]; point[6] = point[0];
	point[2] = (float)destRect.w; if (hasTexture) point[2] *= texture->zoom*texture->zoomWidth; point[4] = point[2];
	point[5] = (float)destRect.h; if (hasTexture) point[5] *= texture->zoom*texture->zoomHeight; point[7] = point[5];
	if (hasTexture){
		cornerX[0] = (float)(sourceRect->x) / (float)(texture->surface->w);               cornerX[3] = cornerX[0];
		cornerX[1] = ((float)(sourceRect->w) / (float)(texture->surface->w)) + cornerX[0]; cornerX[2] = cornerX[1];
		cornerY[0] = (float)(sourceRect->y) / (float)(texture->surface->h);               cornerY[1] = cornerY[0];
		cornerY[2] = ((float)(sourceRect->h) / (float)(texture->surface->h)) + cornerY[0]; cornerY[3] = cornerY[2];
	}
	glLoadIdentity();
	glTranslatef((GLfloat)(destRect.x + offset.x), (GLfloat)(destRect.y + offset.y), zLocation);
	if (hasTexture){
		if (texture->rotate){
			glTranslatef(sourceRect->w / 2 * texture->zoom * texture->zoomWidth, sourceRect->h / 2 * texture->zoom * texture->zoomHeight, 0.f);
			glRotatef(texture->rotation, 0.f, 0.f, 1.f);
			glTranslatef(-sourceRect->w / 2 * texture->zoom * texture->zoomWidth, -sourceRect->h / 2 * texture->zoom * texture->zoomHeight, 0.f);
		}
		glBindTexture(GL_TEXTURE_2D, texture->textureOpenGL);
	}
	else glBindTexture(GL_TEXTURE_2D, empty.textureOpenGL);
	glColor4f(colorf.r, colorf.g, colorf.b, colorf.a);
	glBegin(GL_QUADS);
	if (hasTexture) glTexCoord2f(cornerX[0], cornerY[0]);
	else glTexCoord2f(point[0], point[1]);
	glVertex2f(point[0], point[1]);
	if (hasTexture) glTexCoord2f(cornerX[1], cornerY[1]);
	else glTexCoord2f(point[2], point[3]);
	glVertex2f(point[2], point[3]);
	if (hasTexture) glTexCoord2f(cornerX[2], cornerY[2]);
	else glTexCoord2f(point[4], point[5]);
	glVertex2f(point[4], point[5]);
	if (hasTexture) glTexCoord2f(cornerX[3], cornerY[3]);
	else glTexCoord2f(point[6], point[7]);
	glVertex2f(point[6], point[7]);
	glEnd();
}
/*texture*/			   
void functions::renderTexture(layer* texture,SDL_Rect &sourceRect,SDL_Rect &destinationRect){
    openGLRender(texture,&sourceRect,&destinationRect);
}
void functions::renderTexture(layer* texture,SDL_Rect &sourceAndDestRect){
	renderTexture(texture, sourceAndDestRect, sourceAndDestRect);
}
void functions::renderTexture(layer* texture, SDL_Rect &sourceRect, SDL_Point location){
	renderTexture(texture, sourceRect, getRect(location, sourceRect.w, sourceRect.h));
}
//utility			
/*toString*/		   
std::string functions::toString(int number){
	std::stringstream ss;
	ss << number;
	return ss.str();
}
std::string functions::toString(SDL_Point number){
	std::stringstream ss;
	ss << "[" << number.x << ";" << number.y << "]" ;
	return ss.str();
}
std::string functions::toString(double number){
	std::stringstream ss;
	ss << number;
	return ss.str();
}
std::string functions::toString(int* number){
	std::stringstream ss;
	ss << number;
	return ss.str();
}
int  functions::convertNumbersByRelativity(int numberToConvert, int relativeNumberToConvertTo, int relativeNumberToConvertFrom){
	return (numberToConvert*relativeNumberToConvertTo / relativeNumberToConvertFrom);
}
void functions::spawnFlameParticle(){
	if (rand() % (menu.chanceToCreateFlameEachFrame) == 0) {
		fl newFlame;
		newFlame.startPoint = getFlamePoint(menu.flameStartLine);
		newFlame.endPoint = getFlamePoint(menu.flameEndLine);
		if (menu.type == menu.OLD) {
			newFlame.endPoint.y -= rand() % SCREEN_HEIGHT * 4 / 5;
			if (rand() % 2 == 1) {
				newFlame.startPoint.x += SCREEN_WIDTH * 2 / 3;
				newFlame.endPoint.x += SCREEN_WIDTH * 3 / 8;
			}
		}
		newFlame.lifetime = rand() % menu.flameLifeTime.y + menu.flameLifeTime.x;
		newFlame.creationTimeStamp = timeStamp;
		newFlame.oscillationInitialAmplitude = (float)(rand() % 20 + 90);
		newFlame.oscillationEndingAmplitude = (float)(rand() % 7 + 3);
		newFlame.oscillationSpeed = (float)(rand() % 30 + 20);
		newFlame.direction = (rand() % 2) == 1;
		newFlame.initialSize = 1.f / (float)(rand() % 5 + 8);
		newFlame.endingSize = newFlame.initialSize / 4.f;
		newFlame.flameId = rand() % 2;
		newFlame.rotationDirection = (rand() % 2) == 1;
		newFlame.rotationSpeed = rand() % 300 + 150;
		//newFlame.r -= rand() % 25;
		//newFlame.g = newFlame.r - rand() % 25;
		//newFlame.b = newFlame.r - rand() % 25;
		menu.flames.push_back(newFlame);
	}
}
void functions::reset(){
	timeStamp++;
	frame++; if (frame>FPS) frame %= FPS;
	if (doubleLeftClick>-1){
		doubleLeftClick++;
		if (doubleLeftClick >= FPS){
			doubleLeftClick = -1;
		}
	}
	if (currentMenu == MENU_GAME) player.reset();
	if (mouseButton == 2)    mouseButton = false;
	else if (mouseButton)  mouseButton = false;
	if (leftMouseButton)   leftMouseButton = false;
	if (rightMouseButton)  rightMouseButton = false;
	if (leftMouseButtonUp) leftMouseButtonUp = false;
	if (rightMouseButtonUp)rightMouseButtonUp = false;
	if (mouseWheelMotion != false)mouseWheelMotion = false; //Reset mouse wheel motion
	glClear(GL_COLOR_BUFFER_BIT
		| GL_DEPTH_BUFFER_BIT
		);
	updateMouseLocation();
}
void functions::updateMouseLocation() {
	SDL_GetWindowPosition(window, &windowPos.x, &windowPos.y); GetCursorPos(&mouse.point);
	mouse.location.x = mouse.point.x - windowPos.x; mouse.location.y = mouse.point.y - windowPos.y;
}
void functions::processEvents(){
	while (SDL_PollEvent(&e) != 0) {//Go through all events accumulated in the previous tick
		if (e.type == SDL_QUIT) {//If program tries to shut down
			quit = true;//Exit the game loop
		}
		else if (e.type == SDL_KEYDOWN) {//Checks the pressed buttons
			for (keyboard& n : buttons) {//Goes through all buttons inside the buttons variable
				if (e.key.keysym.sym == n.keycode) {//Checks if the event holding the pressed button is the same as the button that is being checked
					if (n.pressed == 0) n.pressed = 1;//If the button is unpressed then mark it as pressed
					goto quitLookingForPressedButtons;//Exits the check for this event
				}
			quitLookingForPressedButtons:;
			}
		}
		else if (e.type == SDL_KEYUP) {//Checks the unpressed buttons
			for (keyboard& n : buttons) {//Goes through all buttons inside the buttons variable
				if (e.key.keysym.sym == n.keycode) {//Checks if the event holding the unpressed button is the same as the button that is being checked
					n.pressed = 0;//Marks the button as unpressed
					goto quitLookingForUnpressedButtons;//Exits the check for this event
				}
			quitLookingForUnpressedButtons:;
			}
		}
		else if (e.type == SDL_MOUSEWHEEL) {//Checks if the mouse wheel was used
			mouseWheelMotion = e.wheel.y;//Sets the mouse wheel value to it's corresponding one -1 to the used, 1 away from the used
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {//Checks if the mouse button was pressed
			if (e.button.button == SDL_BUTTON_LEFT) leftMouseButton = 1;
			else if (e.button.button == SDL_BUTTON_RIGHT) rightMouseButton = 1;
			mouseButton = 1;
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {//Checks if the mouse button was unpressed
			if (e.button.button == SDL_BUTTON_LEFT) leftMouseButtonUp = 1;
			else if (e.button.button == SDL_BUTTON_RIGHT) rightMouseButtonUp = 1;
			mouseButton = 2;
		}
	}
}
void functions::waitForNextFrame(){
	milisecondOffset = (float)(SDL_GetTicks() - milisecond);
	if (milisecondOffset > delay) milisecondOffset = delay;
	SDL_Delay((Uint32)(delay - milisecondOffset)); // control frame rate
	milisecond = SDL_GetTicks();
	reset();
}
bool functions::equalColors(SDL_Color a, SDL_Color b){
	if (a.r == b.r&&a.g == b.g&&a.b == b.b&&a.a == b.a) return true;
	else return false;
}
bool functions::initialize(){
	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING)<0) {
        error("SDL could not initialize! SDL Error: "+(*SDL_GetError()));
		goto initializeFalse;
	}
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

    //Set texture filtering to linear
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2")) error(1);

    //Create window
	#pragma warning(disable : 4806)

	getDesktopResolution(screenStartPosition.x, screenStartPosition.y);
	screenStartPosition.x = (screenStartPosition.x - SCREEN_WIDTH) / 2;
	screenStartPosition.y = (screenStartPosition.y - SCREEN_HEIGHT) / 2;
    window = SDL_CreateWindow( screenName.c_str(), screenStartPosition.x, screenStartPosition.y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | fullscreen);
    if(window==NULL){ //error
        error("Window could not be created! SDL Error: "+(*SDL_GetError()));
		goto initializeFalse;
    }
    
	GLContext=SDL_GL_CreateContext(window);
    if(GLContext==NULL){
		error("OpenGL context could not be created! SDL Error: " + (*SDL_GetError()));
		goto initializeFalse;
    }

    if(SDL_GL_SetSwapInterval(1)<0){
        error( "Warning: Unable to set VSync! SDL Error: "+(*SDL_GetError()));
    }

    if(!initGL()){
		error("Unable to initialize OpenGL!");
		goto initializeFalse;
    }

    SDL_VERSION(&WindowInfo.version);
    SDL_GetWindowWMInfo(window,&WindowInfo);
    hwnd=WindowInfo.info.win.window;

    //Create renderer for window
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if(renderer==NULL) { //error
		error("Renderer could not be created! SDL Error: " + (*SDL_GetError()));
		goto initializeFalse;
    }

    //Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
    if( !(IMG_Init(imgFlags) & imgFlags ) ) {//error
		error("SDL_image could not initialize! SDL_image Error: " + (*IMG_GetError()));
		goto initializeFalse;
    }

    if(TTF_Init()<0) {//error
		error("SDL_ttf could not initialize! SDL_ttf Error: " + (*SDL_GetError()));
		goto initializeFalse;
    }

	loadImage("Graphics\\menu slices\\favicon_seti.png", iconMain);
    SDL_SetWindowIcon(window,iconMain.surface);
	SDL_ShowCursor(0);
	loadImage("Graphics\\rest of ui\\cursor.png", mouse.image);
	mouse.image.setZoom(1.f / 9.f);

	int flags = MIX_INIT_MP3;
	if (!Mix_Init(flags) | 
		(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0)){//error
		error("SDL_mixer could not initialize! SDL_mixer Error: " + (*Mix_GetError()));
		goto initializeFalse;
	}

	loadMedia();//Pre-load images and variables

	glClear(GL_COLOR_BUFFER_BIT
		| GL_DEPTH_BUFFER_BIT
		);
	updateMouseLocation();

	return true;
	initializeFalse: return false;
}
bool functions::initGL(){
	glEnable(GL_TEXTURE_2D); //Enable texturing
	glEnable(GL_DEPTH_TEST); //Enable Depth testing
	glDepthFunc(GL_LEQUAL);

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT); //Set the viewport

    glMatrixMode( GL_PROJECTION ); //Initialize Projection Matrix
	glLoadIdentity();

    glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 0.1, 100.0 );//Initialize the projection

	glMatrixMode(GL_MODELVIEW); //Initialize Modelview Matrix
    glLoadIdentity();

    //Initialize clear color
	glAlphaFunc(GL_GREATER, (GLclampf)0.0);
	glEnable(GL_ALPHA_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR ){
        return false;
    }

    return true;
}
void functions::close() {
    //Destroy window
	SDL_DestroyRenderer(renderer);	renderer =	NULL;
	SDL_DestroyWindow(window);		window	=	NULL;

	Mix_FreeChunk(sfxStartMenu); sfxStartMenu = NULL;

	Mix_FreeMusic(musicStartMenu); musicStartMenu = NULL;
	
	//Quit SDL subsystems
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
//create			
info		functions::createTask_GetItem(std::string itemName, int itemCount){
	info infoTemp;
	infoTemp.addInfo(itemName);
	infoTemp.addInfo(itemCount);
	return infoTemp;
}
quest&		functions::createQuest(){
	quest questTemp;
	quests.push_back(questTemp);
	return quests[quests.size() - 1];
}
map*		functions::createBattleZone(std::string name, std::string id, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8, int x9, int y9, int x0, int y0){
	map &mapRef = *createMap(name, id);
	SDL_Point location;
	location.x = x1; location.y = y1; mapRef.platforms.push_back(location);
	location.x = x2; location.y = y2; mapRef.platforms.push_back(location);
	location.x = x3; location.y = y3; mapRef.platforms.push_back(location);
	location.x = x4; location.y = y4; mapRef.platforms.push_back(location);
	location.x = x5; location.y = y5; mapRef.platforms.push_back(location);
	location.x = x6; location.y = y6; mapRef.platforms.push_back(location);
	location.x = x7; location.y = y7; mapRef.platforms.push_back(location);
	location.x = x8; location.y = y8; mapRef.platforms.push_back(location);
	location.x = x9; location.y = y9; mapRef.platforms.push_back(location);
	location.x = x0; location.y = y0; mapRef.platforms.push_back(location);
	return &mapRef;
}
map*		functions::createMap(std::string name, std::string id){
	map map_temp;
	map_temp.name = name;
	map_temp.id = id;
	maps.push_back(map_temp);
	return &maps[maps.size() - 1];
}
gather*		functions::createGatherable(int mapId, int gatherableLocationX, int gatherableLocationY, bool colidable, float gatherTime, int requiredLevel, std::string requiredSkillName){
	//also need to call createEvent function, addStage function, addGatherableReturnItemStack
	gather gather_temp;
	gather_temp.colidable = colidable;
	gather_temp.gatherTime = gatherTime;
	gather_temp.requiredLevel = requiredLevel;
	gather_temp.requiredSkillName = requiredSkillName;
	gather_temp.offset.x = gatherableLocationX;
	gather_temp.offset.y = gatherableLocationY;
	map &mapRef = maps[mapId];
	mapRef.gatherable.push_back(gather_temp);
	return &mapRef.gatherable[mapRef.gatherable.size() - 1];
}
void		functions::createZone(int mapId, std::string owner, std::string zoneName){
	zone zone_temp;
	map &mapRef = maps[mapId];
	if (mapRef.layers.size()>0) {
		zone_temp.id = getZoneId(mapRef.layers[0].surface);
		if (zone_temp.id != -1){
			zone_temp.owner = owner;
			zone_temp.name = zoneName;
			zone_temp.color = getColor(zone_temp.id);
			mapRef.zones.push_back(zone_temp);
		}
		else error("The program was unable to create a zone. [Info: owner=" + owner + "; zoneName=" + zoneName + ";");
	}
	else error("The program was unable to create a zone, because the map has no layers;");
}
interact*	functions::createInteractable(int mapId, std::string imagePath, int interactableLocationX, int interactableLocationY, bool isInteractableColidable){
	interact interactable_temp;
	if (loadImage(imagePath, interactable_temp) == 0){
		interactable_temp.z = LAYER_BACKGROUND;
		interactable_temp.colidable = isInteractableColidable;
		interactable_temp.offset.x = interactableLocationX;
		interactable_temp.offset.y = interactableLocationY;
		map &mapRef = maps[mapId];
		mapRef.interactable.push_back(interactable_temp);
		return &mapRef.interactable[mapRef.interactable.size() - 1];
	}
	else error("The program was unable to create an interactable. [Info: imagePath=" + imagePath + "; x=" + toString(interactableLocationX) + "; y=" + toString(interactableLocationY) + "; colidable=" + toString(isInteractableColidable) + ";]");
	return NULL;
}
interact*	functions::createInteractable(int mapId, std::string imagePath, int interactableLocationX, int interactableLocationY, int w, int h, bool isInteractableColidable){
	interact interactable_temp;
	if (loadImage(imagePath, interactable_temp) == 0){
		interactable_temp.z = LAYER_BACKGROUND;
		interactable_temp.colidable = isInteractableColidable;
		interactable_temp.offset.x = interactableLocationX;
		interactable_temp.offset.y = interactableLocationY;
		interactable_temp.setHeightZoom((float)h / (float)interactable_temp.surface->h);
		interactable_temp.setWidthZoom((float)w / (float)interactable_temp.surface->w);
		map &mapRef = maps[mapId];
		mapRef.interactable.push_back(interactable_temp);
		return &mapRef.interactable[mapRef.interactable.size() - 1];
	}
	else error("The program was unable to create an interactable. [Info: imagePath=" + imagePath + "; x=" + toString(interactableLocationX) + "; y=" + toString(interactableLocationY) + "; colidable=" + toString(isInteractableColidable) + ";]");
	return NULL;
}
void		functions::createObject(int mapId, std::string imagePath, int objectLocationX, int objectLocationY, bool isObjectColidable){
	objects object_temp;
	if (loadImage(imagePath, object_temp) == 0){
		object_temp.offset.x = objectLocationX;
		object_temp.offset.y = objectLocationY;
		object_temp.colidable = isObjectColidable;
		map &mapRef = maps[mapId];
		mapRef.object.push_back(object_temp);
	}
	else error("The program was unable to create an object. [Info: imagePath=" + imagePath + "; objectLocationX=" + toString(objectLocationX) + "; objectLocationY=" + toString(objectLocationY) + "; isObjectColidable=" + toString(isObjectColidable) + ";");
}
void		functions::createLayer(int mapId, std::string imagePath){
	layer layer_temp;
	if (loadImage(imagePath, layer_temp) == 0){
		layer_temp.z = LAYER_BACKGROUND;
		layer_temp.setHeightZoom((float)SCREEN_HEIGHT / (float)layer_temp.surface->h);
		layer_temp.setWidthZoom((float)SCREEN_WIDTH / (float)layer_temp.surface->w);
		map &mapRef = maps[mapId];
		mapRef.layers.push_back(layer_temp);
	}
	else error("The program was unable to create a layer. [Info: imagePath=" + imagePath + ";");
}
//add				
void		functions::addGatherableReturnItemStack(int itemCount, item containingItem, gather &gatherableTypeVar){
	itemStack itemStack_temp;
	itemStack_temp.itemCount = itemCount;
	itemStack_temp.containingItem = containingItem;
	gatherableTypeVar.returnItems.push_back(itemStack_temp);
}
stage*		functions::addStage(float timeUntilNextStage, bool isItAShortcutStage, bool isItGatherable, std::string imagePath, gather &gatherableTypeVar){
	stage stage_temp;
	if (loadImage(imagePath, stage_temp.image) == 0){
		stage_temp.image.z = LAYER_BACKGROUND;
		stage_temp.timeUntilNextStage = timeUntilNextStage;
		stage_temp.shortcut = isItAShortcutStage;
		stage_temp.isItGatherable = isItGatherable;
		gatherableTypeVar.stages.push_back(stage_temp);
		return &gatherableTypeVar.stages[gatherableTypeVar.stages.size() - 1];
	}
	else error("The program was unable to create an interactable. [Info: " +
		toString(timeUntilNextStage) + "=timeUntilNextStage" + ";\n" +
		"isItAShortcutStage=" + toString(isItAShortcutStage) + ";\n" +
		"imagePath=" + imagePath + ";\n" +
		"]");
	return NULL;
}
void		functions::addItem(std::string name, std::string type, std::string imagePath){
	item item_temp;
	item_temp.name = name;
	item_temp.type = type;
	if (loadImage(imagePath, item_temp.image) == 0){
		item_temp.image.z = LAYER_UI;
		item_temp.image.setWidthZoom((float)player.inventory.imageInventorySlot[0].w / (float)item_temp.image.surface->w);
		item_temp.image.setHeightZoom((float)player.inventory.imageInventorySlot[0].h / (float)item_temp.image.surface->h);
		items.push_back(item_temp);
	}
}
void		functions::addEnemyId(std::string enemyName){
	battleEnemiesIds.push_back(findEntity(enemyName));
}
void		functions::addEntity(float healthPoints, float level, float manaPoints, std::string name, std::string imagePath, double legCenterX, double legCenterY){
	entity entity_temp;
	entity_temp.healthPoints = healthPoints;
	entity_temp.level = level;
	entity_temp.manaPoints = manaPoints;
	entity_temp.name = name;
	if (loadImage(imagePath, entity_temp.image) == 0){
		entity_temp.legCenter.x = legCenterX / entity_temp.image.surface->w;
		entity_temp.legCenter.y = legCenterY / entity_temp.image.surface->h;
		entities.push_back(entity_temp);
	}
}
void		functions::addSpell(std::string type, float damage, float manaCost, std::string base, std::string icon_active, std::string icon_cooldown, int x, int y){
	spell spell_temp;
	spell_temp.elementType = type;
	spell_temp.damage = damage;
	spell_temp.manaCost = manaCost;
	spell_temp.offset.x = x;
	spell_temp.offset.y = y;
	if (loadImage(base, spell_temp.base) == 0 && loadImage(icon_active, spell_temp.icon_active) == 0 && loadImage(icon_cooldown, spell_temp.icon_cooldown) == 0){
		Spells.push_back(spell_temp);
	}

}
void		functions::addButton(std::string name, SDL_Keycode key){
	keyboard button_temp;
	button_temp.name = name;
	button_temp.keycode = key;
	buttons.push_back(button_temp);
}
void		functions::addObstruction(int r, int g, int b, int a){
	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	obstructions.push_back(color);
}
void		functions::addObstruction(SDL_Color color){
	obstructions.push_back(color);
}
void		functions::addColor(int r, int g, int b, int a){
	SDL_Color color_temp;
	color_temp.r = r;
	color_temp.g = g;
	color_temp.b = b;
	color_temp.a = a;
	Colors.push_back(color_temp);
}
void		functions::addColor(int r, int g, int b){
	SDL_Color color_temp;
	color_temp.r = r;
	color_temp.g = g;
	color_temp.b = b;
	color_temp.a = 255;
	Colors.push_back(color_temp);
}
//get				
void		functions::getEntityCornerColors(SDL_Surface* surface, SDL_Color colorHolder[4], SDL_Point pixelLocation[4]){
	std::stringstream ss;
	SDL_Rect rect;
	for (int i = 0; i<4; i++) {
		rect.x = player.image.offset.x;
		rect.y = player.image.offset.y;
		rect.w = player.image.surface->w;
		rect.h = player.image.surface->h;
		getEntityCorner(i + 1, player.location, rect, pixelLocation[i]);
		pixelLocation[i].x = pixelLocation[i].x*surface->w / SCREEN_WIDTH;
		pixelLocation[i].y = pixelLocation[i].y*surface->h / SCREEN_HEIGHT;
		getPixelColors(surface, pixelLocation[i].x,
			pixelLocation[i].y,
			colorHolder[i]);
		if (buttons[findButton("F")].pressed == 1) ss << "[" << pixelLocation[i].x << ";" << pixelLocation[i].y << "]=[" << toString(colorHolder[i].r) << "," << toString(colorHolder[i].g) << "," << toString(colorHolder[i].b) << "," << toString(colorHolder[i].a) << "]\n";
	}
	if (buttons[findButton("F")].pressed == 1) error(ss.str());
}
void		functions::getEntityCorner(int corner, SDL_Point entityLocation, SDL_Rect& entityRect, SDL_Point &locationHolder){
	locationHolder = entityLocation;
	switch (corner){
	case 2:
		locationHolder.x += entityRect.w;
		break;
	case 3:
		locationHolder.x += entityRect.w;
		locationHolder.y += entityRect.h;
		break;
	case 4:
		locationHolder.y += entityRect.h;
		break;
	}
}
void		functions::getDesktopResolution(int& width, int& height){
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow(); // Get a handle to the desktop window
	GetWindowRect(hDesktop, &desktop); // Get the size of screen to the variable desktop
	width = desktop.right;
	height = desktop.bottom;
}
SDL_Point	functions::getPointBetweenTwo(SDL_Point& pointA, SDL_Point& pointB, float distanceBetweenPoints) {
	return pointA + (pointB - pointA)*distanceBetweenPoints;
}
SDL_Point	functions::getFlamePoint(variables::chance& pointsHolder){
	return getPointBetweenTwo(pointsHolder.from, pointsHolder.to, (rand() % 10000) / 10000.f);
}
float		functions::getDistanceBetweenTwoPoints(SDL_Point &pointA, SDL_Point &pointB){
	return (float)sqrt(pow((pointA.x - pointB.x), 2) + pow((pointA.y - pointB.y), 2));
}
void		functions::getPixelColors(SDL_Surface* surface, int x, int y, SDL_Color &colorHolder){
	SDL_PixelFormat *format;
	Uint32 temp, pixel;
	Uint8 color[4];

	format = surface->format;
	SDL_LockSurface(surface);
	pixel = getPixel(surface, x, y);
	SDL_UnlockSurface(surface);

	temp = pixel&format->Rmask; /* Isolate red component */
	temp = temp >> format->Rshift;/* Shift it down to 8-bit */
	temp = temp << format->Rloss; /* Expand to a full 8-bit number */
	color[0] = (Uint8)temp;

	temp = pixel&format->Gmask; /* Isolate green component */
	temp = temp >> format->Gshift;/* Shift it down to 8-bit */
	temp = temp << format->Gloss; /* Expand to a full 8-bit number */
	color[1] = (Uint8)temp;

	temp = pixel&format->Bmask; /* Isolate blue component */
	temp = temp >> format->Bshift;/* Shift it down to 8-bit */
	temp = temp << format->Bloss; /* Expand to a full 8-bit number */
	color[2] = (Uint8)temp;

	temp = pixel&format->Amask; /* Isolate alpha component */
	temp = temp >> format->Ashift;/* Shift it down to 8-bit */
	temp = temp << format->Aloss; /* Expand to a full 8-bit number */
	color[3] = (Uint8)temp;

	colorHolder.r = color[0];
	colorHolder.g = color[1];
	colorHolder.b = color[2];
	colorHolder.a = color[3];
}
SDL_Rect	functions::getRect(SDL_Point location, int w, int h){
	return getRect(location.x, location.y, w, h);
}
SDL_Rect	functions::getRect(int x, int y, int w, int h){
	SDL_Rect returnValue;
	returnValue.x = x;
	returnValue.y = y;
	returnValue.w = w;
	returnValue.h = h;
	return returnValue;
}
SDL_Rect	functions::getRect(SDL_Rectf Rectf){
	return{ (int)Rectf.x, (int)Rectf.y, (int)Rectf.w, (int)Rectf.h };
}
libs::SDL_Rectf	functions::getRectf(SDL_Rect Rect){
	return{ Rect.x, Rect.y, Rect.w, Rect.h};
}
SDL_Color	functions::getColor(int id){
	if (id>0 && (Uint8)id<Colors.size()){
		return Colors[id - 1];
	}
	error("There's no color with id " + id);
	SDL_Color color = { 255, 255, 255, 255 };
	return color;
}
SDL_Color	functions::getPixelColors(SDL_Surface* surface, int x, int y){
	SDL_Color colorHolder;
	getPixelColors(surface, x, y, colorHolder);
	return colorHolder;
}
int			functions::getColorAlpha(SDL_Color color){
	return color.a;
}
int			functions::getZoneId(SDL_Surface* secretLayer){ //returns -1 if it doesn't find the corresponding color
	SDL_Color color;
	getPixelColors(secretLayer, player.location.x, player.location.y, color);
	for (Uint8 i = 0; i<Colors.size(); i++){
		if (equalColors(color, getColor(i))){
			return i;
		}
	}
	error("Color [" + toString(color.r) + "," + toString(color.g) + "," + toString(color.b) + "," + toString(color.a) + "] is not in the color list.");
	return -1;
}
Uint32		functions::getPixel(SDL_Surface *surface, int x, int y){
	int bpp = surface->format->BytesPerPixel;
	/* Here p is the address to the pixel we want to retrieve */
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp) {
	case 1:
		return *p;
		break;

	case 2:
		return *(Uint16 *)p;
		break;

	case 3:
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return p[0] << 16 | p[1] << 8 | p[2];
		else
			return p[0] | p[1] << 8 | p[2] << 16;
		break;

	case 4:
		return *(Uint32 *)p;
		break;

	default:
		return 0;       /* shouldn't happen, but avoids warnings */
	}
}
//find				
int functions::findButton(std::string name){
	for (Uint8 i = 1; i<buttons.size(); i++){
		if (buttons[i].name == name){
			return i;
		}
	}
	error("Button by the name of " + name + " was not found, fix the program!");
	return 0;
}
int functions::findEntity(std::string name){
	for (Uint8 i = 0; i<entities.size(); i++){
		if (entities[i].name == name){
			return i;
		}
	}
	error(name + " entity was not found, fix the program you lazy programmer!");
	return -1;
}
int functions::findImage(std::string imageIdInFormOfString){
	for (Uint8 i = 0; i<images.size(); i++){
		if (images[i].id == imageIdInFormOfString){
			return i;
		}
	}
	error(imageIdInFormOfString + " image was not found, fix the program you lazy programmer!");
	return -1;
}
int functions::findNextStage(std::vector<stage> &stages, int currentStage){
	for (int i = currentStage + 1; i<(int)stages.size(); i++){
		if (stages[i].shortcut){
			return i;
		}
	}
	return 0;
}
int functions::findItem(std::string itemName){
	for (Uint8 i = 0; i<items.size(); i++){
		if (items[i].name == itemName){
			return i;
		}
	}
	error(itemName + " item was not found, fix the program you lazy programmer!");
	return -1;
}
//Images & Rects	
/*copySurface*/		   
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect, SDL_Rect &destinationRect){
	if (SDL_BlitSurface(sourceSurface, &sourceRect, destinationSurface, &destinationRect) != 0){
		error(SDL_GetError());
	}
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceAndDestRect){
	if (SDL_BlitSurface(sourceSurface, &sourceAndDestRect, destinationSurface, &sourceAndDestRect) != 0){
		error(SDL_GetError());
	}
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect, bool fillSurface){
	SDL_Rect destinationRect;
	if (fillSurface){
		destinationRect.x = 0;                destinationRect.y = 0;
		destinationRect.w = sourceSurface->w; destinationRect.h = sourceSurface->h;
		if (SDL_BlitSurface(sourceSurface, &sourceRect, destinationSurface, &destinationRect) != 0){
			error(SDL_GetError());
		}
	}
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1, int x2, int y2){
	SDL_Rect sourceRect, destinationRect;
	sourceRect.x = x1;      sourceRect.y = y1;
	sourceRect.w = w1;      sourceRect.h = h1;
	destinationRect.x = x2; destinationRect.y = y2;
	destinationRect.w = w1; destinationRect.h = h1;
	if (SDL_BlitSurface(sourceSurface, &sourceRect, destinationSurface, &destinationRect) != 0){
		error(SDL_GetError());
	}
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
	SDL_Rect sourceRect, destinationRect;
	sourceRect.x = x1;      sourceRect.y = y1;
	sourceRect.w = w1;      sourceRect.h = h1;
	destinationRect.x = x2; destinationRect.y = y2;
	destinationRect.w = w2; destinationRect.h = h2;
	if (SDL_BlitSurface(sourceSurface, &sourceRect, destinationSurface, &destinationRect) != 0){
		error(SDL_GetError());
	}
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect, int x, int y, int w, int h){
	SDL_Rect destinationRect;
	destinationRect.x = x; destinationRect.y = y;
	destinationRect.w = w; destinationRect.h = h;
	if (SDL_BlitSurface(sourceSurface, &sourceRect, destinationSurface, &destinationRect) != 0){
		error(SDL_GetError());
	}
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect, int x, int y){
	SDL_Rect destinationRect;
	destinationRect.x = x; destinationRect.y = y;
	destinationRect.w = sourceRect.w; destinationRect.h = sourceRect.h;
	if (SDL_BlitSurface(sourceSurface, &sourceRect, destinationSurface, &destinationRect) != 0){
		error(SDL_GetError());
	}
}
/*other*/			   
bool functions::pointInsideRect(SDL_Point point, SDL_Rect rect) {
	if (
		point.x >= rect.x + offset.x
		&&
		point.x <= rect.x + rect.w + offset.x
		&&
		point.y >= rect.y + offset.y
		&&
		point.y <= rect.y + rect.h + offset.y
		) return true;
	return false;
}
bool functions::pointInsideRect(_mouse mouse, SDL_Rect rect) {
	return pointInsideRect(mouse.location, rect);
}
void functions::createImage(std::string imagePath, std::string imageIdInFormOfString){
	img image_temp;
	image_temp.id = imageIdInFormOfString;
	if (loadImage(imagePath, image_temp.image) == 0){
		images.push_back(image_temp);
	}
	else error("The program was unable to create an image. [Info: imagePath=" + imagePath + ";");
}
void functions::createSurface(SDL_Surface** surfaceDestination, int width, int height){
	*surfaceDestination = SDL_CreateRGBSurface(0,
		width,
		height,
		32,
		0x000000ff,
		0x0000ff00,
		0x00ff0000,
		0xff000000);
}
void functions::clipLayer(layer &layeRef, SDL_Rect boundary){
	clip(boundary, getRect(layeRef.offset, layeRef.w, layeRef.h), layeRef.from, layeRef.offset);
	layeRef.from = getRect(
		(int)(layeRef.from.x / layeRef.zoom / layeRef.zoomWidth),
		(int)(layeRef.from.y / layeRef.zoom / layeRef.zoomHeight),
		(int)(layeRef.from.w / layeRef.zoom / layeRef.zoomWidth),
		(int)(layeRef.from.h / layeRef.zoom / layeRef.zoomHeight));
}
void functions::clip(SDL_Rectf boundary, SDL_Rectf rectToClip, SDL_Rectf &surfaceResult, SDL_Point &locationResult){
	surfaceResult.x = 0;			surfaceResult.y = 0;
	surfaceResult.w = rectToClip.w; surfaceResult.h = rectToClip.h;
	if (rectToClip.x < boundary.x){ //clip left
		surfaceResult.x = boundary.x - rectToClip.x;
		surfaceResult.w = rectToClip.w - surfaceResult.x;
	}
	if (rectToClip.x + rectToClip.w > boundary.x + boundary.w){//clip right
		surfaceResult.w = boundary.x + boundary.w - rectToClip.x;
	}
	if (rectToClip.y < boundary.y){ //clip top
		surfaceResult.y = boundary.y - rectToClip.y;
		surfaceResult.h = rectToClip.h - surfaceResult.y;
	}
	if (rectToClip.y + rectToClip.h > boundary.y + boundary.h){//clip bot
		surfaceResult.h = boundary.y + boundary.h - rectToClip.y;
	}
	if (surfaceResult.w < 0) surfaceResult.w = 0;
	if (surfaceResult.h < 0) surfaceResult.h = 0;
	locationResult = { (int)(rectToClip.x + surfaceResult.x), (int)(rectToClip.y + surfaceResult.y) };
}
void functions::clip(SDL_Rect boundary, SDL_Rect rectToClip, SDL_Rect &surfaceResult, SDL_Point &locationResult){
	SDL_Rectf surfaceResultf = getRectf(surfaceResult);
	clip(getRectf(boundary), getRectf(rectToClip), surfaceResultf, locationResult);
	surfaceResult = getRect(surfaceResultf);
}
void functions::clip(SDL_Rectf boundary, SDL_Rectf rectToClip, SDL_Rect &surfaceResult, SDL_Point &locationResult){
	SDL_Rectf surfaceResultf = getRectf(surfaceResult);
	clip(boundary, rectToClip, surfaceResultf, locationResult);
	surfaceResult = getRect(surfaceResultf);
}
void functions::clip(SDL_Rectf boundary, SDL_Rect rectToClip, SDL_Rect &surfaceResult, SDL_Point &locationResult){
	SDL_Rectf surfaceResultf = getRectf(surfaceResult);
	clip(boundary, getRectf(rectToClip), surfaceResultf, locationResult);
	surfaceResult = getRect(surfaceResultf);
}
void functions::moveLayerWithinBorder(layer& layeref, SDL_Rect border, SDL_Rect& location){
	SDL_Point temp = { location.x, location.y };
	moveLayerWithinBorder(layeref, border, temp);
	location.x = temp.x; location.y = temp.y;
}
void functions::moveLayerWithinBorder(layer& layeref, SDL_Rect border, SDL_Point& location){
	if (location.x < border.x) location.x = border.x;
	else if (location.x + layeref.w > border.x + border.w) location.x = border.x + border.w - layeref.w;
	if (location.y < border.y) location.y = border.y;
	else if (location.y + layeref.h > border.y + border.h) location.y = border.y + border.h - layeref.h;
}
SDL_Surface* functions::createSurface(int width, int height){
	SDL_Surface* returnValue = NULL;
	createSurface(&returnValue, width, height);
	return returnValue;
}
//