#include <string>
#include <iostream>
using namespace std;

class player {
private:
	//Player Name
	string name;
	//Max hp of player
	int maxHealth;
	//Current HP of player
	int healthPoints;
	//Base AD of the player
	int attackDamage;
	//Currency of player
	int balance;
public:
	//Default Constructor
	player();

	//Getters!
	string getName();
	int getMaxHP();
	int getHP();
	int getDMG();
	int getBal();

	//Setters!
	//Accepts cin as the arguement. Sets the player name inside the player save file
	void setName(istream& in);
	void setMaxHP(int input);
	void setHP(int input);
	void setDMG(int input);
	void setBal(int input);

	//Modifies player's HP with the input value
	void modHealth(int input);
	//Modifies player's base damage with an input value
	void modDamage(int input);
	//Modifies player's money balance
	void modBal(int input);

	friend ostream& operator <<(ostream& os, const player& p);
};