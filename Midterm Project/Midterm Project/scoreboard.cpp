#include "scoreboard.h"

scoreboard::scoreboard() {
    sbScore = 0;
    sbDifficulty = "";
    sbDifficultyMod = 0;
    sbFloor = 0;
}

void scoreboard::setScore(int input) {
    sbScore = input;
}
void scoreboard::setDiff(string input) {
    sbDifficulty = input;
}
void scoreboard::setDiffMod(int input) {
    sbDifficultyMod = input;
}
void scoreboard::setFloor(int input) {
    sbFloor = input;
}

int scoreboard::getScore() {
    return sbScore;
}
string scoreboard::getDiff() {
    return sbDifficulty;
}
int scoreboard::getDiffMod() {
    return sbDifficultyMod;
}
int scoreboard::getFloor() {
    return sbFloor;
}

void scoreboard::addScore(int input) {
    sbScore += input;
}

void scoreboard::sbOut() {
    cout << "Score: " << sbScore
        << "\nsbDifficulty: " << sbDifficulty
        << "\nFloor: " << sbFloor << endl;
}

ostream& operator <<(ostream& os, const scoreboard& p) {
    return os;
}