#include <iostream>
#include <string>
using namespace std;

class fileOperations {
    private:
        string sbFileName = "scoreboard.txt;"
        sb_myFile;

        string pFileName;
        fstream pmyFile;
    public:
        void save2File(player&);
        void save2File(scoreboard&);
        void chooseFile(scoreboard&, player&);
        void closeFile();
        void scoreRank();
};