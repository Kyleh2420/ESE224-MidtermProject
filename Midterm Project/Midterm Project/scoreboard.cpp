#include "scoreboard.h"

scoreboard::scoreboard() {
    sbScore = 0;
    sbDifficulty = 1;
    sbFloor = 0;
    sbPos = 0;
}

void scoreboard::setScore(int input) {
    sbScore = input;
}
void scoreboard::setDiff(int input) {
    sbDifficulty = input;
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
int scoreboard::getDiff() {
    return sbDifficulty;
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

ostream& operator <<(ostream& os, const scoreboard& s) {
    string tmp;
    switch (s.sbDifficulty) {
        case 1:
            tmp = "Easy";
            break;
        case 2:
            tmp = "Medium";
            break;
        case 3:
            tmp = "Hard";
            break;
        default:
            tmp = "I don't know what this difficulty is";

    }
    os << "\nCurrent Score: " << s.sbScore << "\nCurrent Difficulty: " << s.sbDifficulty
    << "\nFloor Level: " << s.sbFloor << "\nPosition: " << s.sbPos;
    return os;
}