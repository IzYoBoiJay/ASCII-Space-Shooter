/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: Enemy.h header file for the ASCII space shooter that handles the enemy objects and enemy-related chance events.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Item.h"

class Enemy: public Entity {

private:

    //Enemy bullet position
    int bulletShotY, bulletShotX;

public:

    //Parameterized enemy constructor
    Enemy(WINDOW* window, char symbol);

    //Override movement pure virtual fuction of entity
    int movement() override;

    //Draw Enemy
    void drawEnemy();

    //Enemy Shoot Function
    void shoot();

    //Resets bullet position (Setter)
    void reset_bullet() {

        this->bulletShotY = 0;
        this->bulletShotX = 0;

    }

    //Getters
    int get_bullet_yPos() const {

        return bulletShotY;

    }

    int get_bullet_xPos() const {

        return bulletShotX;

    }

};

#endif