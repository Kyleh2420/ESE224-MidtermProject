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
    input.sbOut();
    closeFile();
}

void fileOperations::chooseFile(scoreboard& s, player& p) {

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