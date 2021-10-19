#include "scoreboard.h"

scoreboard::scoreboard() {
    sbName = "";
    sbScore = 0;
    sbDifficulty = "";
    sbDifficultyMod = 0;
    sbFloor = 0;
}
void scoreboard::setName(string input) {
    sbName = input;

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

string scoreboard::getName() {
    return sbName;
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