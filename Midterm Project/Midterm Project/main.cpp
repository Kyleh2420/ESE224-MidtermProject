#include "enemy.h"
#include "fileOperations.h"
#include "Weapon.h"
//player.h and scoreboard.h don't need to be called, since they are already called in fileOperations.h
//If called again, it will result in a redefinition error
using namespace std;

void playerCombat(player&, weapon[4][4], enemy&, scoreboard&) {

}

bool enemyCombat(enemy&, player&, scoreboard&) {

}

void playerOptions(player&, fileOperations&, scoreboard&) {

}

void chooseWeapon(weapon[4][4], int, player&) {

}

int main() {
	player p1;






	enemy Alex("Alex", 30, 30, 5, 1);
	cout << Alex << endl;
	weapon sword;
	scoreboard test;

}
