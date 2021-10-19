#include "enemy.h"
#include "fileOperations.h"
#include "Weapon.h"
//player.h and scoreboard.h don't need to be called, since they are already called in fileOperations.h
//If called again, it will result in a redefinition error
using namespace std;


int main() {
	player p1;
	enemy Alex("Alex", 30, 30, 5, 1);
	cout << Alex << endl;
	weapon sword;
	scoreboard test;

}
