/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: The program implementation file reads and writes to leaderboard.txt file in which player ranks are managed
 * through the usage of the program. LeaderboardIO.cpp implementation file to perform member functions of LeaderboardIO.h
 */

//Include necessary header for needed objects below
#include "LeaderboardIO.h"

//Reads and stores playerRanks into a LeaderboardList list
LeaderboardList LeaderboardIO::store_score() {

    LeaderboardList list;

    std::ifstream inputFile;

    std::stringstream ss;

    std::string line;
    std::string playerName;
    std::string playerScore;

    //Opens file
    inputFile.open("leaderboard.txt");


    //If unable to open file, or does not exist, exit program abnormally with error message.
    if (!inputFile) {

        std::cerr << "\nUnable to open file leaderboard.txt. Please check if leaderboard.txt is properly in the directory.\n\n";

        //Exits program abnormally
        exit (1);

    } //End if

    //Extracts variables from the leaderboard.txt file and creates a string object and adds it to the LeaderboardList list
    while (getline(inputFile, line)) {

        ss.str(line);
        ss.clear();

        getline(ss, playerName, '\t');
        getline(ss, playerScore, '\t');

        std::string playerRank = ss.str();

        list += playerRank;

    }

    //Close file
    inputFile.close();

    return list;

}

//Writes and saves changes into the LeaderboardList list
void LeaderboardIO::write_score(LeaderboardList list) {

    std::ofstream outputFile;

    //Opens file
    outputFile.open("leaderboard.txt");

    //If unable to open file, or does not exist, exit program abnormally with error message.
    if (!outputFile) {

        std::cerr << "\nUnable to open file leaderboard.txt. Please check if leaderboard.txt is properly in the directory.\n\n";

        //Exits program abnormally
        exit (1);

    } //End if

    for (int i = 0; i < list.get_list_Size(); i++) {

        outputFile << list[i] << std::endl;

    } //End for

    //Close file
    outputFile.close();

}