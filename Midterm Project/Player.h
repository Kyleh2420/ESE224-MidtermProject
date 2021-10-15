#include <string>
#include <iostream>
using namespace std;

class player {
private:
	string Name;
	int maxHealth;
	int healthPoints;
	int attackDamage;
public:
	//Default Constructor
	player();

	//Getters!
	string getName();
	int getMaxHP();
	int getHP();
	int getDMG();

	//Setters!
	void setName(string input);
	void setMaxHP(int input);
	void setHP(int input);
	void setDMG(int input);
	

	void modHealth(int input);
	void modDamage(int input);

	friend ostream& operator <<(ostream& os, const player& p);
};