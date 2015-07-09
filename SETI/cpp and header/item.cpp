#include "item.h"
#include "libs.h"

item::item(){
    reset();
}

bool operator==(item &a, item &b){
    if(a.name==b.name&&a.type==b.type) return true;
    return false;
}

void item::reset(){
    name="empty";
    type="none";
    damage=0;
    affectedStats.clear();
}