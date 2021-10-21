#pragma once
#include <string>
#include <iostream>
using namespace std;

class weapon {
private:
	string wItem;
	int wDamage;
public:
	//Default constructor
	weapon();
	//Weapon constructor
	weapon(string i, int d);
	//Setters!
	void setItem(string);

	//Getters!
	string getItem();
	int getDMG();
};

