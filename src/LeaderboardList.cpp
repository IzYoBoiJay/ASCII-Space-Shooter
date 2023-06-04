/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: The program header file creates a list for
 * reading and writing to leaderboard.txt file in which playerRanks are managed through the usage of the program.
 * LeaderboardList.cpp implementation file to perform member functions of LeaderboardIO.h
 */

//Include necessary header for needed objects below
#include "LeaderboardList.h"

//Default Constructor
LeaderboardList::LeaderboardList(){

    set_list_Size();

}

//Setter Member function to set list size
void LeaderboardList::set_list_Size() {

    this->listSize = list.size();

}

//Overrides += operator to push a new string object to the end of the list
LeaderboardList& LeaderboardList::operator+= (const std::string& rhs) {

    list.push_back(rhs);
    this->listSize = list.size();
    return *this;

}

//Overrides [] to return string object at index
std::string& LeaderboardList::operator[](int index) {

    auto it = list.begin();
    std::advance(it, index);
    return *it;


}

//Overrides << operator to print out the list string
std::ostream& operator<< (std::ostream& out, const LeaderboardList& list) {

    out << list;
    return out;

}