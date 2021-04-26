/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: Core header file (no implementation file) including nearly all necessary header functions for entity
 * creations in which Item, Player, and Enemy classes shall inherit.
 */

#ifndef ENTITY_H
#define ENTITY_H

//Include necessary header for needed objects below
#include <ncurses.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <time.h>

class Entity {

public:

    WINDOW* currWindow;

    int maxY, maxX;

    //For drawing
    char ascii;

    //For collision and position
    int xPos = 0;
    int yPos = 0;

    //For event calculation
    int health = 0;
    int damage = 0;

    //Getters
    int get_xPos() const {

        return xPos;

    }

    int get_yPos() const {

        return yPos;

    }

    //Pure Virutal Function for handling entity movement
    virtual int movement() = 0;


};


#endif