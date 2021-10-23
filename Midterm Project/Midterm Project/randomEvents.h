#pragma once
#include <vector>
#include <fstream>
using namespace std;

class randomEvents {
private:
	int lineCount = 0;
	//vector<string> lineIndicies;

	string eventsFileName;
	fstream eventsFile;

	string line;

public:
	randomEvents(int floorLevel);
	int getLineCount();
	string getEvent();
};