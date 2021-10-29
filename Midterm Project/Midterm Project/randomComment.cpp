#include "randomComment.h"
#include <iostream>
#include <cstdlib> //For srand and rand
#include <string>
using namespace std;



int randomComment::getLineCount() {
	while (!commentsFile.eof()) {
		getline(commentsFile, line);
		lines.push_back(line);
	}
	line = "";
	cout << "Line count is: " << lines.size() << endl;
	return lines.size();
}


randomComment::randomComment(int floorLevel) {
	switch (floorLevel) {
	case 0:
		commentsFileName = "F0Comments.txt";
		cout << "Opening " << commentsFileName << endl;
		commentsFile.open(commentsFileName);
		if (commentsFile.fail()) {
			cerr << "Error: F0Comment not found." << endl;
			exit(1);
		}
		break;
	case 1:
		commentsFileName = "F1Comments.txt";
		cout << "Opening " << commentsFileName << endl;
		commentsFile.open(commentsFileName);
		if (commentsFile.fail()) {
			cerr << "Error: F1Comment not found." << endl;
			exit(1);
		}
		break;
	case 2:
		commentsFileName = "F2Comments.txt";
		cout << "Opening " << commentsFileName << endl;
		commentsFile.open(commentsFileName);
		if (commentsFile.fail()) {
			cerr << "Error: F2Comment not found." << endl;
			exit(1);
		}
		break;
	case 3:
		commentsFileName = "F3Comments.txt";
		cout << "Opening " << commentsFileName << endl;
		commentsFile.open(commentsFileName);
		if (commentsFile.fail()) {
			cerr << "Error: F3Comment not found." << endl;
			exit(1);
		}
		break;
	default:
		cout << "Well that wasn't supposed to happen. We couldn't find that floor!" << endl;
		break;
	}
	//Once we select the file, push everything back into a vector
	getLineCount();
}



//The following should return a random line from the file choosen
string randomComment::getEvent() {
	//This is Kyle's attempt at generating a random line from the file chosen. It does not work.
	/*
	srand(time(0));
	for (int i = 0; i < (rand() % lineCount)-1; i++) {
		getline(commentsFile, line);
		cout << "Unused Line: " << line << endl;
	}
	cout << commentsFileName << endl;
	*/

	return lines[selector];
}


void randomComment::getRandom() {
	srand(time(0));
	selector = rand() % lines.size();
}