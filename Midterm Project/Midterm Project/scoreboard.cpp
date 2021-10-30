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
    string tmp;
    switch (sbScore) {
    case 1: tmp = " brain"; break;
    case 2: tmp = " heart"; break;
    case 3: tmp = " liver"; break;
    case 4: tmp = " pancreas"; break;
    case 6: tmp = " kidney"; break;
    case 8: tmp = " part of the small intestine"; break;
    case 5: tmp = " kidney"; break;
    case 7: tmp = " bottle of blood. This will be useful later"; break;
    case 9: tmp = " part of the large intestine"; break;
    case 10: tmp = " lung"; break;
    case 11: tmp = " gallbladder"; break;
    case 12: tmp = " bladder"; break;
    case 13: tmp = " spleen"; break;
    case 14: tmp = " tongue"; break;
    case 15: tmp = " piece of skin. You hope its big enough for yourself"; break;
    case 16: tmp = " singular eyeball"; break;
    case 17: tmp = "n eardrum"; break;
    case 18: tmp = " half of a nostril"; break;
    case 19: tmp = " singular hair folicle. You hope you're not bald again!"; break;
    default: tmp = " singular muscle fiber"; break;
    }
    cout << "You collected a" << tmp << endl;
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