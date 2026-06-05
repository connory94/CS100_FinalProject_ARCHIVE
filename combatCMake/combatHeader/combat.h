#ifndef COMBAT_H
#define COMBAT_H
#include "character.h"
#include "enemy.h"
#include "cplayer.h"
#include "../../Player/Inventory.h"
using namespace std;

class Combat {
public:
    Combat(cPlayer& player, Enemy& enemy, Inventory& inventory);

    void startCombat();
    bool playerGoesFirst(const cPlayer& player, const Enemy& enemy) const;
    void displayStatus()        const;
    void displayCombatOptions() const;

    bool playerWon() const;
    bool playerFled() const;

    bool isPotion(const string& itemName);
    bool usePotion(const string& itemName, cPlayer& player, Inventory& inventory);
    bool openInventory(cPlayer& player, Inventory& inventory);

private:
    cPlayer& player;
    Enemy&     enemy;
    bool       fled = false;

    Inventory& inventory;

    void playerTurn();
    void enemyTurn();
};

#endif