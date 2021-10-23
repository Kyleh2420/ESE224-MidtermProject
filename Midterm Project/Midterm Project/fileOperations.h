#include <iostream>
#include <string>
#include <fstream>
#include "scoreboard.h"
#include "player.h"
using namespace std;

class fileOperations {
    private:
        //Holds the name of the scoreboard file
        string sbFileName = "scoreboard.txt";
        //Opens the scoreboard file
        fstream sb_myFile;

        //Holds the name of the player file
        string pFileName;
        //Opens the player File
        fstream pmyFile;

    public:
        //Saves player progress to file
        void save2File(player&);
        //Saves scoreboard progress to file
        void save2File(scoreboard&);
        //Asks user to select the file to use
        void chooseFile(scoreboard&, player&);
        //Closing Files
        void closeFile();
        //Output scores from all scoreboards
        void scoreRank();


        //Setting of something
        void setPName(istream& in);

        //Opens the ramdom Events File
        void openRandomEvents();
        string getRandomEvent();
};