#include "floor.h"
#include "scoreboard.h"
#include <iostream>
#include <algorithm> //For the std::shuffle
#include <random> //For std::default_random_engine
#include <chrono> //For std::chrono::system_clock
using namespace std;


gameFloor::gameFloor(int inpLevel, int pos) {
    floorLevel = inpLevel;
    currentPos = pos;
    //The following for loop fills the vector floorSetup with the
    //number of random events using the floor settings.
    for (int i = 0; i < totalPos; i++) {
        //As long as the floorLevel is valid, we can read the settings
        if (floorLevel < 4) {
            //If i is less than the number of enemies that must be created, create the enemy (aka pushback 1 to the vector)
            if (i < floorSettings[floorLevel][0]) {
                floorSetup.push_back(1);
                //If i is less than the # of enemies + the number of random encounters, create the random encounter (aka pushback 0 to the vector)
            }
            else if (i < floorSettings[floorLevel][1] + floorSettings[floorLevel][0]) {
                floorSetup.push_back(2);
                //If it is neither an enemy encounter, nor a random encounter, pushback 0 (Our "Do nothing")
            }
            else {
                floorSetup.push_back(0);
            }
        }
        else if (floorLevel > 4) { //That floor doesn't exist
            cerr << "Floor level has passed limit!" << endl;
            exit(1);
        }
    }
    //Output for testing
    // for (int i = 0; i < floorSetup.size(); i++) {
    //     cout << floorSetup[i] << endl;
    // }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(floorSetup.begin(), floorSetup.end(), default_random_engine(seed));
    //floorSetup.push_back(3);
    for (int i = 0; i < floorSetup.size(); i++) {
        cout << floorSetup[i] << endl;
    }
}

void gameFloor::takeStep() {
    cout << "You take a step." << endl;
    currentPos++;
}

int gameFloor::getCurrentPos() {
    return currentPos;
}

int gameFloor::getTotalPos() {
    return totalPos;
}
int gameFloor::getRandomEvent() {
    return floorSetup[currentPos];
}