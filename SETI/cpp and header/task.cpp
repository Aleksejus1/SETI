#include "task.h"

task::task(){}

void task::setType(std::string taskType){
	type = taskType;
}

void task::setInfo(info& taskInfo){
	information = taskInfo;
}