#include <vector>
using namespace std;


class gameFloor {
    private:
        int floorLevel;
        //This vector will hold the floor setup(Which steps will have random encounters)
        vector<int>floorSetup;
        //Current position of the player
        int currentPos;
        //How many steps per level there are
        int totalPos = 25;
        //Need to create:
        //Fl1: 2 weak enemies, 1 random event
        //Fl2: 3 weak enemies, 2 rand events
        //FL3: 2 Strong enemies, 2 rand events
        //Fl4: 4 strong enmies, 3 rand events
        //Index refers to the floor number 
        //Storage format: {enemies, rand events}
        int floorSettings[4][4] = {{5, 6},
                                    {7, 5},
                                    {8, 2},
                                    {3,1}};

    public:
        //Default constructor
        //Accepts floor level as an input, sets up and creates the floor.
        //Handles random encounter generation
        gameFloor(int inpLevel, int pos);
        //The user takes a step.
        void takeStep();
        //Will return the current players position 
        int getCurrentPos();
        //Will return the total positions possible in a floor level
        int getTotalPos();
        //Will return the random occurance (If any) set to occur
        int getRandomEvent();
};