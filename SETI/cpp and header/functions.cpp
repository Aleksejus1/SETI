#include "functions.h"

functions::functions():
UI(this),
player(this),
menuTxl(this){
    if(true){//stuff
        UI.all[0]->update=&player.updateHealth;     UI.all[0]->countAmount=&player.healthPoints;     UI.all[0]->max_countAmount=&player.healthPointsMax;
        UI.all[1]->update=&player.updateMana;       UI.all[1]->countAmount=&player.manaPoints;       UI.all[1]->max_countAmount=&player.manaPointsMax;
        UI.all[2]->update=&player.updateExperience; UI.all[2]->countAmount=&player.experiencePoints; UI.all[2]->max_countAmount=&player.experienceRequiredForNextLevel;
        UI.bar_green.update=&player.updateType;
        UI.level.update=&player.updateLevel; UI.level.countAmount=&player.level;
        player.healthPointsMax=999.0;
        player.addHealth(player.healthPointsMax-333);
        player.manaPointsMax=820.0;
        player.addMana(player.manaPointsMax-800);
        player.experienceRequiredForNextLevel=100.0;
        player.addExperience(125.0);
        player.location.x=320;//sets the starting x position of the player
        player.location.y=420;//sets the starting y position of the player
        player.map_location=1;//sets the starting map id of the player
        player.inventory.addItemStacks((2+8)*4+2);
        player.setType("EGYPTIAN WARRIOR");
        addColor(0,0,0);
        addColor(255,0,0);
        addColor(0,255,0);
        addColor(0,0,255);
        createSurface(&consoleVariables.surface,CONSOLE_SCREEN_WIDTH/2,CONSOLE_SCREEN_HEIGHT/2);
        createSurface(&consoleMessages.surface,CONSOLE_SCREEN_WIDTH,CONSOLE_SCREEN_HEIGHT/2);
    }
    if(true){//flame particle stuff
        menu.chanceToCreateFlameEachFrame=FPS/10;
        menu.flameStartLine.from=0;
        menu.flameStartLine.width=SCREEN_WIDTH*1/3;
        menu.flameEndLine.from=0;
        menu.flameEndLine.width=SCREEN_WIDTH*5/8;
        menu.flameLifeTime.from=600;//1600;
        menu.flameLifeTime.width=1400;
    }
}

void functions::loadMedia(){
    if(true){//add buttons
        addButton("Always false",SDLK_d);
        addButton("D",SDLK_d);
        addButton("A",SDLK_a);
        addButton("S",SDLK_s);
        addButton("W",SDLK_w);
        addButton("Right",SDLK_RIGHT);
        addButton("Left",SDLK_LEFT);
        addButton("Down",SDLK_DOWN);
        addButton("Up",SDLK_UP);
        addButton("F",SDLK_f);
        addButton("G",SDLK_g);
        addButton("E",SDLK_e);
        addButton("I",SDLK_i);
        addButton("Left Shift",SDLK_LSHIFT);
        addButton("N",SDLK_n);
        addButton("Esc",SDLK_ESCAPE);
        addButton("Z",SDLK_z);
        addButton("Q",SDLK_q);
        addButton("R",SDLK_r);
        addButton("Tab",SDLK_TAB);
	}
    if(GLStage==STAGE_SDL){
    if(true){//create player
        loadImage("qpm\\player.png",player.image);
	}
	if(true){//add obstructions
        addObstruction(0,0,10,255);
        addObstruction(0,0,200,255);
	}
	if(true){//add spells/attacks
        addSpell("Spell", 1337, 0, "qpm\\1st spell.png", "qpm\\icon_active.png", "qpm\\icon_cooldown.png", 50,50);
        Spells[0].icon_active.setWidthZoom((float)50/(float)Spells[0].icon_active.surface->w);
        Spells[0].icon_active.setHeightZoom((float)50/(float)Spells[0].icon_active.surface->h);
        Spells[0].icon_cooldown.setWidthZoom((float)50/(float)Spells[0].icon_cooldown.surface->w);
        Spells[0].icon_cooldown.setHeightZoom((float)50/(float)Spells[0].icon_cooldown.surface->h);
	}
	if(true){//create entities/mobs
        addEntity(20.0,1,0.0,"Zombie","qpm\\Zombie.png",184,478);
        entities[entities.size()-1].image.setZoom((float)player.image.surface->h/(float)entities[entities.size()-1].image.surface->w);
        addEntity(20.0,1,0.0,"Zombie_mini","qpm\\Zombie.png",184,478);
        entities[entities.size()-1].image.setZoom((float)player.image.surface->w/(float)entities[entities.size()-1].image.surface->h);
        addEntity(20.0,1,0.0,"debug_1","qpm\\debug_1.png",147,488);
        entities[entities.size()-1].image.setZoom((float)player.image.surface->w/(float)entities[entities.size()-1].image.surface->h);
        addEntity(20.0,1,0.0,"debug_2","qpm\\debug_2.png",147,488);
        entities[entities.size()-1].image.setZoom((float)player.image.surface->w/(float)entities[entities.size()-1].image.surface->h);
        addEntity(20.0,1,0.0,"debug_3","qpm\\debug_3.png",147,488);
        entities[entities.size()-1].image.setZoom((float)player.image.surface->w/(float)entities[entities.size()-1].image.surface->h);
        addEntity(20.0,1,0.0,"debug_4","qpm\\debug_4.png",147,488);
        entities[entities.size()-1].image.setZoom((float)player.image.surface->w/(float)entities[entities.size()-1].image.surface->h);
        addEntity(20.0,1,0.0,"debug_5","qpm\\debug_5.png",147,488);
        entities[entities.size()-1].image.setZoom((float)player.image.surface->w/(float)entities[entities.size()-1].image.surface->h);
	}
	if(true){//create images
        createImage("qpm\\base.png","base");
        images[images.size()-1].image.setZoom(0.35f);
        createImage("qpm\\progressBarFrame.png","progressBarFrame");
        createImage("qpm\\progressBarInside.png","progressBarInside");
	}
    if(true){//create UI
    if(true){//create Battle UI
        createImage("qpm\\BattleUI.png","battleUI");
        images[images.size()-1].image.setZoom((float)SCREEN_WIDTH/(float)images[images.size()-1].image.surface->w);
	}
	if(true){//create Character UI
        loadImage("Graphics\\Top Left UI\\ui_character_v1.png",UI.characterUI);
            UI.characterUI.setZoom(characterUiZoom);
        loadImage("Graphics\\Top Left UI\\red_bar.png",UI.bar_red.bar);
            UI.bar_red.bar.setZoom(characterUiZoom);
                UI.bar_red.bar.location.x=UI.characterUI.w*360/1113;
                UI.bar_red.bar.location.y=UI.characterUI.h*192/471;
        loadImage("Graphics\\Top Left UI\\blue_bar.png",UI.bar_blue.bar);
            UI.bar_blue.bar.setZoom(characterUiZoom);
                UI.bar_blue.bar.location.x=UI.characterUI.w*360/1113;
                UI.bar_blue.bar.location.y=UI.characterUI.h*237/471;
        loadImage("Graphics\\Top Left UI\\grey_bar.png",UI.bar_grey.bar);
            UI.bar_grey.bar.setZoom(characterUiZoom);
                UI.bar_grey.bar.location.x=UI.characterUI.w*360/1113;
                UI.bar_grey.bar.location.y=UI.characterUI.h*281/471;
        loadImage("Graphics\\Top Left UI\\green_bar.png",UI.bar_green.bar);
            UI.bar_green.bar.setZoom(characterUiZoom);
                UI.bar_green.bar.location.x=UI.characterUI.w*387/1113;
                UI.bar_green.bar.location.y=UI.characterUI.h*343/471;
        loadImage("Graphics\\Top Left UI\\empty_bar.png",UI.bar_empty);
            UI.bar_empty.setZoom(characterUiZoom);
	}
	if(true){//create Inventory Interface
    int scrollBarEndingY;
    if(true){//set some values
        player.inventory.slotsInOneRow=4;
        player.inventory.rowsInInventory=player.inventory.itemStacks.size()/player.inventory.slotsInOneRow;
        if(player.inventory.itemStacks.size()%player.inventory.slotsInOneRow!=0) player.inventory.rowsInInventory++;
        player.inventory.distanceBetweenStats=(int)(player.inventory.zoom*144);
        player.inventory.closeLocation.x=(int)(player.inventory.zoom*2120);
        player.inventory.closeLocation.y=(int)(player.inventory.zoom*105);
        player.inventory.statTopLeftLocation.x=(int)(player.inventory.zoom*215);
        player.inventory.statTopLeftLocation.y=(int)(player.inventory.zoom*1516);
        player.inventory.slotLocationTopLeft.x=(int)(player.inventory.zoom*1298);
        player.inventory.slotLocationTopLeft.y=(int)(player.inventory.zoom*185);
        player.inventory.distanceBetweenSlots=(int)(player.inventory.zoom*267);
        player.inventory.distanceBetweenEquipmentSlots=(int)(player.inventory.zoom*264);
        player.inventory.equipmentTopLeftLocation.x=(int)(player.inventory.zoom*297);
        player.inventory.equipmentTopLeftLocation.y=(int)(player.inventory.zoom*181);
        scrollBarEndingY=(int)(player.inventory.zoom*2251);
	}
	if(true){//load images
		std::string prePath = "Graphics\\equipment ui slice\\", endingPath = ".png", text; layer* layeRef; Texolder& txl = player.inventory.txl;
		for(int i=0; i<player.inventory.equipmentCount; i++){
            loadImage(prePath+player.inventory.equipmentAll[i]->typeName+endingPath,player.inventory.equipmentAll[i]->image);
                player.inventory.equipmentAll[i]->image.setZoom(player.inventory.zoom);
		}
		for(int i=0; i<5; i++){
            switch(i){
                case 0: layeRef=&player.inventory.imageScrollBar;        text="scroll_bubble";          break;
                case 1: layeRef=&player.inventory.imageScrollBubble;     text="scroll_bar";             break;
                case 2: layeRef=&player.inventory.imageInventorySlot[0]; text="inventory_slot";         break;
                case 3: layeRef=&player.inventory.imageInventorySlot[1]; text="inventory_slot_pressed"; break;
                case 4: layeRef=&player.inventory.imageMain;             text="main_body";              break;
            }
            loadImage(prePath+text+endingPath,*layeRef);
               layeRef->setZoom(player.inventory.zoom);
		}
		for(int i=0; i<(int)player.stats.size(); i++){
            loadImage(prePath+"abilities\\"+toString(i+1)+endingPath,player.stats[i].image);
                player.stats[i].image.setZoom(player.inventory.zoom);
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
            float zoomMulti=2.5f;
            if(type==0){
                loadImage(prePath+"bars\\"+color+" gradient"+endingPath,bar.gradient);
                    bar.gradient.setZoom(player.inventory.zoom*zoomMulti);
                bar.gradient.textureOpenGL=convertSurfaceToOpenGLTexture(bar.gradient.surface);
            }
            loadImage(prePath+"bars\\"+color+" left"+endingPath,bar.left);
            loadImage(prePath+"bars\\"+color+" mid"+endingPath,bar.mid);
            loadImage(prePath+"bars\\"+color+" right"+endingPath,bar.right);
            createSurface(&bar.full.surface,bar.left.surface->w+bar.right.surface->w+444,bar.mid.surface->h);
            copySurface(bar.left.surface,bar.full.surface,bar.left.surface->clip_rect);
            copySurface(bar.right.surface,bar.full.surface,bar.right.surface->clip_rect,bar.full.surface->w-bar.right.surface->w,0);
            for(int o=0; o<bar.full.surface->w-bar.left.surface->w-bar.right.surface->w; o++) copySurface(bar.mid.surface,bar.full.surface,bar.mid.surface->clip_rect,bar.left.surface->w+o,0);
            bar.full.textureOpenGL=convertSurfaceToOpenGLTexture(bar.full.surface);
            bar.full.setHeightZoom(player.inventory.zoom*zoomMulti);
            bar.full.setWidthZoom(player.inventory.zoom);
            if(i!=0) player.inventory.statsBar.push_back(bar);
            else player.inventory.additionBar=bar;
		}
		if(true){//create Texolder stuff
		txl.addLayer("base"); txl.addLayer("slots"); txl.addLayer("items"); txl.addLayer("stats");
		txl.addTexture(&player.inventory.imageMain, txl.findLayer("base"), "base", player.inventory.imageMain.from, player.inventory.imageMain.to);
		player.inventory.imageMain.from = player.inventory.imageMain.surface->clip_rect;
		player.inventory.imageMain.to = getRect(player.inventory.location.x, player.inventory.location.y, player.inventory.imageMain.surface->w, player.inventory.imageMain.surface->h);
		std::string relative;
        for(int i=0; i<(int)player.inventory.itemStacks.size(); i++){
            space::is& itemStackRef=player.inventory.itemStacks[i];
            itemStackRef.location.to=getRect(0,0,player.inventory.imageInventorySlot[0].surface->w,player.inventory.imageInventorySlot[0].surface->h);
            if(i==0){
                itemStackRef.location.to.x=player.inventory.slotLocationTopLeft.x;
                itemStackRef.location.to.y=player.inventory.slotLocationTopLeft.y;
                relative="base";
            }
            else if(i%player.inventory.slotsInOneRow==0){
                itemStackRef.location.to.y=player.inventory.distanceBetweenSlots;
                relative="slot "+toString(i-player.inventory.slotsInOneRow);
            }
            else{
                itemStackRef.location.to.x=player.inventory.distanceBetweenSlots;
                relative="slot "+toString(i-1);
            }
            txl.addTexture(&player.inventory.imageInventorySlot[0],txl.findLayer("items"),"slot "+toString(i),itemStackRef.location.from,itemStackRef.location.to,relative);
            itemStackRef.location.from=player.inventory.imageInventorySlot[0].surface->clip_rect;
        }
		for (int i = 0; i<player.inventory.equipmentCount; i++){
            txl.addTexture(&player.inventory.equipmentAll[i]->image,txl.findLayer("slots"),player.inventory.equipmentAll[i]->typeName,player.inventory.equipmentAll[i]->image.from,player.inventory.equipmentAll[i]->image.to,"base");
            player.inventory.equipmentAll[i]->image.from=player.inventory.equipmentAll[i]->image.surface->clip_rect;
            player.inventory.equipmentAll[i]->image.to=getRect(player.inventory.equipmentTopLeftLocation.x+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->x,player.inventory.equipmentTopLeftLocation.y+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->y,player.inventory.equipmentAll[i]->image.surface->w,player.inventory.equipmentAll[i]->image.surface->h);
        }
		for (int i = 0; i<(int)player.stats.size(); i++){
            character::stat& ps=player.stats[i]; int id=player.stats[i].levelBase/100+1; characterSpace::bars& pi=player.inventory.statsBar[id]; characterSpace::bars& pib=player.inventory.statsBar[id-1];
            if(i==0) txl.addTexture(&ps.image,txl.findLayer("stats"),ps.statName+" image",ps.image.from,ps.image.to,"base");
            else txl.addTexture(&ps.image,txl.findLayer("stats"),ps.statName+" image",ps.image.from,ps.image.to,player.stats[i-1].statName+" image");
            txl.addTexture(&ps.statNameLayer,txl.findLayer("stats"),ps.statName+" name",ps.statNameLayer.from,ps.statNameLayer.to,ps.statName+" image");
            txl.addTexture(&ps.levelBaseLayer,txl.findLayer("stats"),ps.statName+" level count",ps.levelBaseLayer.from,ps.levelBaseLayer.to,ps.statName+" name");
            txl.addTexture(&pi.full,txl.findLayer("stats"),ps.statName+" bar main",ps.mainBar.from,ps.mainBar.to,ps.statName+" level count");
            txl.addTexture(&player.inventory.additionBar.full,txl.findLayer("stats"),ps.statName+" bar addition",ps.additionBar.from,ps.additionBar.to,ps.statName+" bar main");
            txl.addTexture(&ps.levelAdditionLayer,txl.findLayer("stats"),ps.statName+" addition count",ps.levelAdditionLayer.from,ps.levelAdditionLayer.to,ps.statName+" level count");
            txl.addTexture(&pi.gradient,txl.findLayer("stats"),ps.statName+" bar gradient",ps.gradientBar.from,ps.gradientBar.to,ps.statName+" bar addition");
            txl.addTexture(&pib.full,txl.findLayer("stats"),ps.statName+" bar background",ps.backgroundBar.from,ps.backgroundBar.to,ps.statName+" bar addition");
            ps.gradientBar.from=pi.gradient.surface->clip_rect;
            ps.gradientBar.to=ps.gradientBar.from;
            ps.backgroundBar.from=pib.full.surface->clip_rect;
            ps.backgroundBar.to=getRect(0,0,0,ps.backgroundBar.from.h);
            ps.additionBar.from=player.inventory.additionBar.full.surface->clip_rect;
            ps.additionBar.to=getRect(0,0,0,ps.additionBar.from.h);
            ps.image.from=ps.image.surface->clip_rect;
            if(i==0) ps.image.to=getRect(player.inventory.statTopLeftLocation.x,player.inventory.statTopLeftLocation.y,ps.image.surface->w,ps.image.surface->h);
            else ps.image.to=getRect(0,player.inventory.distanceBetweenStats,ps.image.surface->w,ps.image.surface->h);
            ps.statNameLayer.from=getRect(0,0,0,0);
            ps.statNameLayer.to=getRect(player.stats[i].image.w*1.5,0,0,0);
            ps.levelBaseLayer.from=getRect(0,0,0,0);
            ps.levelBaseLayer.to=getRect(player.stats[i].image.w*8,0,0,0);
            ps.mainBar.from=pi.full.surface->clip_rect;
            ps.mainBar.to=getRect(0,0,0,pi.full.surface->h);
        }
		txl.sortTextures();
        }
	}
	if(true){//calculate stuff
            createSurface(&player.inventory.imageScrollBubbleFull.surface,player.inventory.imageScrollBubble.surface->w,(scrollBarEndingY-player.inventory.slotLocationTopLeft.y));
            for(int i=0; i<player.inventory.imageScrollBubbleFull.surface->h; i++) copySurface(player.inventory.imageScrollBubble.surface,player.inventory.imageScrollBubbleFull.surface,player.inventory.imageScrollBubble.surface->clip_rect,0,i);
            player.inventory.imageScrollBubbleFull.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.imageScrollBubbleFull.surface);
            player.inventory.imageScrollBubbleFull.setWidthZoom(player.inventory.zoom);
            int temp=8; int temp2;
            if(player.inventory.rowsInInventory<=temp){
                temp=player.inventory.rowsInInventory;
                temp2=player.inventory.imageScrollBubbleFull.surface->h-1;
                sliderSpeed=0;
            }
            else{
                temp2=player.inventory.imageScrollBubbleFull.surface->h/(player.inventory.rowsInInventory-temp+1);
                sliderSpeed=(player.inventory.imageScrollBubbleFull.surface->h-temp2)/(player.inventory.rowsInInventory-temp)/sliderCountForOneRow;
            }
            createSurface(&player.inventory.imageScrollBarFull.surface,player.inventory.imageScrollBar.surface->w,temp2);
            for(int i=0; i<player.inventory.imageScrollBarFull.surface->h; i++) copySurface(player.inventory.imageScrollBar.surface,player.inventory.imageScrollBarFull.surface,player.inventory.imageScrollBar.surface->clip_rect,0,i);
            player.inventory.imageScrollBarFull.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.imageScrollBarFull.surface);
            player.inventory.imageScrollBarFull.setWidthZoom(player.inventory.zoom);
            player.inventory.furthestPossibleSliderLocation=player.inventory.imageScrollBubbleFull.surface->h-player.inventory.imageScrollBarFull.surface->h;
            for(int i=0; i<player.inventory.slotsInOneRow; i++) player.inventory.slotsLocationsX.push_back((player.inventory.slotLocationTopLeft.x+player.inventory.distanceBetweenSlots*i));
            player.inventory.slotLocationBottomY=player.inventory.slotLocationTopLeft.y+7*player.inventory.distanceBetweenSlots+player.inventory.imageInventorySlot[0].w;
            player.inventory.ratioBetweenBarAndSlots=(float)((player.inventory.rowsInInventory-temp)*player.inventory.distanceBetweenSlots)/(float)player.inventory.furthestPossibleSliderLocation;
        }
	}
	if(true){//create Bot UI
        UI.botUIButtonsTopLeftLocation.x=73*characterUiZoom;
        UI.botUIButtonsTopLeftLocation.y=143*characterUiZoom;
        UI.botUIDistanceBetweenButtons=202*characterUiZoom;
        loadImage("Graphics\\Bot UI\\bot_ui_frame.png",UI.botUI);
            UI.botUI.setZoom(characterUiZoom);
        UI.botUItxl.addLayer("base"); UI.botUItxl.addLayer("icons");
        UI.botUI.from=UI.botUI.surface->clip_rect;
        UI.botUI.to=getRect((SCREEN_WIDTH-UI.botUI.w)/2,SCREEN_HEIGHT-UI.botUI.h,UI.botUI.surface->w,UI.botUI.surface->h);
        UI.botUItxl.addTexture(&UI.botUI,UI.botUItxl.findLayer("base"),"base",UI.botUI.from,UI.botUI.to);
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
            UI.botUIButtons[i].state[0].from=UI.botUIButtons[i].state[0].surface->clip_rect;
            UI.botUIButtons[i].state[0].to=getRect(UI.botUIButtonsTopLeftLocation.x+i*UI.botUIDistanceBetweenButtons,
                                                   UI.botUIButtonsTopLeftLocation.y,
                                                   UI.botUIButtons[i].state[0].surface->w,
                                                   UI.botUIButtons[i].state[0].surface->h);
            UI.botUItxl.addTexture(&UI.botUIButtons[i].state[0],
                                   UI.botUItxl.findLayer("icons"),
                                   UIBotUIName,
                                   UI.botUIButtons[i].state[0].from,
                                   UI.botUIButtons[i].state[0].to
                                   ,"base"
                                   );
            loadImage("Graphics\\Bot UI\\icons\\"+UIBotUIName+" pressed.png",UI.botUIButtons[i].state[1]);
                UI.botUIButtons[i].state[1].setZoom(characterUiZoom);
        }

	}
	if(true){//create Top UI
            loadImage("Graphics\\top menu buttons\\reflection below.png",UI.topUIReflection);
                UI.topUIReflection.setZoom(characterUiZoom);
            std::string UITopUIName;
            for(int i=0; i<3; i++){
                switch(i){
                    case 0: UITopUIName="shop";     break;
                    case 1: UITopUIName="settings"; break;
                    case 2: UITopUIName="exit";     break;
                }
                loadImage("Graphics\\top menu buttons\\"+UITopUIName+" idle.png",UI.topUIButtons[i].state[0]);
                    UI.topUIButtons[i].state[0].setZoom(characterUiZoom);
                loadImage("Graphics\\top menu buttons\\"+UITopUIName+" click.png",UI.topUIButtons[i].state[1]);
                    UI.topUIButtons[i].state[1].setZoom(characterUiZoom);
            }
            UI.topUIDistanceBetweenButtons[0]=0*characterUiZoom;
            UI.topUIDistanceBetweenButtons[1]=177*characterUiZoom;
            UI.topUIDistanceBetweenButtons[2]=214*characterUiZoom+UI.topUIDistanceBetweenButtons[1];
            UI.topUIButtonsTopLeftLocation.x=SCREEN_WIDTH-UI.topUIDistanceBetweenButtons[2]-UI.topUIButtons[0].state[0].w;
            UI.topUIButtonsTopLeftLocation.y=0;
        }
	}
	if(true){//create items
        addItem("Poop","ingredient","qpm\\item_poop.png");
        addItem("Berry",player.inventory.equipmentHandRight.typeName,"qpm\\item_berry.png");
        addItem("RegularSword",player.inventory.equipmentHandRight.typeName,"qpm\\regularSword.png"); items[items.size()-1].damage=5; affectStat("Strength",5); affectStat("Health",25);
	}
	if(true){//load Fonts
        //-------------------------------------------------------------------------------------
        font=TTF_OpenFont("ttf\\DroidSerif.ttf",fontSize);
        TTF_SetFontStyle(font,TTF_STYLE_BOLD);
        //-------------------------------------------------------------------------------------
        font_calibriSize*=characterUiZoom;
        font_calibri=TTF_OpenFont("ttf\\Calibri.ttf",font_calibriSize);
        TTF_SetFontStyle(font_calibri,TTF_STYLE_BOLD);
        //-------------------------------------------------------------------------------------
        font_lithosProSize*=characterUiZoom;
        font_lithosPro=TTF_OpenFont("ttf\\LithosPro.otf",font_lithosProSize);
        TTF_SetFontStyle(font_lithosPro,TTF_STYLE_BOLD);
        //-------------------------------------------------------------------------------------
        font_lithosProForLevel=TTF_OpenFont("ttf\\LithosPro.otf",font_lithosProForLevelSize);
        TTF_SetFontStyle(font_lithosProForLevel,TTF_STYLE_BOLD);
        //-------------------------------------------------------------------------------------
	}
	if(true){//load messages
        RenderType=RENDER_NEAREST;
        player.inventory.closeButton.surface=TTF_RenderText_Blended(font_lithosPro,"close X",messageColor);
        player.inventory.closeButton.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.closeButton.surface);
        messageSlash.surface=TTF_RenderText_Blended(font_calibri,"/",messageColor);
        messageSlash.textureOpenGL=convertSurfaceToOpenGLTexture(messageSlash.surface);
        RenderType=RENDER_MIPMAP;
	}
	if(true){//create maps
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
	}
	if(true){//create battle zones
        int mapId;
        createBattleZone("The third map", "Pyramids_So_Real",
                         0,0,   0,0,   320,500,   0,0,   0,0,
                         786,533,  797,675,  933,597,  1095,558,  1086,666
                         //393,419,   431,456,   315,387,   387,483,   360,519
                         ); mapId=maps.size()-1;
        createLayer(mapId,"qpm\\pyramids_secret.png");
        createLayer(mapId,"qpm\\bc3.png");
        createLayer(mapId,"qpm\\pyramids_transparent.png");
	}
	if(true){//create menu
        std::string pathStart="Graphics\\menu slices\\",pathEnd=".png",path; layer *layerr; variables::buttn* buttonp;
        for(int i=0; i<8; i++){
            switch(i){
                case 0: path="close"; buttonp=&menu.close; break;
                case 1: path="play"; buttonp=&menu.play; break;
                case 2: path="options"; buttonp=&menu.options; break;
                case 3: path="about"; buttonp=&menu.about; break;
                case 4: path="background"; layerr=&menu.background; break;
                case 5: path="logo"; layerr=&menu.logo; break;
                case 6: path="top_gradient"; layerr=&menu.gradient; break;
                case 7: path="flame"; layerr=&menu.flameParticle; break;
            }
            if(i<4){
                loadImage(pathStart+path+"_idle"+pathEnd,buttonp->button[0]);
                loadImage(pathStart+path+"_press"+pathEnd,buttonp->button[1]);
            }
            else loadImage(pathStart+path+pathEnd,*layerr);
        }
        menuTxl.addLayer("base"); menuTxl.addLayer("other"); menuTxl.addLayer("logo"); menuTxl.addLayer("buttons");
        menuTxl.addTexture(&menu.background,menuTxl.findLayer("base"),"background",menu.background.from,menu.background.to);
        menuTxl.addTexture(&menu.logo,menuTxl.findLayer("logo"),"logo",menu.logo.from,menu.logo.to,"background");
        menuTxl.addTexture(&menu.close.button[0],menuTxl.findLayer("buttons"),"button close",menu.close.button[0].from,menu.close.button[0].to,"background");
        menuTxl.addTexture(&menu.play.button[0],menuTxl.findLayer("buttons"),"button play",menu.play.button[0].from,menu.play.button[0].to,"logo");
        menuTxl.addTexture(&menu.options.button[0],menuTxl.findLayer("buttons"),"button options",menu.options.button[0].from,menu.options.button[0].to,"button play");
        menuTxl.addTexture(&menu.about.button[0],menuTxl.findLayer("buttons"),"button about",menu.about.button[0].from,menu.about.button[0].to,"button options");
        menuTxl.addTexture(&menu.gradient,menuTxl.findLayer("other"),"gradient",menu.gradient.from,menu.gradient.to,"background");
        menu.background.from=getRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        menu.background.to=getRect(0,0,menu.background.from.w,menu.background.from.h);
        menu.gradient.from=menu.gradient.surface->clip_rect;
        menu.gradient.to=getRect(0,0,menu.gradient.from.w,menu.gradient.from.h);
        menu.logo.from=menu.logo.surface->clip_rect;
        menu.logo.to=getRect((SCREEN_WIDTH-menu.logo.from.w)/2,(SCREEN_HEIGHT-menu.logo.from.h)/2,menu.logo.w,menu.logo.h);
        menu.close.button[0].from=menu.close.button[0].surface->clip_rect;
        menu.close.button[0].to=getRect(SCREEN_WIDTH-menu.close.button[0].from.w,0,menu.close.button[0].from.w,menu.close.button[0].from.h);
        menu.play.button[0].from=menu.play.button[0].surface->clip_rect;
        menu.play.button[0].to=getRect((menu.logo.surface->w-menu.play.button[0].surface->w)/2,menu.logo.surface->h-50,menu.play.button[0].from.w,menu.play.button[0].from.h);
        menu.options.button[0].from=menu.options.button[0].surface->clip_rect;
        menu.options.button[0].to=getRect((menu.play.button[0].surface->w-menu.options.button[0].surface->w)/2,menu.play.button[0].surface->h+10,menu.options.button[0].from.w,menu.options.button[0].from.h);
        menu.about.button[0].from=menu.about.button[0].surface->clip_rect;
        menu.about.button[0].to=getRect((menu.options.button[0].surface->w-menu.about.button[0].surface->w)/2,menu.options.button[0].surface->h+10,menu.about.button[0].from.w,menu.about.button[0].from.h);
	}
	}
    else{
        loadImage("qpm\\poop_full.png",imageOpenGL);
        loadImage("qpm\\base.png",imageOpenGL2);
	}
}

void functions::spawnFlameParticle(){
    fl newFlame;
    newFlame.startPoint=getPoint(rand()%menu.flameStartLine.width+menu.flameStartLine.from,SCREEN_HEIGHT);
    newFlame.endPoint=getPoint(rand()%menu.flameEndLine.width+menu.flameEndLine.from,newFlame.endPoint.y=-rand()%SCREEN_HEIGHT*4/5+SCREEN_HEIGHT*3/5);
    if(rand()%2){
        newFlame.startPoint.x+=SCREEN_WIDTH*2/3;
        newFlame.endPoint.x+=SCREEN_WIDTH*3/8;
    }
    newFlame.lifetime=rand()%menu.flameLifeTime.width+menu.flameLifeTime.from;
    newFlame.creationTimeStamp=timeStamp;
    newFlame.oscillationInitialAmplitude=rand()%20+90;
    newFlame.oscillationEndingAmplitude=rand()%7+3;
    newFlame.oscillationSpeed=rand()%30+20;
    newFlame.direction=rand()%2;
    newFlame.initialSize=4.f/5.f;
    newFlame.endingSize=1.f/5.f;
    menu.flames.push_back(newFlame);
}
void functions::renderFlameParticles(){
    if(rand()%(menu.chanceToCreateFlameEachFrame)==0) spawnFlameParticle();
    //for(int i=0; i<10; i++) spawnFlameParticle();
    for(int i=0; i<(int)menu.flames.size(); i++){
        fl &flame=menu.flames[i];
        flame.delta=(float)(timeStamp-flame.creationTimeStamp)/(float)flame.lifetime;
        //flame.delta=sqrt(flame.delta);
        if(flame.delta>1||(1-sqrt(flame.delta))*7.f/8.f<0){
            menu.flames.erase(menu.flames.begin()+i,menu.flames.begin()+i+1);
            i--;
        }
        else{
            flame.location.x=flame.startPoint.x*(1-flame.delta)+flame.endPoint.x*flame.delta;
            flame.location.y=flame.startPoint.y*(1-flame.delta)+flame.endPoint.y*flame.delta;
            if(flame.direction){
                flame.location.x+=cos(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1-flame.delta)+flame.oscillationEndingAmplitude*flame.delta);
                flame.location.y+=sin(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1-flame.delta)+flame.oscillationEndingAmplitude*flame.delta);
            }
            else{
                flame.location.x+=sin(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1-flame.delta)+flame.oscillationEndingAmplitude*flame.delta);
                flame.location.y+=cos(flame.delta*flame.oscillationSpeed)*(flame.oscillationInitialAmplitude*(1-flame.delta)+flame.oscillationEndingAmplitude*flame.delta);
            }
            //int opacity=flame.delta-
            menu.flameParticle.a=(1-sqrt(flame.delta))*7.f/8.f;
            menu.flameParticle.setZoom(flame.initialSize*(1-flame.delta)+flame.endingSize*flame.delta);
            renderTexture(&menu.flameParticle,menu.flameParticle.surface->clip_rect,flame.location.x,flame.location.y);
        }
    }
}
int functions::getColorAlpha(SDL_Color color){
    return color.a;
}
map* functions::createBattleZone(std::string name, std::string id,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5,int x6,int y6,int x7,int y7,int x8,int y8,int x9,int y9,int x0,int y0){
    map &mapRef=*createMap(name,id);
    SDL_Point location;
    location.x=x1; location.y=y1; mapRef.platforms.push_back(location);
    location.x=x2; location.y=y2; mapRef.platforms.push_back(location);
    location.x=x3; location.y=y3; mapRef.platforms.push_back(location);
    location.x=x4; location.y=y4; mapRef.platforms.push_back(location);
    location.x=x5; location.y=y5; mapRef.platforms.push_back(location);
    location.x=x6; location.y=y6; mapRef.platforms.push_back(location);
    location.x=x7; location.y=y7; mapRef.platforms.push_back(location);
    location.x=x8; location.y=y8; mapRef.platforms.push_back(location);
    location.x=x9; location.y=y9; mapRef.platforms.push_back(location);
    location.x=x0; location.y=y0; mapRef.platforms.push_back(location);
    return &mapRef;
}
map* functions::createMap(std::string name, std::string id){
    map map_temp;
    map_temp.name=name;
    map_temp.id=id;
    maps.push_back(map_temp);
    return &maps[maps.size()-1];
}
void functions::addGatherableReturnItemStack(int itemCount,item containingItem,gather &gatherableTypeVar){
    itemStack itemStack_temp;
    itemStack_temp.itemCount=itemCount;
    itemStack_temp.containingItem=containingItem;
    gatherableTypeVar.returnItems.push_back(itemStack_temp);
}
gather* functions::createGatherable(int mapId, int gatherableLocationX, int gatherableLocationY, bool colidable, float gatherTime, int requiredLevel, std::string requiredSkillName){
    //also need to call createEvent function, addStage function, addGatherableReturnItemStack
    gather gather_temp;
    gather_temp.colidable=colidable;
    gather_temp.gatherTime=gatherTime;
    gather_temp.requiredLevel=requiredLevel;
    gather_temp.requiredSkillName=requiredSkillName;
    gather_temp.location.x=gatherableLocationX;
    gather_temp.location.y=gatherableLocationY;
    map &mapRef=maps[mapId];
    mapRef.gatherable.push_back(gather_temp);
    return &mapRef.gatherable[mapRef.gatherable.size()-1];
}
stage* functions::addStage(float timeUntilNextStage, bool isItAShortcutStage, bool isItGatherable, std::string imagePath,gather &gatherableTypeVar){
    stage stage_temp;
    if(loadImage(imagePath,stage_temp.image)==0){
        stage_temp.timeUntilNextStage=timeUntilNextStage;
        stage_temp.shortcut=isItAShortcutStage;
        stage_temp.isItGatherable=isItGatherable;
        gatherableTypeVar.stages.push_back(stage_temp);
        return &gatherableTypeVar.stages[gatherableTypeVar.stages.size()-1];
    }
    else error("The program was unable to create an interactable. [Info: "+
               toString(timeUntilNextStage)+"=timeUntilNextStage"+";\n"+
               "isItAShortcutStage="+toString(isItAShortcutStage)+";\n"+
               "imagePath="+imagePath+";\n"+
               "]");
    return NULL;
}
void functions::createZone(int mapId, std::string owner, std::string zoneName){
    zone zone_temp;
    map &mapRef=maps[mapId];
    if(mapRef.layers.size()>0) {
        zone_temp.id=getZoneId(mapRef.layers[0].surface);
        if(zone_temp.id!=-1){
            zone_temp.owner=owner;
            zone_temp.name=zoneName;
            zone_temp.color=getColor(zone_temp.id);
            mapRef.zones.push_back(zone_temp);
        }
        else error("The program was unable to create a zone. [Info: owner="+owner+"; zoneName="+zoneName+";");
    }
    else error("The program was unable to create a zone, because the map has no layers;");
}
interact* functions::createInteractable(int mapId, std::string imagePath, int interactableLocationX, int interactableLocationY, bool isInteractableColidable){
    interact interactable_temp;
    if(loadImage(imagePath,interactable_temp)==0){
        interactable_temp.colidable=isInteractableColidable;
        interactable_temp.location.x=interactableLocationX;
        interactable_temp.location.y=interactableLocationY;
        map &mapRef=maps[mapId];
        mapRef.interactable.push_back(interactable_temp);
        return &mapRef.interactable[mapRef.interactable.size()-1];
    }
    else error("The program was unable to create an interactable. [Info: imagePath="+imagePath+"; x="+toString(interactableLocationX)+"; y="+toString(interactableLocationY)+"; colidable="+toString(isInteractableColidable)+";]");
    return NULL;
}
interact* functions::createInteractable(int mapId, std::string imagePath, int interactableLocationX, int interactableLocationY, int w, int h, bool isInteractableColidable){
    interact interactable_temp;
    if(loadImage(imagePath,interactable_temp)==0){
        interactable_temp.colidable=isInteractableColidable;
        interactable_temp.location.x=interactableLocationX;
        interactable_temp.location.y=interactableLocationY;
        interactable_temp.setHeightZoom((float)h/(float)interactable_temp.surface->h);
        interactable_temp.setWidthZoom((float)w/(float)interactable_temp.surface->w);
        map &mapRef=maps[mapId];
        mapRef.interactable.push_back(interactable_temp);
        return &mapRef.interactable[mapRef.interactable.size()-1];
    }
    else error("The program was unable to create an interactable. [Info: imagePath="+imagePath+"; x="+toString(interactableLocationX)+"; y="+toString(interactableLocationY)+"; colidable="+toString(isInteractableColidable)+";]");
    return NULL;
}
void functions::createObject(int mapId, std::string imagePath, int objectLocationX, int objectLocationY, bool isObjectColidable){
    objects object_temp;
    if(loadImage(imagePath,object_temp)==0){
        object_temp.location.x=objectLocationX;
        object_temp.location.y=objectLocationY;
        object_temp.colidable=isObjectColidable;
        map &mapRef=maps[mapId];
        mapRef.object.push_back(object_temp);
    }
    else error("The program was unable to create an object. [Info: imagePath="+imagePath+"; objectLocationX="+toString(objectLocationX)+"; objectLocationY="+toString(objectLocationY)+"; isObjectColidable="+toString(isObjectColidable)+";");
}
void functions::createLayer(int mapId, std::string imagePath){
    layer layer_temp;
    if(loadImage(imagePath,layer_temp)==0){
        layer_temp.setHeightZoom((float)SCREEN_HEIGHT/(float)layer_temp.surface->h);
        layer_temp.setWidthZoom((float)SCREEN_WIDTH/(float)layer_temp.surface->w);
        map &mapRef=maps[mapId];
        mapRef.layers.push_back(layer_temp);
    }
    else error("The program was unable to create a layer. [Info: imagePath="+imagePath+";");
}
void functions::sendMessageToConsole(std::string message, int wait){
    bool test=false;
    for(int i=0; i<(int)consoleMessages.textInfo.size(); i++){
        if(consoleMessages.textInfo[i].substr(0,message.size())==message){
            int temp=atoi(consoleMessages.textInfo[i].substr(message.size()+2,consoleMessages.textInfo[i].size()-message.size()).c_str())+1;
            consoleMessages.textInfo[i]=consoleMessages.textInfo[i].substr(0,message.size());
            consoleMessages.textInfo[i]+=" x"+toString(temp);
            test=true;
            consoleMessages.update=true;
            i=consoleMessages.textInfo.size();
        }
    }
    if(!test){
        consoleMessages.textInfo.push_back(message+" x1");
        if(consoleMessages.textInfo.size()>12) consoleMessages.textInfo.erase(consoleMessages.textInfo.begin(),consoleMessages.textInfo.begin()+1);
        consoleMessages.update=true;
    }
    console();
    SDL_Delay(wait);
}
void functions::console(){
    if(consoleShow){
        SDL_RenderClear(consoleRenderer);
        if(frame==FPS){
            consoleVariables.update=true;
            std::string temp;
            consoleVariables.textInfo.clear();
            temp="Player location: ["+toString(player.location.x)+";"+toString(player.location.y)+"]"; consoleVariables.textInfo.push_back(temp);
            temp="Double click timer: ["+toString(player.inventory.doubleClick)+"]"; consoleVariables.textInfo.push_back(temp);
        }
        int width,height;
        consoleMsg* consoleMsgP;
        for(int i=0; i<2; i++){
            switch(i){
            case 0:
                consoleMsgP=&consoleVariables;
                consoleRect=getRect(0,0,consoleMsgP->surface->w,consoleMsgP->surface->h);
                width=CONSOLE_SCREEN_WIDTH/2; height=CONSOLE_SCREEN_HEIGHT/2;
            break;
            case 1:
                consoleMsgP=&consoleMessages;
                consoleRect=getRect(0,consoleMsgP->surface->h,consoleMsgP->surface->w,consoleMsgP->surface->h);
                width=CONSOLE_SCREEN_WIDTH; height=CONSOLE_SCREEN_HEIGHT/2;
            break;
            }
            if(consoleMsgP->update){
                consoleMsgP->update=false;
                SDL_FreeSurface(consoleMsgP->surface); consoleMsgP->surface=NULL;
                createSurface(&consoleMsgP->surface,width,height);
                for(int o=0; o<(int)consoleMsgP->textInfo.size(); o++){
                    consoleSurface=TTF_RenderText_Blended(font,(consoleMsgP->textInfo[o]).c_str(),messageColor);
                    switch(i){
                        case 0: copySurface(consoleSurface,consoleMsgP->surface,consoleSurface->clip_rect,0,consoleSurface->h*o); break;
                        case 1: copySurface(consoleSurface,consoleMsgP->surface,consoleSurface->clip_rect,0,consoleMsgP->surface->h-consoleSurface->h*(consoleMsgP->textInfo.size()-o)); break;
                    }
                    SDL_FreeSurface(consoleSurface); consoleSurface=NULL;
                }
                SDL_DestroyTexture(consoleMsgP->texture); consoleMsgP->texture=NULL;
                consoleMsgP->texture=SDL_CreateTextureFromSurface(consoleRenderer,consoleMsgP->surface);
            }
            SDL_RenderCopy(consoleRenderer,consoleMsgP->texture,NULL,&consoleRect);
        }
        SDL_RenderPresent(consoleRenderer);
    }
    else{
        if(consoleOnce[0]){
            SDL_RenderClear(consoleRenderer);
            SDL_RenderPresent(consoleRenderer);
            consoleOnce[0]=false;
        }
    }
}
GLuint functions::convertSurfaceToOpenGLTexture(SDL_Surface* surface){
    GLuint texture;
    GLenum texture_format;
	GLint nOfColors = surface->format->BytesPerPixel;

	if (nOfColors == 4){
        if (surface->format->Rmask == 0x000000ff) texture_format=GL_RGBA;
        else texture_format=GL_BGRA;
    }
	else if (nOfColors == 3){
        if(surface->format->Rmask==0x000000ff) texture_format=GL_RGB;
        else texture_format=GL_BGR;
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
void functions::reset(){
    timeStamp++;
    frame++; if(frame>FPS) frame%=FPS;
    if(player.inventory.doubleClick>-1){
        player.inventory.doubleClick++;
        if(player.inventory.doubleClick>=FPS){
            player.inventory.doubleClick=-1;
        }
    }
    if(currentMenu==MENU_GAME) player.reset();
    if(mouseButton==2)    mouseButton       =false;
    else if(mouseButton)  mouseButton       =false;
    if(leftMouseButton)   leftMouseButton   =false;
    if(rightMouseButton)  rightMouseButton  =false;
    if(leftMouseButtonUp) leftMouseButtonUp =false;
    if(rightMouseButtonUp)rightMouseButtonUp=false;
    if(mouseWheelMotion!=false)mouseWheelMotion=false; //Reset mouse wheel motion
}
void functions::affectStats(item* itemOfWhichEffectsToUse, bool trueForGivingStats_falseForRemovingStats){
    int multi=1; if(!trueForGivingStats_falseForRemovingStats) multi=-1;
    for(int i=0; i<(int)itemOfWhichEffectsToUse->affectedStats.size(); i++){//go through all the effects for stats in that item
        for(int o=0; o<(int)player.stats.size(); o++){//go through all the existing stats to see if this effect is for that specific stat
            if(player.stats[o].statName==itemOfWhichEffectsToUse->affectedStats[i].statName){ //check if the effected stat and the checked stat are the same
                player.stats[o].updateAddition=true;
                player.addStatAddition(itemOfWhichEffectsToUse->affectedStats[i].ammount*multi,player.stats[o].statName);//if so then add the effected stat amount to the addition variable that let's the program know by how much the stat is increased from it's base value
                o=player.stats.size();
            }
        }
    }
}
void functions::unequipItem(int equipmentId){
    giveItems(player.inventory.equipmentAll[equipmentId]->item);//copy the item from your equipment slot to you inventory
    affectStats(&player.inventory.equipmentAll[equipmentId]->item.containingItem,false);//remove the stat effects that were given by this item
    player.inventory.equipmentAll[equipmentId]->item.reset();//remove the item from your equipment slot
}
void functions::equipItem(int itemSlotId){
    for(int i=0; i<player.inventory.equipmentCount; i++){//find in which equipment slot this item should be put
        if(player.inventory.itemStacks[itemSlotId].ist.containingItem.type==player.inventory.equipmentAll[i]->typeName){//see if this equipment slot is the one to be used
            if(player.inventory.equipmentAll[i]->item.itemCount!=0){//if there is already an item equipped there
                unequipItem(i);//take off that item
            }
			player.inventory.equipmentAll[i]->item.containingItem = player.inventory.itemStacks[itemSlotId].ist.containingItem;//copy the item from players' inventory to the equipment slot
            player.inventory.equipmentAll[i]->item.itemCount=1;//make sure that there is only one item in the equipment slot
            removeItem(itemSlotId,1);//remove the item from the inventory
            affectStats(&player.inventory.equipmentAll[i]->item.containingItem,true);
            i=player.inventory.equipmentCount;//end the search
        }
    }
}
void functions::removeItem(int slotId, int ammount){
	player.inventory.itemStacks[slotId].ist.itemCount -= ammount;
	if (player.inventory.itemStacks[slotId].ist.itemCount <= 0){
        for(int i=slotId+1; i<(int)player.inventory.itemStacks.size(); i++){
            player.inventory.itemStacks[i-1]=player.inventory.itemStacks[i];
        }
    }
    player.inventory.update=true;
}
void functions::affectStat(std::string statName, float ammount){
    item::affect affectedStat;
    affectedStat.statName=statName; affectedStat.ammount=ammount;
    items[items.size()-1].affectedStats.push_back(affectedStat);
}
void functions::createSurface(SDL_Surface** surfaceDestination, int width, int height){
    *surfaceDestination=SDL_CreateRGBSurface(0,
                       width,
                       height,
                       32,
                       0x000000ff,
                       0x0000ff00,
                       0x00ff0000,
                       0xff000000);
}
SDL_Surface* functions::createSurface(int width, int height){
    SDL_Surface* returnValue=NULL;
    createSurface(&returnValue,width,height);
    return returnValue;
}
void functions::renderUI(){
    renderInventory(true);//manage inventory clicks
    if(true){//render Bot UI
        for(int i=0; i<4; i++){
            if(leftMouseButton==1||leftMouseButtonUp==1){
                Texolder::TH &n=UI.botUItxl.texture[UI.botUItxl.findTexture(*(UI.botUItxl.findLayer("icons")))+i];
                if(pointInsideRect(mouse,getRect(UI.botUItxl.getLocationX(n),UI.botUItxl.getLocationY(n),n.layerp->w,n.layerp->h))){
                    if(leftMouseButton==1) {
                        clickedOn="botUIButton_"+toString(i);
                        leftMouseButton=0;
                        n.layerp=&UI.botUIButtons[i].state[1];
                    }
                    else{
                        if(clickedOn==("botUIButton_"+toString(i))){
                            switch(i){
                                case 0:
                                    player.inventory.open=!player.inventory.open; // open/close inventory
                                break;
                                case 1:
                                    error("open stats menu [needs to be created first]");
                                break;
                                case 2:
                                    error("open skills menu [needs to be created first]");
                                break;
                                case 3:
                                    error("open quests menu [needs to be created first]");
                                break;
                            }
                            n.layerp=&UI.botUIButtons[i].state[0];
                            leftMouseButtonUp=0;
                            clickedOn="";
                        }
                    }
                }
                else{
                    if(leftMouseButtonUp==1&&clickedOn==("botUIButton_"+toString(i))){
                        n.layerp=&UI.botUIButtons[i].state[0];
                        clickedOn="";
                    }
                }
            }
        }
        UI.botUItxl.renderTextures();
    }
    if(true){//render Character UI
    renderTexture(&UI.characterUI,UI.characterUI.surface->clip_rect);
    for(int i=0; i<3; i++){//render health/mana/experience bars
        if(*UI.all[i]->update){
            RenderType=RENDER_NEAREST;
            UI.all[i]->message.freeSurface();
            UI.all[i]->message.surface=TTF_RenderText_Blended(font_calibri,toString(*UI.all[i]->countAmount).c_str(),messageColor);
            UI.all[i]->message.freeTexture();
            UI.all[i]->message.textureOpenGL=convertSurfaceToOpenGLTexture(UI.all[i]->message.surface);
            UI.all[i]->max_count.freeSurface();
            UI.all[i]->max_count.surface=TTF_RenderText_Blended(font_calibri,toString(*UI.all[i]->max_countAmount).c_str(),messageColor);
            UI.all[i]->max_count.freeTexture();
            UI.all[i]->max_count.textureOpenGL=convertSurfaceToOpenGLTexture(UI.all[i]->max_count.surface);
            RenderType=RENDER_MIPMAP;
        }
        renderTexture(&UI.bar_empty,UI.bar_empty.surface->clip_rect,UI.all[i]->bar.location.x,UI.all[i]->bar.location.y);//render empty
        renderTexture(&UI.all[i]->bar,0,0,UI.all[i]->bar.surface->w*(*UI.all[i]->countAmount)/(*UI.all[i]->max_countAmount),UI.all[i]->bar.surface->h,UI.all[i]->bar.location.x,UI.all[i]->bar.location.y);//render full
        renderTexture(&messageSlash,messageSlash.surface->clip_rect,UI.all[i]->bar.location.x+(UI.bar_empty.w-messageSlash.surface->w)/2,UI.all[i]->bar.location.y+(UI.bar_empty.h-messageSlash.surface->h)/2);//render slash
        renderTexture(&UI.all[i]->max_count,UI.all[i]->max_count.surface->clip_rect,UI.all[i]->bar.location.x+(UI.bar_empty.w+messageSlash.surface->w)/2,UI.all[i]->bar.location.y+(UI.bar_empty.h-messageSlash.surface->h)/2);//render max
        renderTexture(&UI.all[i]->message,UI.all[i]->message.surface->clip_rect,UI.all[i]->bar.location.x+(UI.bar_empty.w-messageSlash.surface->w)/2-UI.all[i]->message.surface->w,UI.all[i]->bar.location.y+(UI.bar_empty.h-messageSlash.surface->h)/2);//render current
    }
    if(true){//render class/rank tablet
        if(*UI.bar_green.update){
            UI.bar_green.message.free();
            std::string name=" "; name+=player.type; name+=" ";
            UI.bar_green.message.surface=TTF_RenderText_Blended(font_lithosPro,name.c_str(),messageColor);
            RenderType=RENDER_NEAREST;
            UI.bar_green.message.textureOpenGL=convertSurfaceToOpenGLTexture(UI.bar_green.message.surface);
            RenderType=RENDER_MIPMAP;
        }
        renderTexture(&UI.bar_green.bar,0,0,UI.bar_green.message.surface->w/characterUiZoom,UI.bar_green.bar.surface->h,UI.bar_green.bar.location.x,UI.bar_green.bar.location.y);
        renderTexture(&UI.bar_green.message,UI.bar_green.message.surface->clip_rect,UI.bar_green.bar.location.x,UI.bar_green.bar.location.y+(UI.bar_green.bar.h-UI.bar_green.message.surface->h+12*characterUiZoom)/2);
    }
    if(true){//render player Level
        if(*UI.level.update){
            UI.level.message.free();
            UI.level.message.surface=TTF_RenderText_Blended(font_lithosProForLevel,toString(*UI.level.countAmount).c_str(),levelColor);
            while((UI.level.message.surface->h>84*UI.characterUI.h/(float)1113)||(UI.level.message.surface->w>84*UI.characterUI.w/(float)1113)){
                font_lithosProForLevelSize-=0.1;
                font_lithosProForLevel=TTF_OpenFont("ttf\\LithosPro.otf",font_lithosProForLevelSize);
                TTF_SetFontStyle(font_lithosProForLevel,TTF_STYLE_BOLD);
                UI.level.message.freeSurface();
                UI.level.message.surface=TTF_RenderText_Blended(font_lithosProForLevel,toString(*UI.level.countAmount).c_str(),levelColor);
            }
            RenderType=RENDER_NEAREST;
            UI.level.message.textureOpenGL=convertSurfaceToOpenGLTexture(UI.level.message.surface);
            RenderType=RENDER_MIPMAP;
        }
        renderTexture(&UI.level.message,UI.level.message.surface->clip_rect,(UI.characterUI.w*(float)318/(float)1113)-UI.level.message.surface->w/2,(UI.characterUI.w*(float)360/(float)1113)-UI.level.message.surface->h/2);
    }
    }
    if(true){//render Top UI
        layer* currentLayer;
        renderTexture(&UI.topUIReflection,
                      UI.topUIReflection.surface->clip_rect,
                      UI.topUIButtonsTopLeftLocation.x,
                      UI.topUIButtonsTopLeftLocation.y+UI.topUIButtons[0].state[0].h+5*characterUiZoom);
        for(int i=0; i<3; i++){
            currentLayer=&UI.topUIButtons[i].state[UI.topUIButtons[i].currentState];
            renderTexture(currentLayer,currentLayer->surface->clip_rect,
                          UI.topUIButtonsTopLeftLocation.x+UI.topUIDistanceBetweenButtons[i],
                          UI.topUIButtonsTopLeftLocation.y);
        }
        for(int i=2; i>=0; i--){
            if(leftMouseButton||leftMouseButtonUp){
                if(pointInsideRect(mouse,getRect(UI.topUIButtonsTopLeftLocation.x+UI.topUIDistanceBetweenButtons[i],UI.topUIButtonsTopLeftLocation.y,UI.topUIButtons[i].state[UI.topUIButtons[i].currentState].w,UI.topUIButtons[i].state[UI.topUIButtons[i].currentState].h))){
                    SDL_Color currentColor=getPixelColors(UI.topUIButtons[i].state[UI.topUIButtons[i].currentState].surface,(mouse.x-(UI.topUIButtonsTopLeftLocation.x+UI.topUIDistanceBetweenButtons[i]))/characterUiZoom,(mouse.y-UI.topUIButtonsTopLeftLocation.y)/characterUiZoom);
                    if(currentColor.a!=0){
                        if(leftMouseButton){
                            clickedOn="topUIButton_"+toString(i);
                            UI.topUIButtons[i].currentState=true;
                            leftMouseButton=false;
                        }
                        if(leftMouseButtonUp&&clickedOn=="topUIButton_"+toString(i)){
                            switch(i){
                                case 0: error("open shop"); break;
                                case 1: error("open settings"); break;
                                case 2:
                                    if(MessageBox(hwnd,"Are you sure you want to quit the program and you're not just testing what it does?","Program:",MB_YESNO)==IDYES){
                                        if(MessageBox(hwnd,"So then you do indeed want to shut this program down?","Program:",MB_YESNO)==IDYES){
                                            if(MessageBox(hwnd,"...but...you do know that it will kill me right?","Program:",MB_YESNO)==IDYES){
                                                MessageBox(hwnd,"Okay, okay. [you monster]","Program:",MB_OK);
                                                SDL_Delay(1000);
                                                MessageBox(hwnd,"...but...","Program:",MB_HELP);
                                                SDL_Delay(500);
                                                if(MessageBox(hwnd,"...are you sure?","Program:",MB_YESNO)==IDYES){
                                                    MessageBox(hwnd,"S","Program:",MB_OK);
                                                    MessageBox(hwnd,"Sh","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shu","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shut","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shutt","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shutti","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shuttin","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shutting","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shutting d","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shutting do","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shutting dow","Program:",MB_OK);
                                                    MessageBox(hwnd,"Shutting down","Program:",MB_OK);
                                                    quit=true;
                                                }
                                                else MessageBox(hwnd,"Aborting self destruction mechanism. Thanks for not killing me!","Program:",MB_OK);
                                            }
                                            else MessageBox(hwnd,"Well i'm glad i told you then.","Program:",MB_OK);
                                        }
                                        else MessageBox(hwnd,"Yeah, didn't think so.","Program:",MB_OK);
                                    }
                                    else MessageBox(hwnd,"Well quit it, you're annoying me!","Program:",MB_OK);
                                break;
                            }
                            UI.topUIButtons[i].currentState=false;
                        }
                    }
                }
                if(leftMouseButtonUp&&clickedOn=="topUIButton_"+toString(i)){
                    clickedOn="";
                    UI.topUIButtons[i].currentState=false;
                }
            }
        }
    }
    if(true){//render Inventory
        renderInventory(false);
    }
}
void functions::renderInventory(bool manageClicks){
    if(player.inventory.open){
    if(manageClicks){
    if(leftMouseButton||rightMouseButton||leftMouseButtonUp||rightMouseButtonUp){
        int slotsLocationY;
        SDL_Rect slotLocation;
        for(int y=0; y<player.inventory.rowsInInventory; y++){
            slotsLocationY=(player.inventory.slotLocationTopLeft.y+player.inventory.distanceBetweenSlots*y)-player.inventory.scrollBarOffset*player.inventory.ratioBetweenBarAndSlots;
            for(int x=0; x<player.inventory.slotsInOneRow; x++){
                if(y*player.inventory.slotsInOneRow+x+1<=(int)player.inventory.itemStacks.size()){
                    slotLocation.x=player.inventory.slotsLocationsX[x];
                    slotLocation.w=player.inventory.imageInventorySlot[0].w;
                    if((int)slotsLocationY<(int)(player.inventory.slotLocationTopLeft.y)){ //render itemSlots that are clipping at top
                        slotLocation.y=player.inventory.slotLocationTopLeft.y;
                        slotLocation.h=player.inventory.imageInventorySlot[0].h-(player.inventory.slotLocationTopLeft.y-slotsLocationY);
                    }
                    else if((int)(slotsLocationY+player.inventory.imageInventorySlot[0].h)>(int)(player.inventory.slotLocationBottomY)){ //render itemSlots that are clipping at bottom
                        slotLocation.y=slotsLocationY;
                        slotLocation.h=(player.inventory.slotLocationBottomY-slotLocation.y)/player.inventory.zoom;
                    }
                    else{
                        slotLocation.y=slotsLocationY;
                        slotLocation.h=player.inventory.imageInventorySlot[0].h;
                    }
                    slotLocation.x+=player.inventory.location.x; slotLocation.y+=player.inventory.location.y;
                    if(pointInsideRect(mouse,slotLocation)){
                        bool equip=false;
                        if(leftMouseButtonUp&&clickedOn=="inventorySlot"+toString(y*player.inventory.slotsInOneRow+x)){
                            clickedOn="";
                            player.inventory.pressedId=y*player.inventory.slotsInOneRow+x;
                            if(player.inventory.doubleClick==-1) player.inventory.doubleClick=FPS/2;
                            else{
                                equip=true;
                                player.inventory.doubleClick=-1;
                            }
                            sendMessageToConsole("pressed Id is now equal to "+toString(player.inventory.pressedId));
                        }
                        if(rightMouseButton||equip){
                            equipItem(y*player.inventory.slotsInOneRow+x);
                            rightMouseButton=false;
                            player.inventory.pressedId=-1;
                        }
						else if (leftMouseButton&&clickedOn == ""&&player.inventory.itemStacks[y*player.inventory.slotsInOneRow + x].ist.itemCount>0){
                            clickedOn="inventorySlot"+toString(y*player.inventory.slotsInOneRow+x);
                            leftMouseButton=false;
                        }
                        x=player.inventory.slotsInOneRow;
                        y=player.inventory.rowsInInventory;
                    }
                    else if(leftMouseButtonUp){
                        if(clickedOn=="inventorySlot"+toString(y*player.inventory.slotsInOneRow+x)){
                            clickedOn="";
                        }
                    }
                }
                else{
                    x=player.inventory.slotsInOneRow;
                    y=player.inventory.rowsInInventory;
                }
            }
        }
        if(rightMouseButton){
            for(int i=0; i<player.inventory.equipmentCount; i++){
                slotLocation.x=player.inventory.equipmentTopLeftLocation.x+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->x+player.inventory.location.x;
                slotLocation.y=player.inventory.equipmentTopLeftLocation.y+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->y+player.inventory.location.y;
                slotLocation.w=player.inventory.equipmentAll[i]->image.surface->w;
                slotLocation.h=player.inventory.equipmentAll[i]->image.surface->h;
                if(pointInsideRect(mouse,slotLocation)){
                    unequipItem(i);
                    rightMouseButton=false;
                    i=player.inventory.equipmentCount;
                }
            }
        }
        if(leftMouseButton||leftMouseButtonUp){
            if(pointInsideRect(mouse,getRect(player.inventory.closeLocation.x+player.inventory.location.x,player.inventory.closeLocation.y+player.inventory.location.y,player.inventory.closeButton.surface->w,player.inventory.closeButton.surface->h))){
                if(leftMouseButton&&clickedOn==""){
                    clickedOn="closeInventory";
                    leftMouseButton=0;
                    player.inventory.closeButton.free();
                    player.inventory.closeButton.surface=TTF_RenderText_Blended(font_lithosPro,"close X",messageColorPressed);
                    RenderType=RENDER_NEAREST;
                    player.inventory.closeButton.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.closeButton.surface);
                    RenderType=RENDER_MIPMAP;
                    player.inventory.update=true;
                }
                else{
                    if(clickedOn=="closeInventory"){
                        player.inventory.closeButton.free();
                        player.inventory.closeButton.surface=TTF_RenderText_Blended(font_lithosPro,"close X",messageColor);
                        RenderType=RENDER_NEAREST;
                        player.inventory.closeButton.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.closeButton.surface);
                        RenderType=RENDER_MIPMAP;
                        player.inventory.open=false;
                        leftMouseButtonUp=false;
                        clickedOn="";
                    }
                }
            }
        }
        if(leftMouseButton){
            if(clickedOn==""&&pointInsideRect(mouse,getRect(player.inventory.location.x+85*player.inventory.zoom,player.inventory.location.y+13*player.inventory.zoom,2358*player.inventory.zoom,177*player.inventory.zoom))){
                SDL_Color tempColor=getPixelColors(player.inventory.imageMain.surface,(mouse.x-player.inventory.location.x)/player.inventory.zoom,(mouse.y-player.inventory.location.y)/player.inventory.zoom);
                if(tempColor.a!=0&&(tempColor.r+tempColor.g+tempColor.b)!=0){
                    clickedOn="moveInventory";
                    mouseOffsetFromMovableObject.x=mouse.x-player.inventory.location.x;
                    mouseOffsetFromMovableObject.y=mouse.y-player.inventory.location.y;
                    leftMouseButton=false;
                }
            }
        }
        else if(clickedOn=="closeInventory"&&leftMouseButtonUp){
            player.inventory.closeButton.free();
            player.inventory.closeButton.surface=TTF_RenderText_Blended(font_lithosPro,"close X",messageColor);
            RenderType=RENDER_NEAREST;
            player.inventory.closeButton.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.closeButton.surface);
            RenderType=RENDER_MIPMAP;
            player.inventory.update=true;
            clickedOn="";
        }
    }
    if(clickedOn=="moveInventory"){
        player.inventory.location.x=mouse.x-mouseOffsetFromMovableObject.x;
        if(player.inventory.location.x<0) player.inventory.location.x=0;
        else if(player.inventory.location.x+player.inventory.imageMain.w>SCREEN_WIDTH) player.inventory.location.x=SCREEN_WIDTH-player.inventory.imageMain.w;
        player.inventory.location.y=mouse.y-mouseOffsetFromMovableObject.y;
        if(player.inventory.location.y<0) player.inventory.location.y=0;
        else if(player.inventory.location.y+player.inventory.imageMain.h>SCREEN_HEIGHT) player.inventory.location.y=SCREEN_HEIGHT-player.inventory.imageMain.h;
        if(leftMouseButtonUp){
            mouseOffsetFromMovableObject.x=0;
            mouseOffsetFromMovableObject.y=0;
            clickedOn="";
        }
    }
    if(leftMouseButton){
        if(pointInsideRect(mouse,getRect(player.inventory.location.x,player.inventory.location.y,player.inventory.imageMain.w,player.inventory.imageMain.h))){
            SDL_Color tempColor=getPixelColors(player.inventory.imageMain.surface,(mouse.x-player.inventory.location.x)/player.inventory.zoom,(mouse.y-player.inventory.location.y)/player.inventory.zoom);
            if(tempColor.a!=0&&(tempColor.r+tempColor.g+tempColor.b)!=0){
                leftMouseButton=false;
            }
        }
    }
    }
    else{
    if(mouseWheelMotion!=0){//process mouse wheel action [move scroll bar]
        float possibleSliderLocation=player.inventory.scrollBarOffset-mouseWheelMotion*sliderSpeed;
        if(possibleSliderLocation>0){
            if(possibleSliderLocation<player.inventory.furthestPossibleSliderLocation){
                player.inventory.scrollBarOffset-=mouseWheelMotion*sliderSpeed;
            }
            else player.inventory.scrollBarOffset=player.inventory.furthestPossibleSliderLocation;
        }
        else player.inventory.scrollBarOffset=0;
    }
    //renderTexture(&player.inventory.imageMain,player.inventory.imageMain.surface->clip_rect,player.inventory.location.x,player.inventory.location.y);
    if(true){//render Item Slots
        Texolder& txl=player.inventory.txl;
        Texolder::TH *THp;
        int found=txl.findTexture(*txl.findLayer("items")),yLocation;
        txl.texture[found].to->y=player.inventory.slotLocationTopLeft.y-player.inventory.scrollBarOffset*player.inventory.ratioBetweenBarAndSlots;
        for(int i=0; i<(int)player.inventory.itemStacks.size(); i+=player.inventory.slotsInOneRow){
            THp=&txl.texture[i+found];
            yLocation=txl.getLocationY(*THp);
            bool render=true;
            if(yLocation<(player.inventory.slotLocationTopLeft.y)){ //render info for itemSlots that are clipping at top
                if(yLocation+THp->layerp->h<(player.inventory.slotLocationTopLeft.y)){ if(buttons[findButton("Tab")].pressed) error(THp->name+" outside top");
                    render=false;
                }
                else{ if(buttons[findButton("Tab")].pressed) error(THp->name+" clip top");

                }
            }
            else if(yLocation+THp->layerp->h>player.inventory.slotLocationBottomY){//render info for itemSlots that are clipping at bottom
                if(yLocation>player.inventory.slotLocationBottomY){ if(buttons[findButton("Tab")].pressed) error(THp->name+" outside bot");
                    render=false;
                }
                else{ if(buttons[findButton("Tab")].pressed) error(THp->name+" clip bot");
                    /*
                    yFrom=0;
                    hFrom=(player.inventory.slotLocationBottomY-yLocation)/player.inventory.zoom;
                    yTo=yLocation;
                    */
                }
            }
            else{ if(buttons[findButton("Tab")].pressed) error(THp->name+" inside");
            }
            for(int o=0; o<player.inventory.slotsInOneRow; o++){
                if(i+o<(int)player.inventory.itemStacks.size()){
                    txl.texture[i+o+found].render=render;
                }
            }
        }
        /*
        int slotsLocationY,yFrom,hFrom,yTo,yFromTemp,hFromTemp,yTo2,yTo3,yFrom2,hFrom2;
        for(int y=0; y<player.inventory.rowsInInventory; y++){
            slotsLocationY=(player.inventory.slotLocationTopLeft.y+player.inventory.distanceBetweenSlots*y)-player.inventory.scrollBarOffset*player.inventory.ratioBetweenBarAndSlots;
            for(int x=0; x<player.inventory.slotsInOneRow; x++){
                if(y*player.inventory.slotsInOneRow+x+1<=(int)player.inventory.itemStacks.size()&&slotsLocationY<player.inventory.slotLocationBottomY){
                    if(slotsLocationY+player.inventory.imageInventorySlot[0].h>player.inventory.slotLocationTopLeft.y){
                        if((int)slotsLocationY<(int)(player.inventory.slotLocationTopLeft.y)){ //render info for itemSlots that are clipping at top
                            yFrom=(player.inventory.slotLocationTopLeft.y-slotsLocationY)/player.inventory.zoom;
                            hFrom=player.inventory.imageInventorySlot[0].surface->h-(yFrom);
                            yTo=player.inventory.slotLocationTopLeft.y;
                        }
                        else if((int)(slotsLocationY+player.inventory.imageInventorySlot[0].h)>(int)(player.inventory.slotLocationBottomY)){//render info for itemSlots that are clipping at bottom
                            yFrom=0;
                            hFrom=(player.inventory.slotLocationBottomY-slotsLocationY)/player.inventory.zoom;
                            yTo=slotsLocationY;
                        }
                        else{//render info for regular itemSlots
                            yFrom=0;
                            hFrom=player.inventory.imageInventorySlot[0].surface->h;
                            yTo=slotsLocationY;
                        }
                        if(player.inventory.pressedId==y*inventorySlotsPerRow+x) renderTexture(&player.inventory.imageInventorySlot[1],0,yFrom,player.inventory.imageInventorySlot[0].surface->w,hFrom,player.inventory.slotsLocationsX[x]+player.inventory.location.x,yTo+player.inventory.location.y);
                        else renderTexture(&player.inventory.imageInventorySlot[0],0,yFrom,player.inventory.imageInventorySlot[0].surface->w,hFrom,player.inventory.slotsLocationsX[x]+player.inventory.location.x,yTo+player.inventory.location.y);
                        if(player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCount>0){//if there's an item in this slot then : render that item
                            if(player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.updateItem){
                                player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.free();
                                player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface=TTF_RenderText_Blended(font,toString(player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCount).c_str(),messageColor);
                                RenderType=RENDER_NEAREST;
                                player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface);
                                RenderType=RENDER_MIPMAP;
                            }
                            yFromTemp=yFrom*player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.containingItem.image.surface->h/player.inventory.imageInventorySlot[0].surface->h;
                            hFromTemp=hFrom*player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.containingItem.image.surface->h/player.inventory.imageInventorySlot[0].surface->h;
                            renderTexture(&player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.containingItem.image,0,yFromTemp,player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.containingItem.image.surface->w,hFromTemp,player.inventory.slotsLocationsX[x]+player.inventory.location.x,yTo+player.inventory.location.y);
                            yTo2=yTo+((player.inventory.imageInventorySlot[0].surface->h-yFrom)*player.inventory.zoom-player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface->h);
                            if(yTo2<player.inventory.slotLocationBottomY){
                                if((int)yTo2<(int)(player.inventory.slotLocationTopLeft.y)){
                                    yFrom2=(player.inventory.slotLocationTopLeft.y-yTo2);
                                    hFrom2=player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface->h-yFrom2;
                                    yTo3=player.inventory.slotLocationTopLeft.y;
                                }
                                else if((int)(yTo2+player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface->h)>(int)(player.inventory.slotLocationBottomY)){
                                    yFrom2=0;
                                    hFrom2=player.inventory.slotLocationBottomY-yTo2;
                                    yTo3=yTo2;
                                }
                                else{
                                    yFrom2=0;
                                    hFrom2=player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface->h;
                                    yTo3=yTo2;
                                }
                                renderTexture(&player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer,0,yFrom2,player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface->w,hFrom2,player.inventory.slotsLocationsX[x]+(player.inventory.imageInventorySlot[0].w-player.inventory.itemStacks[y*inventorySlotsPerRow+x].is.itemCountLayer.surface->w)+player.inventory.location.x,yTo3+player.inventory.location.y);
                            }
                        }
                    }
                }
                else{
                    x=player.inventory.slotsInOneRow;
                    y=player.inventory.rowsInInventory;
                }
            }
        }
        */
    }
    if(false){//render Scroll Bar
        renderTexture(&player.inventory.imageScrollBubbleFull,player.inventory.imageScrollBubbleFull.surface->clip_rect,2354*player.inventory.zoom+player.inventory.location.x,player.inventory.slotLocationTopLeft.y+player.inventory.location.y);
        renderTexture(&player.inventory.imageScrollBarFull,player.inventory.imageScrollBarFull.surface->clip_rect,2354*player.inventory.zoom+player.inventory.location.x,player.inventory.slotLocationTopLeft.y+player.inventory.scrollBarOffset+player.inventory.location.y);
    }
    if(false){//render Equipment
        for(int i=0; i<player.inventory.equipmentCount; i++){
            if(player.inventory.equipmentAll[i]->item.itemCount==0){
                renderTexture(&player.inventory.equipmentAll[i]->image,
                              player.inventory.equipmentAll[i]->image.surface->clip_rect,
                              player.inventory.equipmentTopLeftLocation.x+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->x+player.inventory.location.x,
                              player.inventory.equipmentTopLeftLocation.y+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->y+player.inventory.location.y);
            }
            else{
                renderTexture(&player.inventory.imageInventorySlot[0],player.inventory.imageInventorySlot[0].surface->clip_rect,player.inventory.equipmentTopLeftLocation.x+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->x+player.inventory.location.x,player.inventory.equipmentTopLeftLocation.y+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->y+player.inventory.location.y);
                renderTexture(&player.inventory.equipmentAll[i]->item.containingItem.image,player.inventory.equipmentAll[i]->item.containingItem.image.surface->clip_rect,player.inventory.equipmentTopLeftLocation.x+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->x+player.inventory.location.x,player.inventory.equipmentTopLeftLocation.y+player.inventory.distanceBetweenEquipmentSlots*player.inventory.equipmentAll[i]->y+player.inventory.location.y);
            }
        }
    }
    if(true){//render Stats
    for(int i=0; i<(int)player.stats.size(); i++){
        character::stat& ps=player.stats[i];
        Texolder& txl=player.inventory.txl;
        int id=ps.levelBase/100+1;
        if(ps.updateAddition){ ps.updateAddition=false; ps.update=true;
            if(ps.levelAddition!=0){
                txl.texture[txl.findTexture(ps.statName+" addition count")].render=true;
                ps.levelAdditionLayer.free();
                ps.levelAdditionLayer.surface=TTF_RenderText_Blended(font_lithosPro,("+"+toString(ps.levelAddition)).c_str(),additionColor);
                ps.levelAdditionLayer.from=ps.levelAdditionLayer.surface->clip_rect;
                ps.levelAdditionLayer.to=getRect(ps.levelBaseLayer.surface->w,0,ps.levelAdditionLayer.surface->w,ps.levelAdditionLayer.surface->h);
                ps.levelAdditionLayer.textureOpenGL=convertSurfaceToOpenGLTexture(ps.levelAdditionLayer.surface);
                txl.texture[txl.findTexture(ps.statName+" bar addition")].render=true;
                layer& layeRef=player.inventory.additionBar.full;
                ps.additionBarWidth=ceil(layeRef.surface->w*((float)ps.levelAddition/(float)100));
            }
            else{
                Texolder::TH* thl; std::string text;
                ps.additionBarWidth=0;
                for(int i=0; i<2; i++){
                    switch(i){
                        case 0: text="addition count"; break;
                        case 1: text="bar addition";   break;
                    }
                    thl=&txl.texture[txl.findTexture(ps.statName+" "+text)];
                    thl->render=false;
                    thl->to->w=0;
                }
            }
        }
        if(ps.update){ ps.update=false;
            Texolder::TH* thl; layer* layerp; std::string text,statName;
            for(int o=0; o<2; o++){
                switch(o){
                    case 0:
                        layerp=&ps.statNameLayer;
                        text=ps.statName;
                        statName="name";
                    break;
                    case 1:
                        layerp=&ps.levelBaseLayer;
                        text=toString(ps.levelBase);
                        statName="level count";
                    break;
                }
                layerp->free();
                layerp->surface=TTF_RenderText_Blended(font_lithosPro,text.c_str(),messageColor);
                layerp->textureOpenGL=convertSurfaceToOpenGLTexture(layerp->surface);
                thl=&txl.texture[txl.findTexture(ps.statName+" "+statName)];
                thl->from=&layerp->surface->clip_rect; thl->to->w=layerp->surface->w; thl->to->h=layerp->surface->h;
                if(o==1){
                    ps.levelAdditionLayer.to.x=layerp->surface->w;
                    thl=&txl.texture[txl.findTexture(ps.statName+" bar main")];
                    thl->layerp=&player.inventory.statsBar[id].full;
                    thl->to->y=player.inventory.distanceBetweenStats-((player.inventory.distanceBetweenStats-layerp->surface->h)/2)-thl->layerp->h/2;
                    ps.mainBar.from.w=thl->layerp->surface->w*((float)(ps.levelBase%100)/(float)100); ps.mainBar.to.w=ps.mainBar.from.w;
                    ps.additionBar.from.x=ps.mainBar.from.w;
                    ps.additionBar.from.w=thl->layerp->surface->w-ps.additionBar.from.x;
                    if(ps.additionBar.from.w>ps.additionBarWidth) ps.additionBar.from.w=ps.additionBarWidth;
                    ps.additionBar.to.w=ps.additionBar.from.w;
                    ps.additionBar.to.x=ps.additionBar.from.x*thl->layerp->zoom*thl->layerp->zoomWidth;
                    ps.backgroundBar.from.x=ps.additionBar.from.w;
                    ps.backgroundBar.to.x=ps.backgroundBar.from.x*thl->layerp->zoom*thl->layerp->zoomWidth;
                    ps.backgroundBar.from.w=thl->layerp->surface->w-ps.additionBarWidth-ps.mainBar.from.w;
                    if(ps.backgroundBar.from.w<0) ps.backgroundBar.from.w=0;
                    ps.backgroundBar.to.w=ps.backgroundBar.from.w;
                    thl=&txl.texture[txl.findTexture(ps.statName+" bar background")];
                    thl->layerp=&player.inventory.statsBar[id-1].full;
                    thl=&txl.texture[txl.findTexture(ps.statName+" bar gradient")];
                    thl->layerp=&player.inventory.statsBar[id].gradient;
                }
            }
        }
    }
    }
    if(false){//render Close button
        renderTexture(&player.inventory.closeButton,
                      player.inventory.closeButton.surface->clip_rect,
                      player.inventory.closeLocation.x+player.inventory.location.x,
                      player.inventory.closeLocation.y+player.inventory.location.y);
    }
    player.inventory.txl.renderTextures();
    }
    }
    else if(manageClicks){
        if(clickedOn=="moveInventory"){
            mouseOffsetFromMovableObject.x=0;
            mouseOffsetFromMovableObject.y=0;
            clickedOn="";
        }
        else if(clickedOn=="closeInventory"){
            player.inventory.closeButton.free();
            player.inventory.closeButton.surface=TTF_RenderText_Blended(font_lithosPro,"close X",messageColor);
            RenderType=RENDER_NEAREST;
            player.inventory.closeButton.textureOpenGL=convertSurfaceToOpenGLTexture(player.inventory.closeButton.surface);
            RenderType=RENDER_MIPMAP;
            player.inventory.update=true;
            clickedOn="";
        }
        else if(clickedOn.substr(0,12)=="inventorySlot"){
            clickedOn="";
            player.inventory.pressedId=-1;
        }
    }
    else{
        player.inventory.pressedId=-1;
    }
}
void functions::giveItems(itemStack &itemsToGive){
    for(Uint8 i=0; i<player.inventory.itemStacks.size(); i++){
		if (player.inventory.itemStacks[i].ist.containingItem == itemsToGive.containingItem){
			player.inventory.itemStacks[i].ist.itemCount += itemsToGive.itemCount;
			player.inventory.itemStacks[i].ist.updateItem = true;
            i=player.inventory.itemStacks.size();
        }
		else if (player.inventory.itemStacks[i].ist.itemCount == 0){
			player.inventory.itemStacks[i].ist = itemsToGive;
            i=player.inventory.itemStacks.size();
        }
    }
    player.inventory.update=true;
}
void functions::giveItems(item &itemToGive, int ammount){
    for(Uint8 i=0; i<player.inventory.itemStacks.size(); i++){
		if (player.inventory.itemStacks[i].ist.containingItem == itemToGive){
			player.inventory.itemStacks[i].ist.itemCount += ammount;
			player.inventory.itemStacks[i].ist.updateItem = true;
            i=player.inventory.itemStacks.size();
        }
		else if (player.inventory.itemStacks[i].ist.itemCount == 0){
			player.inventory.itemStacks[i].ist.itemCount = ammount;
			player.inventory.itemStacks[i].ist.containingItem = itemToGive;
			player.inventory.itemStacks[i].ist.updateItem = true;
            i=player.inventory.itemStacks.size();
        }
    }
    player.inventory.update=true;
}
void functions::giveItems(item &itemToGive, int ammount, itemStack &toWhere){
    toWhere.itemCount=ammount;
    toWhere.containingItem=itemToGive;
    toWhere.updateItem=true;
}
int functions::findNextStage(std::vector<stage> &stages, int currentStage){
    for(int i=currentStage+1; i<(int)stages.size(); i++){
        if(stages[i].shortcut){
            return i;
        }
    }
    return 0;
}
int functions::findItem(std::string itemName){
    for(Uint8 i=0; i<items.size(); i++){
        if(items[i].name==itemName){
            return i;
        }
    }
    error(itemName+" item was not found, fix the program you lazy programmer!");
    return -1;
}
void functions::addItem(std::string name, std::string type, std::string imagePath){
    item item_temp;
    item_temp.name=name;
    item_temp.type=type;
    if(loadImage(imagePath,item_temp.image)==0){
        item_temp.image.setWidthZoom((float)player.inventory.imageInventorySlot[0].w/(float)item_temp.image.surface->w);
        item_temp.image.setHeightZoom((float)player.inventory.imageInventorySlot[0].h/(float)item_temp.image.surface->h);
        items.push_back(item_temp);
    }
}
bool functions::movePoint(SDL_Point *point, int movementSpeed){
    bool change=false;
    if(buttons[findButton("D")].pressed==1 || buttons[findButton("Right")].pressed==1) {point->x+=movementSpeed; change=true;}
    if(buttons[findButton("A")].pressed==1 || buttons[findButton("Left")].pressed==1)  {point->x-=movementSpeed; change=true;}
    if(buttons[findButton("S")].pressed==1 || buttons[findButton("Down")].pressed==1)  {point->y+=movementSpeed; change=true;}
    if(buttons[findButton("W")].pressed==1 || buttons[findButton("Up")].pressed==1)    {point->y-=movementSpeed; change=true;}
    return change;
}
SDL_Point functions::getPoint(int x, int y){
    SDL_Point returnValue;
    returnValue.x=x;
    returnValue.y=y;
    return returnValue;
}
SDL_Rect functions::getRect(int x, int y, int w, int h){
    SDL_Rect returnValue;
    returnValue.x=x;
    returnValue.y=y;
    returnValue.w=w;
    returnValue.h=h;
    return returnValue;
}
bool functions::pointInsideRect(SDL_Point point, SDL_Rect rect){
    if(
       point.x>=rect.x+offset.x
        &&
       point.x<=rect.x+rect.w+offset.x
        &&
       point.y>=rect.y+offset.y
        &&
       point.y<=rect.y+rect.h+offset.y
      ) return true;
    return false;
}
int functions::findImage(std::string imageIdInFormOfString){
    for(Uint8 i=0; i<images.size(); i++){
        if(images[i].id==imageIdInFormOfString){
            return i;
        }
    }
    error(imageIdInFormOfString+" image was not found, fix the program you lazy programmer!");
    return -1;
}
void functions::createImage(std::string imagePath, std::string imageIdInFormOfString){
    img image_temp;
    image_temp.id=imageIdInFormOfString;
    if(loadImage(imagePath,image_temp.image)==0){
        images.push_back(image_temp);
    }
    else error("The program was unable to create an image. [Info: imagePath="+imagePath+";");
}
void functions::addEnemyId(std::string enemyName){
    battleEnemiesIds.push_back(findEntity(enemyName));
}
int functions::findEntity(std::string name){
    for(Uint8 i=0; i<entities.size(); i++){
        if(entities[i].name==name){
            return i;
        }
    }
    error(name+" entity was not found, fix the program you lazy programmer!");
    return -1;
}
void functions::callEvent(std::string type, info &information){
    if(type=="Enter"){
        callEventEnter(information);
    }
    else if(type=="Battle"){
        callEventBattle(information);
    }
    else if(type=="Gather"){
        callEventGather(information);
    }
    else{
        error(type+"was not added to the callEvent function.\nFix the program you lazy programmer!");
    }
}
void functions::callEventGather(info &information){
    player.gathering=1;
    player.gatherableId=information.intInfo[0];
}
void functions::callEventEnter(info &information){
    player.map_location=information.intInfo[0];
    player.location.x=information.intInfo[1];
    player.location.y=information.intInfo[2];
    sendMessageToConsole("Player went into map "+toString(player.map_location)+", to coordinates ["+toString(player.location.x)+";"+toString(player.location.y)+"]");
}
void functions::callEventBattle(info &information){
    battleZoneId=information.intInfo[0];
    for(int i=0;i<information.intInfo[1];i++){
        battleEnemies.push_back(entities[information.intInfo[i+2]]);
    }
    player.isInBattle=1;
    player.map_location=ammountOfMaps+battleZoneId;
}
void functions::addEntity(float healthPoints,int level,float manaPoints,std::string name, std::string imagePath, double legCenterX, double legCenterY){
    entity entity_temp;
    entity_temp.healthPoints=healthPoints;
    entity_temp.level=level;
    entity_temp.manaPoints=manaPoints;
    entity_temp.name=name;
    if(loadImage(imagePath,entity_temp.image)==0){
        entity_temp.legCenter.x=legCenterX/entity_temp.image.surface->w;
        entity_temp.legCenter.y=legCenterY/entity_temp.image.surface->h;
        entities.push_back(entity_temp);
    }
}
void functions::getEntityCornerColors(SDL_Surface* surface, SDL_Color colorHolder[4], SDL_Point pixelLocation[4]){
    std::stringstream ss;
    SDL_Rect rect;
    for(int i=0; i<4; i++) {
        rect.x=player.image.location.x;
        rect.y=player.image.location.y;
        rect.w=player.image.surface->w;
        rect.h=player.image.surface->h;
        getEntityCorner(i+1,player.location,rect,pixelLocation[i]);
        pixelLocation[i].x=pixelLocation[i].x*surface->w/SCREEN_WIDTH;
        pixelLocation[i].y=pixelLocation[i].y*surface->h/SCREEN_HEIGHT;
        getPixelColors(surface,pixelLocation[i].x,
                                          pixelLocation[i].y,
                                          colorHolder[i]);
        if(buttons[findButton("F")].pressed==1) ss << "[" << pixelLocation[i].x << ";" << pixelLocation[i].y << "]=[" << toString(colorHolder[i].r) << "," << toString(colorHolder[i].g) << "," << toString(colorHolder[i].b) << "," << toString(colorHolder[i].a) << "]\n";
    }
    if(buttons[findButton("F")].pressed==1) error(ss.str());
}
void functions::getEntityCorner(int corner, SDL_Point entityLocation, SDL_Rect& entityRect, SDL_Point &locationHolder){
    locationHolder=entityLocation;
    switch(corner){
    case 2:
        locationHolder.x+=entityRect.w;
        break;
    case 3:
        locationHolder.x+=entityRect.w;
        locationHolder.y+=entityRect.h;
        break;
    case 4:
        locationHolder.y+=entityRect.h;
        break;
    }
}
void functions::addObstruction(int r, int g, int b, int a){
    SDL_Color color;
    color.r=r;
    color.g=g;
    color.b=b;
    color.a=a;
    obstructions.push_back(color);
}
void functions::addObstruction(SDL_Color color){
    obstructions.push_back(color);
}
int functions::findButton(std::string name){
    for(Uint8 i=1; i<buttons.size(); i++){
        if(buttons[i].name==name){
            return i;
        }
    }
    error("Button by the name of "+name+" was not found, fix the program!");
    return 0;
}
void functions::moveCharacter(bool withObstructions, SDL_Surface* surfaceOfObstructions){
    if(withObstructions){
        SDL_Color currentColor[4]; SDL_Point pixelLocation[4];
        SDL_Point savedLocation=player.location;
        moveCharacter();
        SDL_Point movedLocation=player.location;
        SDL_Point doneLocation=movedLocation;

        player.location.x=movedLocation.x;
        player.location.y=savedLocation.y;
        getEntityCornerColors(surfaceOfObstructions,currentColor,pixelLocation);
        for(Uint8 i=0; i<obstructions.size(); i++){
            if(equalColors(currentColor[0],obstructions[i])||
               equalColors(currentColor[1],obstructions[i])||
               equalColors(currentColor[2],obstructions[i])||
               equalColors(currentColor[3],obstructions[i])){
                doneLocation.x=savedLocation.x;
                i=obstructions.size();
            }
        }
        player.location.x=savedLocation.x;
        player.location.y=movedLocation.y;
        getEntityCornerColors(surfaceOfObstructions,currentColor,pixelLocation);
        for(Uint8 i=0; i<obstructions.size(); i++){
            if(equalColors(currentColor[0],obstructions[i])||
               equalColors(currentColor[1],obstructions[i])||
               equalColors(currentColor[2],obstructions[i])||
               equalColors(currentColor[3],obstructions[i])){
                doneLocation.y=savedLocation.y;
                i=obstructions.size();
            }
        }
        player.location=doneLocation;
    }
    else{
        moveCharacter();
    }
}
void functions::moveCharacter(){
    SDL_Point* movedObject;
    if(moveObject==OBJECT_PLAYER) movedObject=&player.location;
    else if(moveObject==OBJECT_SCREEN) movedObject=&offset;
    if(player.isInBattle==0){
        if(buttons[findButton("D")].pressed==1 || buttons[findButton("Right")].pressed==1) movedObject->x+=player.movementSpeed;
        if(buttons[findButton("A")].pressed==1 || buttons[findButton("Left")].pressed==1)  movedObject->x-=player.movementSpeed;
        if(buttons[findButton("S")].pressed==1 || buttons[findButton("Down")].pressed==1)  movedObject->y+=player.movementSpeed;
        if(buttons[findButton("W")].pressed==1 || buttons[findButton("Up")].pressed==1)    movedObject->y-=player.movementSpeed;
    }
}
void functions::addSpell(std::string type, float damage, float manaCost, std::string base, std::string icon_active, std::string icon_cooldown, int x, int y){
    spell spell_temp;
    spell_temp.elementType=type;
    spell_temp.damage=damage;
    spell_temp.manaCost=manaCost;
    spell_temp.offset.x=x;
    spell_temp.offset.y=y;
    if (loadImage(base, spell_temp.base)==0&&loadImage(icon_active, spell_temp.icon_active)==0&&loadImage(icon_cooldown, spell_temp.icon_cooldown)==0){
        Spells.push_back(spell_temp);
       }

}
void functions::addButton(std::string name, SDL_Keycode key){
    keyboard button_temp;
    button_temp.name=name;
    button_temp.keycode=key;
    buttons.push_back(button_temp);
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,SDL_Rect &destinationRect){
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        error(SDL_GetError());
    }
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceAndDestRect){
    if(SDL_BlitSurface(sourceSurface,&sourceAndDestRect,destinationSurface,&sourceAndDestRect)!=0){
        error(SDL_GetError());
    }
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect, bool fillSurface){
    SDL_Rect destinationRect;
    if(fillSurface){
        destinationRect.x=0;                destinationRect.y=0;
        destinationRect.w=sourceSurface->w; destinationRect.h=sourceSurface->h;
        if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
            error(SDL_GetError());
        }
    }
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1,int x2, int y2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w1; destinationRect.h=h1;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        error(SDL_GetError());
    }
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w2; destinationRect.h=h2;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        error(SDL_GetError());
    }
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,int x, int y, int w, int h){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=w; destinationRect.h=h;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        error(SDL_GetError());
    }
}
void functions::copySurface(SDL_Surface* sourceSurface, SDL_Surface* destinationSurface, SDL_Rect &sourceRect,int x, int y){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=sourceRect.w; destinationRect.h=sourceRect.h;
    if(SDL_BlitSurface(sourceSurface,&sourceRect,destinationSurface,&destinationRect)!=0){
        error(SDL_GetError());
    }
}
void functions::renderTexture(layer* texture,SDL_Rect &sourceRect,SDL_Rect &destinationRect){
    openGLRender(texture,&sourceRect,&destinationRect);
}
void functions::renderTexture(layer* texture,SDL_Rect &sourceAndDestRect){
    openGLRender(texture,&sourceAndDestRect,&sourceAndDestRect);
}
void functions::renderTexture(layer* texture,int x, int y, int w, int h){
    SDL_Rect sourceAndDestRect;
    sourceAndDestRect.x=x; sourceAndDestRect.w=w;
    sourceAndDestRect.y=y; sourceAndDestRect.h=h;
    openGLRender(texture,&sourceAndDestRect,&sourceAndDestRect);
}
void functions::renderTexture(layer* texture,SDL_Rect &sourceRect, bool fillScreen){
    SDL_Rect destinationRect;
    if(fillScreen){
        destinationRect.x=0;              destinationRect.y=0;
        destinationRect.w=SCREEN_WIDTH; destinationRect.h=SCREEN_HEIGHT;
        openGLRender(texture,&sourceRect,&destinationRect);
    }
}
void functions::renderTexture(layer* texture,int x1, int y1, int w1, int h1,int x2, int y2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w1; destinationRect.h=h1;
    openGLRender(texture,&sourceRect,&destinationRect);
}
void functions::renderTexture(layer* texture,int x1, int y1, int w1, int h1,int x2, int y2, int w2, int h2){
    SDL_Rect sourceRect,destinationRect;
    sourceRect.x=x1;      sourceRect.y=y1;
    sourceRect.w=w1;      sourceRect.h=h1;
    destinationRect.x=x2; destinationRect.y=y2;
    destinationRect.w=w2; destinationRect.h=h2;
    openGLRender(texture,&sourceRect,&destinationRect);
}
void functions::renderTexture(layer* texture,SDL_Rect &sourceRect,int x, int y, int w, int h){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=w; destinationRect.h=h;
    openGLRender(texture,&sourceRect,&destinationRect);
}
void functions::renderTexture(layer* texture,SDL_Rect &sourceRect,int x, int y){
    SDL_Rect destinationRect;
    destinationRect.x=x; destinationRect.y=y;
    destinationRect.w=sourceRect.w; destinationRect.h=sourceRect.h;
    openGLRender(texture,&sourceRect,&destinationRect);
}
void functions::openGLRender(layer* texture,SDL_Rect* sourceRect,SDL_Rect* destRect){
    if(texture->textureOpenGL!=0){
        float point[8];
        point[0]=0.f;
        point[1]=point[0];
        point[2]=destRect->w*texture->zoom*texture->zoomWidth;
        point[3]=point[0];
        point[4]=point[2];
        point[5]=destRect->h*texture->zoom*texture->zoomHeight;
        point[6]=point[0];
        point[7]=point[5];
        float cornerX[4],cornerY[4];
        cornerX[0]=(float)(sourceRect->x)/(float)(texture->surface->w);              cornerX[3]=cornerX[0];
        cornerX[1]=((float)(sourceRect->w)/(float)(texture->surface->w))+cornerX[0]; cornerX[2]=cornerX[1];
        cornerY[0]=(float)(sourceRect->y)/(float)(texture->surface->h);              cornerY[1]=cornerY[0];
        cornerY[2]=((float)(sourceRect->h)/(float)(texture->surface->h))+cornerY[0]; cornerY[3]=cornerY[2];
        glLoadIdentity();
        glTranslatef(SCREEN_WIDTH/2,SCREEN_HEIGHT/2,0.f);
        glRotatef(rotationAngle,0.f,0.f,0.f);
        glRotatef(rotationAngle,0.f,0.f,1.f);
        glTranslatef(destRect->x+offset.x-SCREEN_WIDTH/2,destRect->y+offset.y-SCREEN_HEIGHT/2,0.f);
        glBindTexture(GL_TEXTURE_2D,texture->textureOpenGL);
        glColor4f(texture->r,texture->g,texture->b,texture->a);
        glBegin(GL_QUADS);
            glTexCoord2f(cornerX[0],cornerY[0]);
                glVertex2f(point[0],point[1]);
            glTexCoord2f(cornerX[1],cornerY[1]);
                glVertex2f(point[2],point[3]);
            glTexCoord2f(cornerX[2],cornerY[2]);
                glVertex2f(point[4],point[5]);
            glTexCoord2f(cornerX[3],cornerY[3]);
                glVertex2f(point[6],point[7]);
        glEnd();
    }
}
std::string functions::toString(int number){
    std::stringstream ss;
    ss << number;
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
bool functions::equalColors(SDL_Color a, SDL_Color b){
    if(a.r==b.r&&a.g==b.g&&a.b==b.b&&a.a==b.a) return true;
    else return false;
}
void functions::addColor(int r, int g, int b, int a){
    SDL_Color color_temp;
    color_temp.r=r;
    color_temp.g=g;
    color_temp.b=b;
    color_temp.a=a;
    Colors.push_back(color_temp);
}
void functions::addColor(int r, int g, int b){
    SDL_Color color_temp;
    color_temp.r=r;
    color_temp.g=g;
    color_temp.b=b;
    color_temp.a=255;
    Colors.push_back(color_temp);
}
SDL_Color functions::getColor(int id){
    if(id>0&&(Uint8)id<Colors.size()){
        return Colors[id-1];
    }
    error("There's no color with id "+id);
    SDL_Color color={255,255,255,255};
    return color;
}
int functions::getZoneId(SDL_Surface* secretLayer){ //returns -1 if it doesn't find the corresponding color
    SDL_Color color;
    getPixelColors(secretLayer,player.location.x,player.location.y,color);
    for(Uint8 i=0; i<Colors.size(); i++){
        if(equalColors(color,getColor(i))){
            return i;
        }
    }
    error("Color ["+toString(color.r)+","+toString(color.g)+","+toString(color.b)+","+toString(color.a)+"] is not in the color list.");
    return -1;
}
Uint32 functions::getPixel(SDL_Surface *surface, int x, int y){
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
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
void functions::getPixelColors(SDL_Surface* surface, double x, double y, SDL_Color &colorHolder){
    SDL_PixelFormat *format;
	Uint32 temp, pixel;
	Uint8 color[4];

    format=surface->format;
    SDL_LockSurface(surface);
    pixel=getPixel(surface,x,y);
    SDL_UnlockSurface(surface);

    temp=pixel&format->Rmask; /* Isolate red component */
    temp=temp>>format->Rshift;/* Shift it down to 8-bit */
    temp=temp<<format->Rloss; /* Expand to a full 8-bit number */
    color[0]=(Uint8)temp;

    temp=pixel&format->Gmask; /* Isolate green component */
    temp=temp>>format->Gshift;/* Shift it down to 8-bit */
    temp=temp<<format->Gloss; /* Expand to a full 8-bit number */
    color[1]=(Uint8)temp;

    temp=pixel&format->Bmask; /* Isolate blue component */
    temp=temp>>format->Bshift;/* Shift it down to 8-bit */
    temp=temp<<format->Bloss; /* Expand to a full 8-bit number */
    color[2]=(Uint8)temp;

    temp=pixel&format->Amask; /* Isolate alpha component */
    temp=temp>>format->Ashift;/* Shift it down to 8-bit */
    temp=temp<<format->Aloss; /* Expand to a full 8-bit number */
    color[3]=(Uint8)temp;

    colorHolder.r=color[0];
    colorHolder.g=color[1];
    colorHolder.b=color[2];
    colorHolder.a=color[3];
}
SDL_Color functions::getPixelColors(SDL_Surface* surface, double x, double y){
    SDL_Color colorHolder;
    getPixelColors(surface,x,y,colorHolder);
    return colorHolder;
}
int functions::loadImage(std::string path, layer &layererer){
    layererer.surface=NULL;
	layererer.surface = IMG_Load(path.c_str());
    if(layererer.surface==NULL){
        error("image in this directory: "+path+"was not found.");
        return 1;
    }
	else{
		layererer.updateSize();
		layererer.textureOpenGL = convertSurfaceToOpenGLTexture(layererer.surface);
        layererer.location.x=0;
        layererer.location.y=0;
	}
    return 0;
}
void functions::error(int errorNumber){
    switch(errorNumber){
    case 1:
        MessageBox(hwnd,"Linear texture filtering not enabled!","Warning:",MB_OK);
        break;
    }
}
void functions::error(std::string errorMessage){
    MessageBox(hwnd,errorMessage.c_str(),NULL,MB_OK);
}
bool functions::initialize(){
	bool success=true;
	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO)<0) {
        success=false;
        error("SDL could not initialize! SDL Error: "+(*SDL_GetError()));
	}
	else{
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
	}

    //Set texture filtering to linear
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"2")) error(1);

    //Create window
    window = SDL_CreateWindow( screenName.c_str(), screenStartPosition.x, screenStartPosition.y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | fullscreen);
	SDL_SetWindowBordered(console_window,SDL_FALSE);
    console_window = SDL_CreateWindow( consoleScreenName.c_str(), 1680+(1280-CONSOLE_SCREEN_WIDTH)/2, (1024-CONSOLE_SCREEN_HEIGHT)/2, CONSOLE_SCREEN_WIDTH, CONSOLE_SCREEN_HEIGHT, fullscreen);
    if(success&&(window==NULL||console_window==NULL)){ //error
        error("Window could not be created! SDL Error: "+(*SDL_GetError()));
        success=false;
    }
    else{
        GLContext=SDL_GL_CreateContext(window);
        if(GLContext==NULL){
            error("OpenGL context could not be created! SDL Error: "+(*SDL_GetError()));
            success=false;
        }
        else{
            if(SDL_GL_SetSwapInterval(1)<0){
                error( "Warning: Unable to set VSync! SDL Error: "+(*SDL_GetError()));
            }
            if(!initGL()){
                error("Unable to initialize OpenGL!");
                success=false;
            }
            SDL_VERSION(&WindowInfo.version);
            SDL_GetWindowWMInfo(window,&WindowInfo);
            hwnd=WindowInfo.info.win.window;
            SDL_GetWindowWMInfo(console_window,&ConsoleWindowInfo);
            console_hwnd=ConsoleWindowInfo.info.win.window;
            //Create renderer for window
            renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
            consoleRenderer=SDL_CreateRenderer(console_window,-1,SDL_RENDERER_ACCELERATED);
            if(renderer==NULL||consoleRenderer==NULL) { //error
                error("Renderer could not be created! SDL Error: "+(*SDL_GetError()));
                success=false;
            }
            else{
                //Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
                if( !(IMG_Init(imgFlags) & imgFlags ) ) {//error
                    error("SDL_image could not initialize! SDL_image Error: "+(*IMG_GetError()));
                    success=false;
                }
				else{
                    if(TTF_Init()<0) {//error
                        error("SDL_ttf could not initialize! SDL_ttf Error: "+(*SDL_GetError()));
                        success = false;
                    }
					else{
						loadImage("Graphics\\menu slices\\favicon_seti.png", iconMain);
						loadImage("Graphics\\menu slices\\debug_icon.png", iconDebug);
                        SDL_SetWindowIcon(console_window,iconDebug.surface);
                        SDL_SetWindowIcon(window,iconMain.surface);
                    }
                }
            }
        }
	}
	return success;
}
bool functions::initGL(){
    //Set the viewport
    glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );

    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glClearColor( 0.f, 0.f, 0.f, 1.f );

    //Enable texturing
    glEnable( GL_TEXTURE_2D );

    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR ){
        return false;
    }

    return true;
}
void functions::close() {
    //Destroy window
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window=NULL;
	renderer=NULL;
	//Quit SDL subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}