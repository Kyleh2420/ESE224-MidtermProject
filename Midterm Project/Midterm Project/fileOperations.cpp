#include "fileOperations.h"
#include <vector>
using namespace std;

//This class will handle the opening, saving, and closing of the player file.
void fileOperations::save2File(player& input) {
    pmyFile.open(pFileName, ios::out);
    if (pmyFile.fail()) {
        cerr << "Error saving the file! Please try again!" << endl;
        exit(1);
    }
    pmyFile << input.getName() << "\n"
            << input.getWeapon() << "\n"
            << input.getMaxHP() << "\n"
            << input.getHP() << "\n"
            << input.getDMG() << "\n"
            << input.getBal() << endl;
    closeFile();

}
void fileOperations::save2File(scoreboard& input) {
    cout << "Testing124";
    sb_myFile.open(sbFileName, ios::out);
    if (sb_myFile.fail()) {
        cerr << "Error saving the file! Please try again!" << endl;
        exit(1);
    }
    sb_myFile   << input.getScore() << "\n"
                << input.getDiff() << "\n"
                << input.getFloor() << "\n"
                << input.getPos() << endl;
    closeFile();
}

void fileOperations::chooseFile(scoreboard& s, player& p) {
    string inputString = "";
    int inputInt = 0;
    pmyFile.open(pFileName, ios::in);
    if (pmyFile.fail()) {
        cerr << "Error opening the player file!" << endl;
        exit(1);
    }
    getline(pmyFile, inputString);
    //pmyFile >> inputString;
    p.setName(inputString);
    getline(pmyFile, inputString);
    p.setWeapon(inputString);
    pmyFile >> inputInt;
    p.setMaxHP(inputInt);
    pmyFile >> inputInt;
    p.setHP(inputInt);
    //pmyFile >> inputString;
    pmyFile >> inputInt;
    p.setDMG(inputInt);
    pmyFile >> inputInt;
    p.setBal(inputInt);


    sb_myFile.open(sbFileName, ios::in);
    if (sb_myFile.fail()) {
        cerr << "Error opening the player file!" << endl;
        exit(1);
    }
    sb_myFile >> inputInt;
    s.setScore(inputInt);
    sb_myFile >> inputInt;
    s.setDiff(inputInt);
    sb_myFile >> inputInt;
    s.setFloor(inputInt);
    sb_myFile >> inputInt;
    s.setPos(inputInt);
 
    closeFile();
}
void fileOperations::closeFile() {
    sb_myFile.close();
    pmyFile.close();
}
void fileOperations::scoreRank() {

}

//Accepts cin as the arguement and sets the player savefile name
void fileOperations::setPName(istream& in) {
    in >> pFileName;
    sbFileName = pFileName + sbFileName;
    pFileName += ".txt";
    cout << pFileName << "\t" << sbFileName << endl;
}