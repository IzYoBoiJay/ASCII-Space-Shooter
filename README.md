# ASCII-Space-Shooter
A C++ ncurses.h space shooter game

***INSTALLATION**
Only available in a UX based console platform.

Have all *.cpp and *.h files from folder Space_Shooter, cd to the directory, and issue the following command in bash:
g++ -lncurses main.cpp Game.cpp Entity.h Item.cpp Player.cpp Enemy.cpp LeaderboardList.cpp LeaderboardIO.cpp

Afterwards, play via:
./a.out


***Welcome to ASCII Space Shooter Game!***

Survive as many levels as you can and achieve a high score! This could be you: '>' (as a matter of fact, it is you in-game)

HOW TO PLAY:
Move - Arrow Keys
Shoot - Space
End Game - Q

SYMBOLS:
'A' - +10 Ammo
'H' - +10 Health

ENEMIES:
'{' - Enemy
Stats: 10HP, 10DMG, 25 DMG if Crashed Into.
