#pragma once
#include <vector>
#include <fstream>
using namespace std;

class randomEvents {
private:
	int lineCount;
	vector<int> lineIndicies;

	string eventsFileName;
	fstream eventsFile;

	string line;

public:
	void openFile(int floorLevel);
	int getLineCount();
	string getEvent();
};