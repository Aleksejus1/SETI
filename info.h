#ifndef INFO_H
#define INFO_H

#include "libs.h"

class info{
    public:
        info();
        std::vector<int> intInfo;
        std::vector<float> floatInfo;
        std::vector<std::string> stringInfo;
        void addInfo(int info);
        void addInfo(float info);
        void addInfo(std::string info);
};

#endif // INFO_H
