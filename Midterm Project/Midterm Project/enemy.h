#include <iostream>
#include <string>
using namespace std;

class enemy {
private:
	//Enemys name
	string name;
	//Enemys max HP
	int maxHealth;
	//Enemys HP
	int healthPoints;
	//Enemys AD
	int attackDamage;
	//Enemys level. Each level increase should increase their stats
	int level = 0;
public:
	//Default constructor
	enemy();
	//Enemy Constructor. Enter Name, MaxHP, hpCurrent, damage, and level
	enemy(string n, int max, int hp, int ad, int lvl);

	//Getters!
	string getName();
	int getMaxHP();
	int getHP();
	int getDMG();
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
};

