#pragma once
#include <vector>
#include <fstream>
using namespace std;

class randomEvents {
private:
	vector<string> lines;

	string eventsFileName;
	fstream eventsFile;

	int hpChange, balChange;
	string line;

public:
	randomEvents(int floorLevel);
	int getLineCount();
	string getEvent();
};