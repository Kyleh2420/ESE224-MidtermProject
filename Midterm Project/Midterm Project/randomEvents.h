#pragma once
#include <vector>
#include <fstream>
using namespace std;

class randomEvents {
private:
	vector<string> lines;
	vector<int> hpList;
	vector<int> balList;

	string eventsFileName;
	fstream eventsFile;

	int hpChange, balChange, selector;
	string line;

public:
	randomEvents(int floorLevel);
	int getLineCount();
	string getEvent();
	int getHPChange();
	int getBalChange();
	void getRandom();
};