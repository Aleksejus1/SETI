#include "userInterface.h"
#include "libs.h"

userInterface::userInterface(functions *fp){
	f = fp;
	all[0] = &bar_red;
	all[1] = &bar_blue;
	all[2] = &bar_grey;
	TabStats.closeButtonOffsetFromTopRight = { 118, 118 };
	QuestsTab& TQ = TabQuests;
	TQ.zoom = 2.f / 5.f;
	TQ.questsRenderArea = { 186, 239, 1680, 700 };
	TQ.QRectH = TQ.questsRenderArea.h*TQ.zoom / 1.25f;
	TQ.questsIconWH = (int)(TQ.QRectH / 1.25f);
	TQ.location = { 0, 0 };
	TQ.questIconOffset.x = TQ.questsIconWH / 8; TQ.questIconOffset.y = TQ.questIconOffset.x;
	TQ.closeButtonOffsetFromTopRight = { 108, 81 };
	TQ.distanceBetweenQuests = (int)(TQ.QRectH*0.25f);
	float unit = TQ.QRectH*1.25f;
	TQ.ScrollBar.initialize(287, 5, 
							TQ.questsRenderArea.h / unit + 0.2f,
							0, //calculate each tick
							unit * TQ.zoom,
							5.f,
							false);
	TQ.ScrollBar.location = { 873, 87 };
}
