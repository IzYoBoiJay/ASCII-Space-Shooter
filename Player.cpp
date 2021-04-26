/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: Implementation file for the ASCII space shooter Player.h that handles the player object and user inputted ncurses commands.
 */
#include "Player.h"

Player::Player() {

    currWindow = NULL;
    yPos = 1;
    xPos = 1;
    getmaxyx(currWindow, maxY, maxX);
    keypad(currWindow, TRUE);

    ascii = ' ';

    health = 0;
    damage = 0;

}

//Parameterized Constructor
Player::Player(WINDOW *window, int y, int x, char symbol) {

    currWindow = window;
    yPos = y;
    xPos = x;
    getmaxyx(currWindow, maxY, maxX);
    keypad(currWindow, TRUE);

    ascii = symbol;

    health = 100;
    set_Ammo();

    damage = 10;

    drawPlayer();

}

//Graphics
void Player::drawPlayer() {

    mvwaddch(currWindow, yPos, xPos, ascii);

}

//Movement
int Player::movement() {

    this->keyPressed = wgetch(currWindow);

    switch (keyPressed) {

    case KEY_RIGHT:

        moveRight();
        break;

    case KEY_LEFT:

        moveLeft();
        break;

    case KEY_UP:

        moveUp();
        break;

    case KEY_DOWN:
    
        moveDown();
        break;

    case ' ':

        //Able to shoot if ammo is not empty
        if (ammo.size() != 0) {

            shoot();
        }
        break;

    default:

        break;

    }

    return this->keyPressed;

}

//Generates 10 bullets for player ammo
void Player::set_Ammo() {

    for (int i = 0; i < 10; i++) {

        Item bullet = Item(currWindow, yPos, xPos + 1, '=', "bullet");
        ammo.push_back(bullet);

    }

}

void Player::shoot() {

    //Bullet position in front of player
    ammo.back().yPos = yPos;
    ammo.back().xPos = xPos + 1;

    //Bullet animation AND position update
    for (int i = ammo.back().xPos; i < (maxX - 1); i++) {

        mvwaddch(currWindow, ammo.back().yPos, i, ammo.back().ascii);
        wrefresh(currWindow);

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        //If bullet is in front of player
        if ((ammo.back().xPos - 1) == xPos) {

            mvwaddch(currWindow, ammo.back().yPos, i, ' ');
            wrefresh(currWindow);

        }
        //Otherwise
        else {

            mvwaddch(currWindow, ammo.back().yPos, i - 1, ' ');
            wrefresh(currWindow);

        }

        this->ammo.back().xPos++;

        //If ammo reaches right border
        if (i == (maxX - 2)) 
        {
            mvwaddch(currWindow, ammo.back().yPos, i, ' ');
            this->bulletShotY = ammo.back().yPos;
            this->bulletShotX = ammo.back().xPos;

            //Delete bullet
            ammo.pop_back();

        }

    } //End for

}

void Player::moveRight() {

    //Remove character artifact
    mvwaddch(currWindow, yPos, xPos, ' ');

    ++xPos;

    //If player reaches right border
    if (xPos > (maxX - 2)) {

        //Player kept in border
        xPos = (maxX - 2);

    }

}

void Player::moveLeft() {

    //Remove character artifact
    mvwaddch(currWindow, yPos, xPos, ' ');

    --xPos;

    //If player reaches left border
    if (xPos < 1) {

        //Player kept in border
        xPos = 1;
    }

}

void Player::moveUp() {

    //Remove character artifact
    mvwaddch(currWindow, yPos, xPos, ' ');

    --yPos;

    //If player reaches upper border
    if (yPos < 1) {

        //Player kept in border
        yPos = 1;
    }

}

void Player::moveDown() {

    //Remove character artifact
    mvwaddch(currWindow, yPos, xPos, ' ');

    ++yPos;

    //If player reaches lower border
    if (yPos > (maxY - 2)) {

        //Player kept in border
        yPos = (maxY - 2);
    }
    
}