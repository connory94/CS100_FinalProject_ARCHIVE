#ifndef COMBATDISPLAY_H
#define COMBATDISPLAY_H
#include "character.h"
#include "enemy.h"
#include "skill.h"
#include "../../Player/Inventory.h"
#include <vector>
#include <string>
using namespace std;

class CombatDisplay {
public:
    static void showAppeared(const Enemy& enemy);
    static void showStatus(const Character& player, const Enemy& enemy);
    static void showCombatOptions();
    static void showRanAway();
    static void showSkillMenu(const vector<Skill>& skills);
    static void showSkillUsed(const string& characterName, const string& skillName);
    static void showFled();
    static void showVictory(const Enemy& enemy);
    static void showDefeat();

    static void showInventoryMenu(const Inventory& inventory);
    static void showItemUsed(const string& characterName, const string& itemName);
    static void showCannotUseItem(const string& itemName);
};

#endif