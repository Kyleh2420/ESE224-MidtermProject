#include "floor.h"
using namespace std;


floor::floor(int lvl) {
    floorLevel = lvl;
    //The following for loop fills the vector floorSetup with the
    //number of random events using the floor settings.
    for (int i = 0; i < 25, i++) {
        switch (floorLevel) {
            case 0: //1st Floor
                break;
            case 1: //2nd Floor
                break;
            case 2: //3rd Floor
                break;
            case 3: //4th Floor
                break;
            default:
                floorLevel = 0;
        }
    }


}


void floor::takeStep() {
    currentPos++;
}