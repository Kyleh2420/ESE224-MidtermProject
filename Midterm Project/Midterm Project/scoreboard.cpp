#include "scoreboard.h"

scoreboard::scoreboard() {
    sbScore = 0;
    sbDifficulty = "";
    sbDifficultyMod = 0;
    sbFloor = 0;
    sbPos = 0;
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
void scoreboard::setPos(int input) {
    sbPos = input;
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
int scoreboard::getPos() {
    return sbPos;
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