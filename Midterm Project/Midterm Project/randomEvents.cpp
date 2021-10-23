#include "randomEvents.h"
#include <iostream>;
#include <string>
using namespace std;

void randomEvents::openFile(int floorLevel) {
	switch (floorLevel) {
	case '1':
		eventsFileName = "F1RandomEvents.txt";
		eventsFile.open(eventsFileName);
		if (eventsFile.fail()) {
			cerr << "Error: F1RandomEvents not found." << endl;
			exit(1);
		}
		break;
	case '2':
		eventsFileName = "F2RandomEvents.txt";
		eventsFile.open(eventsFileName);
		if (eventsFile.fail()) {
			cerr << "Error: F2RandomEvents not found." << endl;
			exit(1);
		}
		break;
	case '3':
		eventsFileName = "F3RandomEvents.txt";
		eventsFile.open(eventsFileName);
		if (eventsFile.fail()) {
			cerr << "Error: F3RandomEvents not found." << endl;
			exit(1);
		}
		break;
	case '4':
		eventsFileName = "F4RandomEvents.txt";
		eventsFile.open(eventsFileName);
		if (eventsFile.fail()) {
			cerr << "Error: F4RandomEvents not found." << endl;
			exit(1);
		}
		break;
	default:
		break;
	}
}

int randomEvents::getLineCount() {
	while (!eventsFile.eof()) {
		getline(eventsFile, line);
		lineCount++;
	}
	line = "";
	return lineCount;
}

string randomEvents::getEvent() {

}