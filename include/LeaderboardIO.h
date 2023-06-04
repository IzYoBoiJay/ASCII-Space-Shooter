/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: The program header file reads and writes to leaderboard.txt file in which player ranks are managed
 * through the usage of the program. LeaderboardIO.cpp implementation file to perform member functions of LeaderboardIO.h
 */

#ifndef LEADERBOARDIO_H
#define LEADERBOARDIO_H

#include "LeaderboardList.h"

//Include necessary header for needed objects
#include <iostream>
#include <fstream>
#include <sstream>

class LeaderboardIO {

//Public member functions
public:

    //Stores playerRanks from leaderboard.txt onto Leaderboard list
    static LeaderboardList store_score();

    //Writes and updates new playerRanks from Leaderboard list to leaderboard.txt
    static void write_score(LeaderboardList list);

};

#endif