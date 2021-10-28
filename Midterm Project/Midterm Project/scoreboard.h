#include <iostream>
#include <string.h>
using namespace std;

class scoreboard {
    private:
        //Score of the player. Score should increase after the player defeats an enemy or through some custom meathod designed by you
        //Note: Higher level enemies should give more points
        int sbScore;
        int sbDifficulty;
        //Difficulty of the game
        int sbDifficultyMod;
        //Keeps track of the area in the game wich the player is at 
        int sbFloor;
        //Keeps track of what position on the floor the player is at
        int sbPos;

    public:
        //Default constructor
        scoreboard();
        
        //Setters!
        void setScore(int input);
        void setDiff(int input);
        void setDiffMod(int input);
        void setFloor(int input);
        void setPos(int input);

        //Getters!
        int getScore();
        int getDiff();
        int getDiffMod();
        int getFloor();
        int getPos();

        void addScore(int input);

        //Print scoreboard
        void sbOut();

        friend ostream& operator <<(ostream& os, const scoreboard& s);
};