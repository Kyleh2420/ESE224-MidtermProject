#include "enemy.h"
#include "fileOperations.h"
#include "Weapon.h"
#include "floor.h"
#include "randomEvents.h"
#include "randomComment.h"
#include <string>
#include <vector>
#include <iomanip>
//player.h and scoreboard.h don't need to be called, since they are already called in fileOperations.h
//If called again, it will result in a redefinition error
using namespace std;


//Here, the user will be able to spend their coins on getting upgraded weapons.
//This code uses a vector with the class Weapon to store all the information read from the file
void weaponsShop(player& p1) {
	//Every time we enter the weapons shop, take a look through the file as to what is available
	//THis allows for the possiblity of a new weapon's shop on every floor.
	//Thus, it is highly possible that an item that can be brought at a lower level (With more money than is available)
	//is more op than one brought at a later leve. Kinda reminds me of SAO
	vector<weapon> weaponsList;
	fstream weaponFile;
	string weaponFileName = "weaponsList.txt", item;
	int cost, dmg, selection;
	int maxHP, HP;
	bool loop = true;
	char acknowledge;
	//Open the file, reset back to hand if file cannot be opened.
	weaponFile.open(weaponFileName);
	if (weaponFile.fail()) {
		cerr << "We couldn't open the weapons file. You'll have to stick with your fist" << endl;
		p1.setWeapon("Hand");
		p1.setDMG(2);
		return;
	}

//Take in the weapon choices from the file to a vector
	//Format is
	//Damage, cost, string.
	while (!weaponFile.eof()) {
		weaponFile >> cost >> dmg >> maxHP >> HP;
		weaponFile.seekg(1, std::ios_base::cur);
		getline(weaponFile, item);
		weaponsList.push_back(weapon(item, dmg, cost, maxHP, HP));
	}

//This starts the buying process from the user.
	while (loop) {
		cout << "Your options:" << endl;
		cout <<setw(8) << right << "Cost"
			<<setw(11) << right << "Effect"
			<<setw(10) << right << "Item" << endl;
		//Loop through the whole vector, display all the options to the user. Then, have the user make a selection
		for (int i = 0; i < weaponsList.size(); i++) {
			//The following is a weapon;
			if (weaponsList[i].getDMG() != 0) {
				cout << i + 1 << ". "
					<< setw(3) << right << weaponsList[i].getCost()
					<< setw(9) << right << weaponsList[i].getDMG() << " Dmg   "
					<< left << weaponsList[i].getItem() << endl;
			//The following is a potion. 
			} else {
				cout << i + 1 << ". "
					<< setw(3) << right << weaponsList[i].getCost()
					<< setw(15) << right << "Unknown   "
					<< left << weaponsList[i].getItem() << endl;
			}
		}
		cout << "You currently have " << p1.getBal() << "coins" << endl;
		cout << "Enter 0 to exit the buying process. Please enter your selection: ";
		cin >> selection;
//If the user's selection is 0, then we know to exit the loop
		if (selection == 0) {
			loop = false;
//Otherwise, let's check if the user can actually buy the item. If they can, then prompt them to ensure their purchase is correct
		} else if (weaponsList[selection-1].getCost() > p1.getBal()) {
			cout << "Sorry, you can't afford " << weaponsList[selection-1].getItem() << endl;
		} else {
			cout << "Ready to purchase " << weaponsList[selection-1].getItem() << "? Your new balance will be: " << p1.getBal() - weaponsList[selection-1].getCost() << ". Enter Y/N: ";
			cin >> acknowledge;
			acknowledge = tolower(acknowledge);
			//The user has acknowledge that the purchase is valid. Change the player damage, and change the player's weapon name 
			//Also modify the user's balance
			if (acknowledge == 'y') {
				//If the object is a pottion (i.e. If damage incurred is 0)
				if (weaponsList[selection-1].getDMG() == 0) {
					p1.modHealth(weaponsList[selection-1].getHP());
					p1.modMaxHP(weaponsList[selection-1].getMaxHP());
				} else {
					p1.setDMG(weaponsList[selection-1].getDMG());
					p1.setWeapon(weaponsList[selection-1].getItem());
				}
				p1.modBal(-weaponsList[selection-1].getCost());
				cout << "You've brought " << weaponsList[selection-1].getItem() << "!" << endl;
				loop = false;
			} else {
				cout << "Alright, we won't make that purchase." << endl;
			}

		}
	}



	
}

//The enemy will attack.
//Decrease player's HP according to enemy's level and AD
//Check if player is dead
bool enemyCombat(enemy& e1, player& p1, scoreboard& p1Scoreboard) {
	cout << "The enemy attacked you. " << -e1.getDMG()*e1.getLvl() << " HP." << endl;
	p1.modHealth(-e1.getDMG() * e1.getLvl());
	//If the user has died, then return false
	if (p1.getHP() <= 0) {
		return false;
	}
	else {
		//The user is not dead yet. Keep the battle going
		return true;
	}
}


//The player will have 4 options
//1. Examine themselves (Return HP/MaxHP, damage, and name)
//	1a. Change weapon (Only in the beginning of the encounter) [At least that's what I want it to be]
//2. Examine the enemy (Return Name, HP/Max HP, damage)
//3. Attack 
//4. Run Away
//Enter Combat. WIll only exit when one of the following conditions are met:
//1. The player Runs away
//2. The player runs out of HP
//3. The enemy runs out of hp
void playerCombat(player& p1, enemy& e1, scoreboard& p1Scoreboard) {
	bool loop = true;
	char selection;
	cout << "\n-----------------\nEntering combat with " << e1 << endl;
	cout << "Your stats: \n" << p1 << endl;
	while (loop) {
		cout << "Please make a selection" 
		<< "\n1 - Examine yourself"
		<< "\n2 - Examine the enemy"
		<< "\n3 - Attack"
		<< "\n4 - Run Away"
		<< "\nYour selection: ";
		cin >> selection;
		switch (selection) {
			case '1':
				cout << "\nExamine Yourself. Your stats: \n--------------" << p1 << endl;
				break;
			case '2': 
				cout << "\nExamine the enemy. " << e1.getName() << "'s stats: \n-----------------\n" << e1 << endl;
				break;
			case '3':
			//The player attacks the enemy.
				cout << "Attack" << endl;
				//Since we are adding coins ad scores according to the damage that the player does,
				//We need an ifstatement to see if the damage that the player does is way above the enemys HP.
				//If it is, then only add the rest of the player's HP and kill the enemy
				if (e1.getHP() <= p1.getDMG()) {
					p1.modBal(e1.getHP());
					p1Scoreboard.addScore(1);
					cout << "The enemy has died!"
						<< "\nYou have earned " << e1.getMaxHP() << " coins." << endl;
					loop = false;
				} else {
					p1.modBal(p1.getDMG());
					cout << "You attacked the enemy, -" << p1.getDMG() << endl;
					loop = enemyCombat(e1, p1, p1Scoreboard);
				}
				e1.modHealth(-p1.getDMG());
				break;
			case '4': 
				cout << "Run Away." << endl;
				loop = false;
				break;
			default:
				cout << "That wasn't a selection! Please try again!" << endl;
		}
	}
	
}



//This function is essentially a pause menu. The player has the following options:
//1. Examine themselves
//2. See the scorboard
//3. Save and Quit
void playerOptions(player& p1, fileOperations& files, scoreboard& p1Scoreboard) {
	char selection;
	bool loop = true;
	while (loop) {
		cout << "Pause menu\n---------------\n"
			<< "Please enter a number\n"
			<< "1 - Examine Yourself\n"
			<< "2 - See the Scoreboard\n"
			<< "3 - Enter the shop\n"
			<< "4 - Exit the menu\n"
			<< "5 - Save and quit\nYour selection: ";
		cin >> selection;
		switch (selection) {
		case '1':
			cout << "\nYou selected 'Examine Yourself'" << endl;
			cout << p1 << endl;
			loop = false;
			break;
		case '2':
			cout << "\nYou selected 'See the scoreboard'" << endl;
			cout << p1Scoreboard << endl;
			loop = false;
			break;
		case '3':
			cout << "\nYou selected 'Enter the shop'" << endl;
			loop = false;
			weaponsShop(p1);
			break;
		case '4':
			cout << "\nYou selected 'Exit the menu'" << endl;
			loop = false;
			break;
		case '5':
			cout << "\nYou selected 'Save and Quit'" << endl;
			files.save2File(p1);
			files.save2File(p1Scoreboard);
			files.closeFile();
			exit (0);
			loop = false;
			break;
		default:
			cout << "That wasn't an option!" << endl;
		}
	}
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
	string entry;
    bool loop = true;
    while (loop) {
			cout << "Would you like to create a new file or load a save file? "
				<< "\nN - Create a new save file \nL - Load a save file \nYour answer: ";
			cin >> selection;
			selection = tolower(selection); //Lowercase everything to limit the number of cases
			switch(selection) {
				case 'l':
					cout << "Please enter the savefile name: ";
					files.setPName(cin);
					files.chooseFile(p1Scoreboard, p1);

					loop = false;
					break;
				case 'n': //New File is to be created. We must gather information about the user.
					cout << "Please enter your player name: ";
					cin.ignore();
					std::getline(cin, entry);
					p1.setName(entry);
					/*
					while (loop) {
						cout << "Please enter your difficulty level\n1 - easy\n2 - Medium\n3 - Hard\nYour selection: ";
						cin >> selection;
						selection = tolower(selection);
						switch(selection){
							case '1':
								cout << "Difficulty set to easy" << endl;
								p1Scoreboard.setDiff(1);
								loop = false;
								break;
							case '2':
								cout << "Difficulty set to medium" << endl;
								p1Scoreboard.setDiff(2);
								loop = false;
								break;
							case '3':
								cout << "Difficulty set to hard" << endl;
								p1Scoreboard.setDiff(3);
								loop = false;
								break;
							default:
								cout << "Please enter a valid response" << endl;
								break;
						}
					}
					*/
					loop = false;
					p1Scoreboard.setFloor(0);
					p1Scoreboard.setPos(0);
					cout << "Please enter a save file name: ";
					files.setPName(cin);
					//cout << "Please enter a scoreboard file name with a .txt extention: ";
					//p1Scoreboard.setName(cin);
					files.save2File(p1);
					files.save2File(p1Scoreboard);
				break;
				default:
					cout << "Please enter a valid response" << endl;
			}
    }
	//cout << "Now entering Game Portion";
	//We clear the screen
	cout << "\033[2J\033[1;1H";
	//Storytime!
	cout << "You are a skeleton who has been condemned to the depths of hell."
		<< "\nHowever, hell just isn't to your satisfaction, so you're escaping back to earth."
		<< "\nExplore the path, defeat enemies, collect organs, and set yourself up to become a real person again."
		<<"\nSucceed, and live a life of comfort back on earth."
		<<"\nFail, and become an unsuccessful ghost, forever stuck in the land of inbetween, neither satisfied on hell or reborn on earth."
		<< endl;
	loop = true;
	//While we are in the game
	//Each floor is a repeat with different probabilities, therefore this code reuses the same thing for every floor
	///THIS IS THE MAIN GAME LOOP
	//Each time this loop is run, we construct different objects depending on what we read from p1Scoreboard
	
	while (loop) {
		//Creates a new class playGame with the current floor
		gameFloor playGame(p1Scoreboard.getFloor(), p1Scoreboard.getPos());
		//Opens a file for the randomEvents that may occur (With tile 2)
		randomEvents event(p1Scoreboard.getFloor());
		//Opens the randomComments file
		randomComment quirkyComment(p1Scoreboard.getFloor());
		//Primes the random event selector with the selector
		cout << "The current floor is: " << p1Scoreboard.getFloor() << endl;
		//We stay in this while loop as long as the usre has not reached the maximum position 
		//Anotherwards, repeat the following loop until we run out of positions to advance to
		while (playGame.getCurrentPos() < playGame.getTotalPos()-1) {
			//User Input. Gets whether the user would like to take a step or pause
			cout << "\nThe current position is " << playGame.getCurrentPos() << "/" << playGame.getTotalPos() << endl;
			cout << "Press [t] to take a step, or press [m] to access menu options. \nYou entered: ";
			cin >> selection;
			selection = tolower(selection);
			switch(selection) {
				case 't': //The user takes a step
					playGame.takeStep();
					//Now that the user has taken a step, we need to see what tile the user has landed on. Use playGame.getRandomEvent to see the tile
					//After the user takes a step, we need to see if a random encounter has occurred
					//Depending on what tile the user lands on, we must respond differently
					//As a reminder:
					//0 - Do Nothing
					//1 - Enter combat
					//2 - Random Event
					//Default: Something wrong occurred. Treat this as a do nothing 
					 switch(playGame.getRandomEvent()) {
					 	case 1: {
						 	cout << "You encounter an enemy" << endl;
					// 		//The following function requires weapons and an enemy to fight against
					// 		//My goal is to have the enemy randomly generated out of a file, according to 
					// 		//a preset list. 
					// 		//Ex: Fl1Enemies.txt and Fl1Weapons.txt both contain info about what is available on each floor	
							enemy e1(p1Scoreboard.getFloor());
					 		playerCombat(p1, e1, p1Scoreboard);
					 		break;
						}//These brackets are here to ger around the 
						 //"Transfer of control bypasses intitalization of variable e1"
						 //This error is caused by the case not being in it's own scope, which is solved with {}
					 	case 2:
						 	//cout << "A random event occurs" << endl;
							//The following gets a random event out of the file according to the floor
							//Generates a random line out of the list
							event.getRandom();
							cout << event.getEvent() << endl;
							//The following is user interface
							if (event.getHPChange() != 0)
								(event.getHPChange() < 0) ? cout << "You have lost " << event.getHPChange() << "Hp" << endl : cout << "You have gained " << event.getHPChange() << "Hp" << endl;
							if (event.getBalChange() != 0)
								(event.getBalChange() < 0) ? cout << "You have lost " << event.getBalChange() << "coins" << endl : cout << "You have gained " << event.getBalChange() << "coins" << endl;
							break;
							//The following affects the users stats
							//The user cannot die from a random event. Thus, if the HP change read is negative 
							//And is not greater 
							if ((event.getHPChange() >= 0) || (event.getHPChange() < 0 && !(abs(event.getHPChange()) > p1.getHP()))) {
								loop = p1.modHealth(event.getHPChange());
							} else {
								p1.setHP(1);
							}
							//The following will check if the user has died or not, and exit the floor
							if (!loop) {
								break;
							}
							p1.modBal(event.getBalChange());
							
					 	case 0:
					 	default:
					// 		//QuIrKy comments need to be read from a file as well
					 		//cout << "Quirky comment here" << endl;
							quirkyComment.getRandom();
							cout << quirkyComment.getEvent() << endl;
					// 		break;
					}
					break;
				case 'm': //The user access a pause menu
					p1Scoreboard.setPos(playGame.getCurrentPos());
					playerOptions(p1, files, p1Scoreboard);
					break;
				default:
					cout << "That wasn't a valid option, please try again.";
			}

		}
		//Once we exit the above loop, we know that the user has completed the floor (Has advanced as far as they can on the floor)
		//Or the user has died, and we just exited the loop. Check p1.health's status to determine which one
		
		//user has died
		if (p1.getHP() <= 0) {
			cout << "We're sorry that the game is over for you. You're more than able go and restart it!" << endl;
		}
		else {
			//Increases the floor count by 1
			p1Scoreboard.setFloor(p1Scoreboard.getFloor() + 1);
			//Resets the player's position on the floor back to the beginning
			p1Scoreboard.setPos(0);
			//Clear the screen and introduce the new level
			cout << "\033[2J\033[1;1H";
			
			//We can check if the user has reached the last floor. If they have, then we can exit the main game loop
			//If the user has reached the last floor, we can confirm the user has completed the game!
			if (p1Scoreboard.getFloor() == 4) {
				loop = false;
				if (p1Scoreboard.getScore() > 10) {
					cout << "A booming voice around you tells \" Congratulations, you have collected enough organs to become a person again! Go enjoy your life\"" << endl;
				}
				else {
					cout << "A booming voice around you yells \"It looks like you haven't collected enough organs. I will now strip you of all your organs so that you will never be able to live again. \"" << endl;
				}
				break;
			}
			else {
				cout << "A booming voice around you yells \"Congratulations, you have passed this level!\"" << endl;
			}
		}

	}
	
	//Tests
	//enemy Alex("Alex", 30, 30, 5, 1);
	//cout << Alex << endl;
	//weapon sword;

}
