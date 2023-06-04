# ASCII-Space-Shooter

A C++ `ncurses.h` space shooter game

[INSTALLATION]
Only available in a UX based console platform.

## How to compile and run

Have all `*.cpp` and `*.h` files from folder Space_Shooter, cd to the directory, and issue the following command in bash:
```bash
cd ASCII-Space-Shooter

g++ -std=c++11 -lncurses main.cpp Game.cpp Entity.h Item.cpp Player.cpp Enemy.cpp LeaderboardList.cpp LeaderboardIO.cpp -o main.out
```
Afterwards, play via:
```bash
./main.out
```

Another method with shell scripts:
```shell
./build.sh
```

#### How to generate `build.sh`

1. Modify the content in `build.sh`
    ```shell
    g++ -Iinclude -lncurses src/*.cpp -o bin/main.out && ./bin/main.out
    ```
2. Give permission to `build.sh` by:
    ```s
    $ chmod +x build.sh
    ```
3. Run in terminal:
    ```s
    $ ./build.sh
    ```

## Project Structure
```
PROJECT_ROOT
├── bin/
│   └── main.out
├── include/
│   ├── Enemy.h
│   ├── Entity.h
│   ├── Game.h
│   ├── Item.h
│   ├── LeaderboardIO.h
│   ├── LeaderboardList.h
│   └── Player.h
├── src/
│   ├── Enemy.cpp
│   ├── Game.cpp
│   ├── Item.cpp
│   ├── leaderboard.txt
│   ├── LeaderboardIO.cpp
│   ├── LeaderboardList.cpp
│   ├── main.cpp
│   └── Player.cpp
├── .gitignore
├── build.sh
└── README.md
```

## [Welcome to ASCII Space Shooter Game!]

Survive as many levels as you can and achieve a high score! This could be you: `>` (as a matter of fact, it is you in-game)

### HOW TO PLAY:
```
Move - Arrow Keys
Shoot - Space
End Game - Q

SYMBOLS:
'A' - +10 Ammo
'H' - +10 Health

ENEMIES:
'{' - Enemy
Stats: 10HP, 10DMG, 25 DMG if Crashed Into.
```
