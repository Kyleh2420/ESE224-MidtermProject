#include <vector>
using namespace std;

class floor {
    private:
        int floorLevel;
        //This vector will hold the floor setup(Which steps will have random encounters)
        vector<int>floorSetup;
        int currentPos = 0;
        //Need to create:
        //Fl1: 2 weak enemies, 1 random event
        //Fl2: 3 weak enemies, 2 rand events
        //FL3: 2 Strong enemies, 2 rand events
        //Fl4: 4 strong enmies, 3 rand events
        //Index refers to the floor number 
        //Storage format: {enemies, rand events}
        int floorSettings[4][4] = {{2, 1},
                                    {3, 2},
                                    {2, 2},
                                    {4,3}};

    public:
        //Default constructor
        //Accepts floor level as an input, sets up and creates the floor.
        //Handles random encounters
        floor(int lvl);
        //The user takes a step.
        //The 
        void takeStep();
};