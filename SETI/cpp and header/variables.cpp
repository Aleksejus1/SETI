#include "variables.h"
#include "libs.h"
#include "character.h"
#include "map.h"
#include "spell.h"

variables::variables(){
	messageColor = { 255, 255, 255, 255 };
	messageColorPressed = { 215, 215, 215, 255 };
	additionColor = { 14, 90, 0, 255 };
	levelColor = { 185, 0, 4, 255 };
	offset = { 0, 0 };
	mouseOffsetFromMovableObject = { 0, 0 };
	screenStartPosition = { (1680 - SCREEN_WIDTH) / 2, (1050 - SCREEN_HEIGHT) / 2 };
}
