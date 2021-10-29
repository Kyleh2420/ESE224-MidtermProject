#pragma once
#include <string>
#include <iostream>
using namespace std;

class weapon {
private:
	string wItem;
	int wDamage;
	int wCost;
public:
	//Default constructor
	weapon();
	//Weapon constructor
	weapon(string i, int d, int c);
	//Setters!
	void setItem(string in);
	void setDMG(int i);
	void setCost(int i);

	//Getters!
	string getItem();
	int getDMG();
	int getCost();
};

