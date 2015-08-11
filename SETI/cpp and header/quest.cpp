#include "quest.h"
#include "functions.h"

quest::quest(){}

void quest::addTask(std::string taskType, info& taskInfo){
	task taskTemp;
	taskTemp.setType(taskType);
	taskTemp.setInfo(taskInfo);
	tasks.push_back(taskTemp);
}
void quest::setShortDescription(std::string shortQuestDescription){
	shortDescription.text = shortQuestDescription;
	shortDescription.image.free();
	shortDescription.update = true;
}
void quest::setDescription(std::string fullQuestDescription){
	fullDescription.text = fullQuestDescription;
	fullDescription.image.free();
	fullDescription.update = true;
}
void quest::setName(std::string Name){
	name.text = Name;
	name.image.free();
	name.update = true;
}
std::string quest::getName(){
	return name.text;
}
layer* quest::getShortDescriptionImage(int pixelLengthUntilWrapping){
	if (shortDescription.update){
		shortDescription.update = false;
		libs libTemp;
		libTemp.writeWrappedMessage(shortDescription.text, shortDescription.image,pixelLengthUntilWrapping);
	}
	return &shortDescription.image;
}