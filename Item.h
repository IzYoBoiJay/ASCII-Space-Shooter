#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
//#include "Player.h"
//#include "Enemy.h"

class Item : public Entity {


private:

bool isBullet = false;
bool isHeal = false;
bool isAmmo = false;


public:

    //Default Constructor
    Item();

    //Parameterized Constructor with SET position
    Item(WINDOW* window, int y, int x, char symbol, std::string type);

    //Parameterized Constructor with RNG position
    Item(WINDOW* window, char symbol, std::string type);


    //Draw Item
    void drawItem();

    //Override movement pure virtual fuction of entity
    int movement() override;

    //Getters
    bool get_isBullet() const {

        return isBullet;

    }

    bool get_isHeal() const {

        return isHeal;

    }

    bool get_isAmmo() const {

        return isAmmo;

    }

};

#endif