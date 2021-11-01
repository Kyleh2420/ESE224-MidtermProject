#pragma once
#include <vector>
#include <fstream>
using namespace std;

class randomComment {
private:
	vector<string> lines;

	string commentsFileName;
	fstream commentsFile;

	int selector;
	string line;

public:
	randomComment(int floorLevel);
	int getLineCount();
	string getComment();
	void getRandom();
	string getEvent();
};