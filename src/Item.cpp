#include "Item.h"

Item::Item() {

    currWindow = NULL;
    yPos = 1;
    xPos = 1;
    getmaxyx(currWindow, maxY, maxX);

    ascii = ' ';

    this->isBullet = false;
    this->isHeal = false;
    this->isAmmo = false;
}

Item::Item(WINDOW *window, int y, int x, char symbol, std::string type) {

    currWindow = window;
    yPos = y;
    xPos = x;
    getmaxyx(currWindow, maxY, maxX);

    ascii = symbol;

    if (type == "bullet") {

        this->isBullet = true;

    }
    else if (type == "heal") {

        this->isHeal = true;

    }
    else if (type == "ammo") {

        this->isAmmo = true;

    }

}

Item::Item(WINDOW *window, char symbol, std::string type) {

    currWindow = window;
    getmaxyx(currWindow, maxY, maxX);
    movement();

    ascii = symbol;

    if (type == "bullet") {

        this->isBullet = true;

    }
    else if (type == "heal") {

        this->isHeal = true;

    }
    else if (type == "ammo") {

        this->isAmmo = true;

    }

}

void Item::drawItem() {

    mvwaddch(currWindow, yPos, xPos, ascii);

}

int Item::movement() {

    xPos = rand() % (maxX - 2) + 1;
    yPos = rand() % (maxY - 2) + 1;
    
}