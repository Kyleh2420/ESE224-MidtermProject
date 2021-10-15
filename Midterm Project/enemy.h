#include <iostream>
#include <string>
using namespace std;

class enemy
{
private:
	string name;
	int maxHealth;
	int healthPoints;
	int attackDamage;
	int level = 0;
public:
	//Default constructor
	enemy();
	enemy(string n, int max, int hp, int ad);

	string getName();
	int getMaxHP();
	int getDMG();
	int getLvl();

	void setName(string input);
	void setMaxHP(int input);
	void setHP(int input);
	void setDMG(int input);
	void setLvl(int input);

	void modHealth(int input);
	void modDamage(int input);

	friend ostream& operator <<(ostream& os, const enemy& e);
};

