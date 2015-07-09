#include "userInterface.h"
#include "libs.h"

userInterface::userInterface(functions *fp):
botUItxl(fp){
    f=fp;
    all[0]=&bar_red;
    all[1]=&bar_blue;
    all[2]=&bar_grey;
}
