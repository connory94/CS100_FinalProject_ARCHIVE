#include "../combatHeader/combatdisplay.h"
#include <iostream>
using namespace std;

void CombatDisplay::showAppeared(const Enemy& enemy) {
    cout << "A wild " << enemy.getName() << " appeared!" << endl;
}

void CombatDisplay::showStatus(const Character& player, const Enemy& enemy) {
    cout << endl;
    cout << "====================" << endl;
    cout << player.getName() << " HP: "
         << player.getHealth() << "/" << player.getMaxHealth() << endl;
    cout << enemy.getName()  << " HP: "
         << enemy.getHealth()  << "/" << enemy.getMaxHealth()  << endl;
    cout << "====================" << endl;
    cout << endl;
}

void CombatDisplay::showCombatOptions() {
    cout << "Choose an action:" << endl;
    cout << "1. Fight" << endl;
    cout << "2. Run"   << endl;
    cout << "3. Item"  << endl;
    cout << "Choice: ";
}

void CombatDisplay::showInventoryMenu(const Inventory& inventory) {
    const vector<Item*>& items = inventory.getItems();

    cout << endl << "Inventory:" << endl;
    if (items.empty()) {
        cout << "No items in inventory." << endl;
    } else {
        for (int i = 0; i < (int)items.size(); i++) {
            cout << i + 1 << ". " << items.at(i)->getName() << endl;
        }
    }
    cout << "0. Back" << endl;
    cout << "Choice: ";
}

void CombatDisplay::showItemUsed(const string& characterName, const string& itemName) {
    cout << endl;
    cout << characterName << " used " << itemName << "!" << endl;
}

void CombatDisplay::showCannotUseItem(const string& itemName) {
    cout << itemName << " is not consumable and cannot be used in battle." << endl;
}

void CombatDisplay::showRanAway() {
    cout << "You ran away!" << endl;
}

void CombatDisplay::showSkillMenu(const vector<Skill>& skills) {
    cout << endl << "Choose a skill:" << endl;
    for (int i = 0; i < (int)skills.size(); i++)
        cout << i + 1 << ". " << skills.at(i).name << endl;
    cout << "Choice: ";
}

void CombatDisplay::showSkillUsed(const string& characterName, const string& skillName) {
    cout << endl;
    cout << characterName << " used " << skillName << "!" << endl << endl;
}

void CombatDisplay::showFled() {
    cout << "You escaped safely." << endl << endl;
}

void CombatDisplay::showVictory(const Enemy& enemy) {
    cout << "You defeated the " << enemy.getName() << "!" << endl;
    cout << "You gained " << enemy.xpReward() << " XP and "
                          << enemy.goldReward() << " gold." << endl << endl;
}

void CombatDisplay::showDefeat() {
    cout << "You were defeated..." << endl;
}