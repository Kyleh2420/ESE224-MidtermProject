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
	scoreboard p1Scoreboard;
	fileOperations files;

	
    //The following will loop through the player's starting options 
	char selection;
    bool loop = true;
    while (loop) {
			cout << "Would you like to create a new file or load a save file? "
				<< "\nN - Create a new save file \nL - Load a save file \nYour answer: ";
			cin >> selection;
			selection = tolower(selection);
			switch(selection) {
				case 'l':	//Ask user for save name. IDK what file type(prob .dat, right?) we are saving in but could we concatenate the file type extension to the user input?
					loop = false;
					break;
				case 'n':
					cout << "Please enter a save file name: ";
					files.setPName(cin);
					cout << "Please enter a scoreboard file name:";
					p1Scoreboard.setName(cin);
					cout << "Please enter your player name: ";
					//Default values
					p1.setName(cin);
					while (loop) {
						cout << "Please enter your difficulty level\nE - easy\nM - Medium\nH - Hard\nYour selection: ";
						cin >> selection;
						selection = tolower(selection);
						switch(selection){
							case 'e':
								cout << "Difficulty set to easy" << endl;
								p1Scoreboard.setDiff("Easy");
								loop = false;
								break;
							case 'm':
								cout << "Difficulty set to medium" << endl;
								p1Scoreboard.setDiff("Medium");
								loop = false;
								break;
							case 'h':
								cout << "Difficulty set to hard" << endl;
								p1Scoreboard.setDiff("Hard");
								loop = false;
								break;
							default:
								cout << "Please enter a valid response" << endl;
								break;
						}
					}
					files.save2File(p1);
					files.save2File(p1Scoreboard);
					break;
				default:
					cout << "Please enter a valid response" << endl;
			}
    }
	cout << "Now entering Game Portion";



	//Game Portion of the code



	enemy Alex("Alex", 30, 30, 5, 1);
	cout << Alex << endl;
	weapon sword;

}
