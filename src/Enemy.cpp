/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: Implementation file for the ASCII space shooter Enemy.h that handles the enemy objects and enemy-related chance events.
 */

#include "Enemy.h"

//Parameterized Constructor
Enemy::Enemy(WINDOW* window, char symbol) {

    currWindow = window;

    getmaxyx(currWindow, maxY, maxX);

    //Set enemy position to the right border of screen at random Y-position
    yPos = rand() % (maxY - 2) + 1;
    xPos = maxX - 2;

    ascii = symbol;

    health = 10;
    damage = 10;

    drawEnemy();

}

//Graphics
void Enemy::drawEnemy() {

    mvwaddch(currWindow, yPos, xPos, ascii);

}

//Movement override
int Enemy::movement() {

    //Remove character artifact
    mvwaddch(currWindow, yPos, xPos, ' ');

    //Move left
    --xPos;

    //If enemy reaches to the left screen border, position them at the start of the right border at a random Y-axis
    if (xPos < 1) {

        xPos = (maxX - 2);
        yPos = rand() % (maxY - 2) + 1;

    }

    // 1 out of 10 chance of shooting
    if((rand() % 10 + 1) == 1) {

        shoot();

    }

}

//Player shoot function
void Enemy::shoot() {

    Item bullet = Item(currWindow, yPos, xPos + 1, '~', "bullet");

        //Bullet animation AND position update
        for(int i = bullet.xPos; i > 0 && xPos != (maxX - 2); i--) {

                mvwaddch(currWindow, bullet.yPos, i, bullet.ascii);
                wrefresh(currWindow);
                
                std::this_thread::sleep_for(std::chrono::milliseconds(1));

                    mvwaddch(currWindow, bullet.yPos, i, ' ');
                    wrefresh(currWindow);

                bullet.xPos--;
                
                //If bullet reaches left border
                if(i == 1) {

                    mvwaddch(currWindow, bullet.yPos, i, ' ');
                    this->bulletShotY = bullet.yPos;
                    this->bulletShotX = bullet.xPos;
                    break;
                }

    } //End for

}