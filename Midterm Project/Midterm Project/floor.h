#include <vector>
using namespace std;

class floor {
    private:
        int floorLevel;
        //This vector will hold the floor setup(Which steps will have random encounters)
        vector<int>floorSetup;
        int currentPos = 0;
        int difficulties[3];

    public:
        //Default constructor
        //Accepts floor level as an input, sets up and creates the floor.
        //Handles random encounters
        floor(int lvl);
        //The user takes a step.
        //The 
        void takeStep();
};