/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: Player.h header file for the ASCII space shooter that handles the player object and user inputted ncurses commands.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Item.h"


class Player : public Entity {

private:

    std::vector<Item> ammo;

    int bulletShotY, bulletShotX;

    int keyPressed;

public:

    //Default Constructor
    Player();

    //Player Parameterized Constructor
    Player(WINDOW* window, int y, int x, char symbol);
    
    //Setter (within .cpp)
    void set_Ammo();

    //Getters
    int get_Ammo_left() const {

        return ammo.size();

    }
    
    int get_bullet_yPos() const {

        return bulletShotY;

    }

    int get_bullet_xPos() const {

        return bulletShotX;

    }

    //Draw player
    void drawPlayer();

    //Override movement pure virtual fuction of entity
    int movement() override;

    //Shoot function
    void shoot();

    //Movement functions
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

};

#endif
