#include "../Biomes/StarterForest.h"
#include "../Biomes/TremorousCaves.h"
#include "../Biomes/DesertOfDeath.h"
#include "../Biomes/KingsLand.h"
#include <string>
#include <iostream>
#include "../combatCMake/combatHeader/character.h"
#include "../combatCMake/combatHeader/combat.h"
#include "../combatCMake/combatHeader/skill.h"
#include "../combatCMake/combatHeader/cplayer.h"
#include "../combatCMake/combatHeader/enemy.h"
#include "../combatCMake/combatHeader/slime.h"
#include "../Player/Inventory.h"
#include "../Player/Player.h"
#include "../Player/Item.h"
#include "../ScreenDisplay/header/ScreenDisplay.h"

class Game {
 private:
    Player player;
    Pathways* playerPath;
    Inventory playerInventory;
    std::string currArea = "Starter Forest";

    ScreenDisplay screenDisplay;

    StarterForest forest;
    TremorousCaves caves;
    DesertOfDeath desert;
    KingsLand kingsLand;

    bool gameOver = false;

 public:
    std::string getCurrentArea();
    Game(Player player, Inventory inventory, Pathways* playerPath);
    void introSequence(Player &player);
    void areaTraversal(Player &player, Inventory &playerInventory, Pathways* &playerPath);
    Pathways* choosePath(Pathways& areaPaths);
    void userPathChoice(Player& player, Inventory& playerInventory, Pathways* &playerPath, Pathways& areaPaths);
    bool getGameOver() const;

    vector<int> getUnlockedSkillsForPlayer(const Player& player);
};