#pragma once
#include <string>
#include <iostream>
using namespace std;

class weapon {
private:
	string wItem;
	int wDamage;
public:
	weapon();
	weapon(string i, int d);
	void setItem(string);

	string getItem();
	int getDMH();
};

