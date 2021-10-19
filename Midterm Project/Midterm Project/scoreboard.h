#include <iostream>
#include <string.h>

using namespace std;

class scoreboard {
    private:
        //Name of player
        string sbName;
        //Score of the player. Score should increase after the player defeats an enemy or through some custom meathod designed by you
        //Note: Higher level enemies should give more points
        int sbScore;
        string sbDifficulty;
        //Difficulty of the game
        int sbDifficultyMod;
        //Keeps track of the area in the game wich the player is at 
        int sbFloor;

    public:
        //Default constructor
        scoreboard();
        
        //Setters!
        void setName(string input);
        void setScore(int input);
        void setDiff(string input);
        void setDiffMod(int input);
        void setFloor(int input);

        //Getters!
        string getName();
        int getScore();
        string getDiff();
        int getDiffMod();
        int getFloor();

        void addScore(int);

        //Print scoreboard
        void sbOut();

        friend ostream& operator <<(ostream& os, const scoreboard& p);
};