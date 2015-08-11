#pragma once
#include "libs.h"
#include "info.h"
class task{
	public:
		task();
		void setType(std::string);
		void setInfo(info&);
	private:
		std::string type;
		info information;
};

