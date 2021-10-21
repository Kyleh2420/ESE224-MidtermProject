#include "enemy.h"
#include "fileOperations.h"
#include "Weapon.h"
#include "floor.h"
//player.h and scoreboard.h don't need to be called, since they are already called in fileOperations.h
//If called again, it will result in a redefinition error
using namespace std;

//The player will have 4 options
//1. Examine themselves (Return HP/MaxHP, damage, and name)
//	1a. Change weapon (Only in the beginning of the encounter) [At least that's what I want it to be]
//2. Examine the enemy (Return Name, HP/Max HP, damage)
//3. Attack 
//4. Run Away
void playerCombat(player&, weapon[4][4], enemy&, scoreboard&) {

}

//The enemy will attack.
//Decrease player's HP according to enemy's level and AD
//Check if player is dead
bool enemyCombat(enemy&, player&, scoreboard&) {
	return false;
}

//This function is essentially a pause menu. The player has the following options:
//1. Examine themselves
//2. See the scorboard
//3. Save and Quit
void playerOptions(player& p1, fileOperations& files, scoreboard& p1Scoreboard) {
}

//Changes weapon
void chooseWeapon(weapon[4][4], int, player&) {

}

int main() {
	player p1;
	scoreboard p1Scoreboard;
	fileOperations files;

    //The following will loop through the player's starting options 
	//The User will select whether or not a new file is created or loaded.
	//If a new file is created, it will Ask for the players name and difficulty, then save those to 
	//player p1 and scoreboard p1Scoreboard, respectively. It will then jump to
	//playerOptions (The glorified pause menu) for file saving
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
					cout << "Please enter your player name: ";
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


	p1Scoreboard.setFloor(1);
	//Game Portion of the code
	gameFloor test(p1Scoreboard.getFloor());

	enemy Alex("Alex", 30, 30, 5, 1);
	cout << Alex << endl;
	weapon sword;

}
