#include <iostream>
#include <string.h>

using namespace std;

class scoreboard {
    private:
        string sbName;
        int sbScore;
        string sbDifficulty;
        int sbDifficultyMod;
        int sbFloor;

    public:
        scoreboard();
        void setName(string);
        void setScore(int);
        void setDiff(string d);
        void setDiffMod(int);
        void setFloor(int);

        string getName();
        int getScore();
        string getDiff();
        int getDiffMod();
        int getFloor();

        void addScore(int);

        void sbOut();

        friend ostream& operator <<(ostream& os, const scoreboard& p);
};