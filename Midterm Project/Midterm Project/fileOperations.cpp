#include "fileOperations.h"
#include <vector>
using namespace std;

//This class will handle the opening, saving, and closing of the player file.
void fileOperations::save2File(player& input) {
    pmyFile.open(pFileName, ios::out);
    if (pmyFile.fail()) {
        cerr << "Error saving the file! Please try again1!" << endl;
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
    sb_myFile.open(sbFileName, ios::out);
    if (sb_myFile.fail()) {
        cerr << "Error saving the file! Please try again2!" << endl;
        exit(1);
    }
    sb_myFile   << input.getScore() << "\n"
                << input.getDiff() << "\n"
                << input.getFloor() << "\n"
                << input.getPos() << endl;
    closeFile();
}

void fileOperations::save2File(scoreboard& input, player& pl) {
    gsb_myFile.open(gsbFileName, std::ios_base::app);
    if (gsb_myFile.fail()) {
        cerr << "Error saving the file! Please try again3!" << endl;
        exit(1);
    }
    gsb_myFile << "Name: " << setw(16) << left << pl.getName()
        << "Score: " << setw(10) << left << input.getScore() << "\n";
    
    closeFile();

    //Sort the file
    gsb_myFile.open(gsbFileName, ios::in);
    if (gsb_myFile.fail()) {
        cerr << "Error saving the file! Please try again4!" << endl;
        exit(1);
    }
    vector<string> names;
    vector<string> scores;
    while (gsb_myFile) {
        string label;
        string name;
        string score;
       
        gsb_myFile >> label;
        if (gsb_myFile.eof())
            break;
        gsb_myFile >> name;
        names.push_back(name);
        gsb_myFile >> label;
        gsb_myFile >> score;
        scores.push_back(score);
    }

    for (int i = 0; i < names.size()-1; i++) {
        for (int j = i+1; j < names.size(); j++) {
            if (scores[j] > scores[i]) {
                string stemp;
                string ntemp;
                stemp = scores[j];
                scores[j] = scores[i];
                scores[i] = stemp;

                ntemp = names[j];
                names[j] = names[i];
                names[i] = ntemp;
            }
        }
    }
    closeFile();

    //Write sorted scores back to file
    gsb_myFile.open(gsbFileName, ios::out);
    if (gsb_myFile.fail()) {
        cerr << "Error saving the file! Please try again5!" << endl;
        exit(1);
    }
    for (int i = 0; i < names.size(); i++) {
        gsb_myFile << "Name: " << setw(16) << left << names[i]
            << "Score: " << setw(10) << left << scores[i] << endl;
    }
    closeFile();
}

vector<string> fileOperations::getNames(scoreboard& input, player& pl) {
    gsb_myFile.open(gsbFileName, ios::in);
    if (gsb_myFile.fail()) {
        cerr << "Error saving the file! Please try again4!" << endl;
        exit(1);
    }
    vector<string> names;
    while (gsb_myFile) {
        string label;
        string name;
        string score;

        gsb_myFile >> label;
        if (gsb_myFile.eof())
            break;
        gsb_myFile >> name;
        names.push_back(name);
        gsb_myFile >> label;
        gsb_myFile >> score;
    }
   closeFile();
   return names;
}

vector<string> fileOperations::getScores(scoreboard& input, player& pl) {
    gsb_myFile.open(gsbFileName, ios::in);
    if (gsb_myFile.fail()) {
        cerr << "Error saving the file! Please try again4!" << endl;
        exit(1);
    }
    vector<string> scores;
    while (gsb_myFile) {
        string label;
        string name;
        string score;

        gsb_myFile >> label;
        if (gsb_myFile.eof())
            break;
        gsb_myFile >> name;
        gsb_myFile >> label;
        gsb_myFile >> score;
        scores.push_back(score);
    }
    closeFile();
    return scores;
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
    gsb_myFile.close();
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