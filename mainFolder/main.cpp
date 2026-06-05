#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../GameDriver/Game.h"


using namespace std;

int main() {
    srand(time(0));

    Player userPlayer("None", 0, 0, 0, 0, 0);
    Inventory userInventory;
    Pathways* userPath = nullptr;
    Game playableGame(userPlayer, userInventory, userPath);
    
    playableGame.introSequence(userPlayer);
    while (playableGame.getGameOver() == false) {
        playableGame.areaTraversal(userPlayer, userInventory, userPath);
    }
    cout << "Game Over! Thanks for playing!" << endl;
    return 0;
}

/*
for valgrind copy this command after navigating to the mainFolder:
g++ -g -O0 \
main.cpp \
../GameDriver/Game.cpp \
../Biomes/TremorousCaves.cpp \
../Biomes/StarterForest.cpp \
../Biomes/KingsLand.cpp \
../Biomes/DesertOfDeath.cpp \
../Biomes/Pathways.cpp \
../Biomes/shop.cpp \
../Player/Inventory.cpp \
../Player/Player.cpp \
../combatCMake/combatSrc/*.cpp \
../ScreenDisplay/src/Hotbar.cpp \
../ScreenDisplay/src/ReadScreenFile.cpp \
../ScreenDisplay/src/ScreenDisplay.cpp \
-o BattleLeague
*/