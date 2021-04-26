/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: UNIX-based ASCII Space Shooter with HUD, Collision Detection, and Enemy and Item generation.
 * Player is able to control the '>' unit via keyboard input in an ncurses.h enviornment. After the game is over, the player
 * enters their name to add their name and score to the leaderboard.
 */

//Include necessary header for needed objects below
#include "Game.h"
#include "Entity.h"
#include "Player.h"
#include "Item.h"
#include "LeaderboardList.h"
#include "LeaderboardIO.h"

#include <iostream>
#include <ncurses.h>
#include <time.h>

//Only use these objects with the namespace std
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

//Function declarations
void create_playerRank(LeaderboardList &list, Game spaceShooter);
void display_leaderboard(LeaderboardList list);

int main(int argc, char **argv) {

    //Display intro to program and menu of commands

    LeaderboardList list = LeaderboardIO::store_score();

    //Set up ncurses enviornment
    initscr();
    noecho();
    cbreak();

    //Hide cursor
    curs_set(0);

    //Info
    printw("Welcome to ASCII Space Shooter Game!\n\nHOW TO PLAY:\nMove - Arrow Keys\nShoot - Space\nEnd Game - Q\n\nSYMBOLS:\n'A' - +10 Ammo\n'H' - +10 Health\n\nENEMIES:\n'{' - Enemy\nStats: 10HP, 10DMG, 25 DMG if Crashed Into.\n\nPress Any Key to Continue/Play...");
    
    //Press Any Key
    getch();

    clear();
    refresh();

    //Create game object of spaceShooter
    Game spaceShooter;

    //Seed for random number generator
    srand(time(NULL));

    //Main Game Engine Loop
    while (spaceShooter.isRunning() == true) {

        spaceShooter.process_keyPressed();

        spaceShooter.gCycleUpdate();

        spaceShooter.redraw();

    }

    //End window
    endwin();

    //Creates player instance to append to leaderboard
    create_playerRank(list, spaceShooter);

    //Displays leaderboard
    display_leaderboard(list);

    //Writes changes to the task_list.txt file
    LeaderboardIO::write_score(list);

    //Exit program successfully
    return 0;

}

//Creates and appends a new task to the task list
void create_playerRank(LeaderboardList &list, Game spaceShooter) {

    string playerRank;
    string playerName = "";

    cout << endl << "Game over! Your score is: " << spaceShooter.get_score() << endl;

    cout << endl << "Enter your name for the scoreboard: ";
    cin >> playerName;

    playerRank = playerName + '\t' + to_string(spaceShooter.get_score());

    list += playerRank;

}

//Displays unfinished tasks
void display_leaderboard(LeaderboardList list) {

    cout << endl;

    for (int i = 0; i < list.get_list_Size(); i++) {

        cout << list[i] << endl;
    }

    cout << endl;

} //End displayTasks