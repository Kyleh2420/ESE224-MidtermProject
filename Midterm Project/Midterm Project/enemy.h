#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class enemy {
private:
	//Enemys name
	string name;
	//Enemys max HP
	int maxHealth;
	//Enemys HP
	int healthPoints;
	//Enemys AD. Multiplied by the level gets you the actual enemys damage
	int attackDamage;
	//Enemys level. Each level increase should increase their stats
	int level = 0;


	//The following is for the random generation of enemies
	vector<string> listOfNames;
	vector<int> listOfMaxHP;
	vector<int> listOfHP;
	vector<int> listOfAD;
	vector<int> listOfLevel;
	string enemyFileName;
	fstream enemyList;
	int selector;
	void getLineCount();
	void randomizeSelector();
public:
	//Default constructor
	enemy(int floorLevel);
	//Enemy Constructor. Enter Name, MaxHP, hpCurrent, damage, and level
	enemy(string n, int max, int hp, int ad, int lvl);

	//Getters!
	//Returns the [string] name of the enemy
	string getName();
	//Returns the [int] maxHP of the enemy
	int getMaxHP();
	//Returns the [int] current hp of the enemy
	int getHP();
	//Returns the [int] current damage of the enemy.
	//Once multiplied with the current leve, gets you the actaul damage of the enemy
	int getDMG();
	//Returns the [int] current level of the enemy
	int getLvl();

	//Setters!
	void setName(string input);
	void setMaxHP(int input);
	void setHP(int input);
	void setDMG(int input);
	void setLvl(int input);

	//Modifiers!
	void modHealth(int input);
	void modDamage(int input);

	//Example Usage: 
	//cout << enemyName << endl;
	friend ostream& operator <<(ostream& os, const enemy& e);


	//The following is for the randomization of enemies
	void randomEnemySelector(int floorlevel);
};

