/*
 * Author: Jhun-Thomas Calahatian
 * Program Description / Purpose: Implementation file for the ASCII space shooter that handles game engine updates. All-in-One for MVC model.
 */

#include "Game.h"

Game::Game() {

    this->gameRunning = true;

    //Get Standard Screen Size
    getmaxyx(stdscr, gSpaceMaxY, gSpaceMaxX);

    //Create Window for Input [Centered at standard screen size]
    gameWindow = newwin(20, 50, (gSpaceMaxY / 2) - 10, (gSpaceMaxX / 2) - 25);

    gen_Borders();
    refresh_Window();

    currLevel = 0;
    score = 0;
    numEnemies = 0;

    //Initializes player object
    player = Player(gameWindow, 9, 1, '>');

    //Begins drawing graphics
    redraw();
}

//Process keyPress (User Input)
int Game::process_keyPressed() {

    int key = player.movement();

    //Shoot
    if (key == ' ')
    {

        isShooting = true;
        return key;
    }
    //Quit
    if (key == 'q')
    {

        this->gameRunning = false;
        return key;
    }
    //Otherwise, just return key value
    else
    {

        isShooting = false;
        return key;
    }
}

//Game Cycle Update (Controller)
void Game::gCycleUpdate() {

    level();
    collision();

    //For Loop to reset enemyBullet to help with collision
    for (int i = 0; i < enemies.size(); i++) {

        enemies[i].reset_bullet();
    }

    if (player.health <= 0) {

        this->gameRunning = false;
    }

}

//Generates enemies and items
void Game::level() {

    //Increment level if enemies are at 0
    if (numEnemies == 0) {

        ++currLevel;
        numSpawned = 0;
    }

    //Generation
    generate_Enemies();
    generate_Items();

    //Process enemy movement
    for (int i = 0; i < enemies.size(); i++) {

        enemies[i].movement();
    }

}

//Generates enemies
void Game::generate_Enemies() {

    //Enemies on screen = current level x5
    if (numSpawned < currLevel * 5) {

        //Create new enemy
        Enemy newEnemy = Enemy(gameWindow, '{');

        //Push into enemies vector
        enemies.push_back(newEnemy);

        //Increment
        ++numSpawned;
        ++numEnemies;
    }

}

void Game::generate_Items() {

    //Items on screen (at a time) = current Level
    if (items.size() < currLevel) {

        // 1 out of 2 chance for each item
        if (((rand() % 2) + 1) == 1) {

            //Create Ammo instance
            Item newAmmo = Item(gameWindow, 'A', "ammo");

            items.push_back(newAmmo);
        }
        else {

            //Create Heal instance
            Item newHeal = Item(gameWindow, 'H', "heal");

            items.push_back(newHeal);
        }

    }

}

//Collision Detection
void Game::collision() {

    //For Loop handling Player & Enemy Collision
    for (int i = 0; i < enemies.size(); i++) {

        //Player collides with enemy
        if ((player.get_yPos() == enemies[i].get_yPos()) && (player.get_xPos() == enemies[i].get_xPos())) {

            //Destroy enemy
            enemies.erase(enemies.begin() + i);

            //Player loses 25 health
            player.health -= 25;

            //Decrement numEnemies
            --numEnemies;
        }

        //Enemy bullet to Player Collision
        if ((enemies[i].get_bullet_yPos() == player.get_yPos()) && (enemies[i].get_bullet_xPos() <= player.get_xPos())) {

            //Player takes damage equal to enemies damage
            player.health -= enemies[i].damage;
        }

        //PlayerBullet to Enemy Collision
        if ((player.get_bullet_yPos() == enemies[i].get_yPos()) && (player.get_bullet_xPos() >= enemies[i].get_xPos())) {

            //Enemies take damage equal to players damage
            enemies[i].health -= player.damage;

            //If the enemies health drops to 0 or lower
            if (enemies[i].health <= 0) {

                //Destroy enemy
                enemies.erase(enemies.begin() + i);

                //Player receives 10 score
                score += 10;

                //Decrement numEnemies
                --numEnemies;
            }

        }

    } //End For handling Player & Enemy Collission

    //For Loop handling Player & Item Collision
    for (int i = 0; i < items.size(); i++) {

        //If player collides with item
        if ((player.get_yPos() == items[i].get_yPos()) && (player.get_xPos() == items[i].get_xPos())) {

            //If the item is a heal
            if (items[i].get_isHeal()) {

                //Heal player with 10 health
                player.health += 10;
            }

            //If the item is ammo
            if (items[i].get_isAmmo()) {

                //Give player 10 bullets
                player.set_Ammo();
            }

            //Destroy item instance
            items.erase(items.begin() + i);

            //Player receives 5 score
            score += 5;
        }

    } //End For handling Player & Item Collision

}

//Main graphic processing function
void Game::redraw() {

    begin_Render();

    //HUD
    mvwprintw(gameWindow, 0, 1, "[Level: %d]", currLevel);
    refresh_Window();

    mvwprintw(gameWindow, 0, 15, "[Enemies Left: %d]", numEnemies);
    refresh_Window();

    mvwprintw(gameWindow, 0, 36, "[Score: %d]", score);
    refresh_Window();

    mvwprintw(gameWindow, 19, 1, "[Health: %d]", player.health);
    refresh_Window();

    mvwprintw(gameWindow, 19, 15, "[Ammo: %d]", player.get_Ammo_left());
    refresh_Window();

    //Draw Player
    player.drawPlayer();

    //Draw Enemies
    for (int i = 0; i < enemies.size(); i++) {

        //refresh();
        refresh_Window();
        enemies[i].drawEnemy();
    }

    refresh_Window();

    //Draw Items
    for (int i = 0; i < items.size(); i++) {

        //refresh();
        refresh_Window();
        items[i].drawItem();
    }

}

//Begins render
void Game::begin_Render() {

    clear_Window();
    refresh_Window();

}

//Generates box border
void Game::gen_Borders() {

    box(gameWindow, 0, 0);

}

//Clears game window
void Game::clear_Window() {

    wclear(gameWindow);
    gen_Borders();

}

//Refreshes game window
void Game::refresh_Window() {

    refresh();
    wrefresh(gameWindow);

}