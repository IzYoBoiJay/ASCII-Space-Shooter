/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: The program header file creates a list for
 * reading and writing to leaderboard.txt file in which playerRanks are managed through the usage of the program.
 * LeaderboardList.cpp implementation file to perform member functions of LeaderboardIO.h
 */
#ifndef LEADERBOARDLIST_H
#define LEADERBOARDLIST_H

//Include necessary header for needed objects below
#include "Game.h"

#include <list>
#include <iterator>
#include <string>


class LeaderboardList {

//Private data members
private:

    std::list<std::string> list;

    int listSize = 0;

//Public member functions
public:

    //Default Constructor
    LeaderboardList();

    //Setter Member function to set list size
    void set_list_Size();

    //Getter Member function to get list size
    int get_list_Size() const {

        return listSize;

    }

    //Overrides += operator to push a new string object to the end of the list
    LeaderboardList& operator+= (const std::string& rhs);

    //Overrides [] to return string object at index
    std::string& operator[] (int);

    //Friend Member Function that overrides << operator to print out the list string object
    friend std::ostream &operator<< (std::ostream& out, const LeaderboardList& list);

};

#endif
