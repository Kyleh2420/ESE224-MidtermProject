#include "enemy.h"
#include "fileOperations.h"
#include "Weapon.h"
//player.h and scoreboard.h don't need to be called, since they are already called in fileOperations.h
//If called again, it will result in a redefinition error
using namespace std;

void playerCombat(player&, weapon[4][4], enemy&, scoreboard&) {

}

bool enemyCombat(enemy&, player&, scoreboard&) {
	return false;
}

void playerOptions(player&, fileOperations&, scoreboard&) {

}

void chooseWeapon(weapon[4][4], int, player&) {

}

int main() {
	player p1;
	fileOperations files;

	
    //The following will loop through the player's save options 
	char selection;
    bool loop = true;
        while (loop) {
			cout << "Would you like to create a new file or load a save file? "
				<< "\nN - Create a new save file \nL - Load a save file \nYour answer: ";
			cin >> selection;
			selection = tolower(selection);
			switch(selection) {
				case 'l':
					loop = false;
					break;
				case 'n':
					cout << "Please enter a save file name: ";
					files.setPName(cin);
					cout << "Please enter your player name: ";
					//Default values
					p1.setName(cin);
					files.save2File(p1);
					loop = false;
					break;
				default:
					cout << "Please enter a valid response" << endl;
			}
    }
	cout << "Now entering Game Portion";
	//For some reason, when running the above, we won't be able to save any files, no matter what.
	//I personally am confused as to why we can't open files.
	//Error originates from fileOperations.h. pmyFile.open(fileName).




	enemy Alex("Alex", 30, 30, 5, 1);
	cout << Alex << endl;
	weapon sword;
	scoreboard test;

}
