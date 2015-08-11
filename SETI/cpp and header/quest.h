#pragma once
#include "libs.h"
#include "layer.h"
#include "task.h"

class quest{
	public:
		quest();
		void addTask(std::string, info&);
		void setShortDescription(std::string);
		void setDescription(std::string);
		void setName(std::string);
		std::string getName();
		layer* getShortDescriptionImage(int);
		layer icon;
		bool collapse = false;
		int additionalHeight = 0;
	private:
		struct txt{ bool update; std::string text; layer image; } shortDescription, fullDescription, name;
		std::vector<task> tasks;
};

