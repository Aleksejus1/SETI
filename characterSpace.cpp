#include "characterSpace.h"

characterSpace::characterSpace(){
    for(int i=0; i<equipmentCount; i++){
        switch(i){
            case 0: equipmentAll[i]=&equipmentHandRight; equipmentAll[i]->typeName="weapon";    equipmentAll[i]->x=0; equipmentAll[i]->y=0; break;
            case 1: equipmentAll[i]=&equipmentHead;      equipmentAll[i]->typeName="armorHead"; equipmentAll[i]->x=1; equipmentAll[i]->y=0; break;
            case 2: equipmentAll[i]=&equipmentNeck;      equipmentAll[i]->typeName="armorNeck"; equipmentAll[i]->x=0; equipmentAll[i]->y=1; break;
            case 3: equipmentAll[i]=&equipmentBody;      equipmentAll[i]->typeName="armorBody"; equipmentAll[i]->x=1; equipmentAll[i]->y=1; break;
            case 4: equipmentAll[i]=&equipmentLegs;      equipmentAll[i]->typeName="armorLegs"; equipmentAll[i]->x=1; equipmentAll[i]->y=2; break;
            case 5: equipmentAll[i]=&equipmentHandLeft;  equipmentAll[i]->typeName="weapon2";   equipmentAll[i]->x=2; equipmentAll[i]->y=2; break;
            case 6: equipmentAll[i]=&equipmentFeet;      equipmentAll[i]->typeName="armorFeet"; equipmentAll[i]->x=1; equipmentAll[i]->y=3; break;
        }
    }
}
