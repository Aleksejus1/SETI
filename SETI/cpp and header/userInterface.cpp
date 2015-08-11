#include "userInterface.h"
#include "libs.h"

userInterface::userInterface(functions *fp) :
botUItxl(fp){
	f = fp;
	all[0] = &bar_red;
	all[1] = &bar_blue;
	all[2] = &bar_grey;
	TabStats.closeButtonOffsetFromTopRight = { 118, 118 };
	QuestsTab& TQ = TabQuests;
	TQ.location = { 0, 0 };
	TQ.questsIconWH = 180;
	TQ.QRectH = TQ.questsIconWH*1.25f;
	TQ.questIconOffset.x = TQ.questsIconWH / 8; TQ.questIconOffset.y = TQ.questIconOffset.x;
	TQ.closeButtonOffsetFromTopRight = { 108, 81 };
	TQ.questsRenderArea = { 186, 239, 1680, 700};
	TQ.distanceBetweenQuests = (int)(TQ.QRectH*0.25f);
	TQ.slotLocationTopLeftBase = { 0, 0 };
}
