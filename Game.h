/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: Header file for the ASCII space shooter that handles game engine updates. All-in-One for MVC model.
 */

#ifndef GAME_H
#define GAME_H

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

class Game {
private:

    int gSpaceMaxY, gSpaceMaxX;

    //WINDOW Pointers
    WINDOW* gameWindow;

    Player player;

    int currLevel = 0;
    int score = 0;


    int numEnemies;
    int numSpawned;

    std::vector<Enemy> enemies;
    std::vector<Item> items;

    bool isShooting = false;
    bool gameRunning = false;

public:

    //Constructor
    Game();

    //Main Game Engine Functions
    int process_keyPressed();
    void gCycleUpdate();
    void redraw();

    //Getters
    bool isRunning() const {

        return gameRunning;

    }

    int get_score() const {

        return score;

    }

    int get_level() const {

        return currLevel;

    }

    //Controller Functions
    void level();
    void generate_Enemies();
    void generate_Items();
    void collision();

    //Graphics
    void begin_Render();
    void gen_Borders();
    void clear_Window();
    void refresh_Window();

    
};

#endif