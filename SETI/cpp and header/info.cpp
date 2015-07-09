#include "info.h"
#include "libs.h"

info::info()
{
    //ctor
}

void info::addInfo(int info){
    info::intInfo.push_back(info);
}

void info::addInfo(float info){
    info::floatInfo.push_back(info);
}

void info::addInfo(std::string info){
    info::stringInfo.push_back(info);
}