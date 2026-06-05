#include "../combatHeader/combat.h"
#include "../combatHeader/combatdisplay.h"
#include <iostream>

Combat::Combat(cPlayer& player, Enemy& enemy, Inventory& inventory)
    : player(player), enemy(enemy), inventory(inventory) {}

void Combat::startCombat() {
    CombatDisplay::showAppeared(enemy);

    while (player.isAlive() && enemy.isAlive() && !fled) {
        CombatDisplay::showStatus(player, enemy);

        if (playerGoesFirst(player, enemy)) {
            playerTurn();

            if (fled || !player.isAlive() || !enemy.isAlive()) {
                break;
            }

            enemyTurn();
        } else {
            enemyTurn();

            if (fled || !player.isAlive() || !enemy.isAlive()) {
                break;
            }

            playerTurn();
        }
    }

    if (fled) {
        CombatDisplay::showFled();
    } else if (player.isAlive() && !enemy.isAlive()) {
        CombatDisplay::showVictory(enemy);
    } else {
        CombatDisplay::showDefeat();
    }
}

bool Combat::playerGoesFirst(const cPlayer& player, const Enemy& enemy) const {
    return player.getSpeed() >= enemy.getSpeed();
}

bool Combat::playerWon() const {
    return player.isAlive() && !enemy.isAlive() && !fled;
}

bool Combat::playerFled() const {
    return fled;
}

void Combat::playerTurn() {
    while (!fled) {
        int choice;
        CombatDisplay::showCombatOptions();
        cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3) {
            cout << "Invalid choice. Enter 1 to fight, 2 to run, or 3 to open inventory: ";
            cin >> choice;
            cout << endl;
        }

        if (choice == 2) {
            CombatDisplay::showRanAway();
            fled = true;
            return;
        }

        if (choice == 3) {
            if (openInventory(player, inventory)) {
                return;
            }
        } else {
            vector<Skill> unlockedSkills = player.getUnlockedSkills();
            CombatDisplay::showSkillMenu(unlockedSkills);

            int skillChoice;
            cin >> skillChoice;
            while (skillChoice < 1 || skillChoice > (int)unlockedSkills.size()) {
                cout << "Invalid skill. Choose again: ";
                cin >> skillChoice;
            }

            int skillIndex = skillChoice - 1;
            CombatDisplay::showSkillUsed(player.getName(), unlockedSkills.at(skillIndex).name);
            player.useSkillEffect(skillIndex, player, enemy);
            return;
        }
    }
}

void Combat::enemyTurn() {
    if (fled || !player.isAlive() || !enemy.isAlive()) {
        return;
    }

    enemy.updatePhase();
    int skillIndex = enemy.chooseSkill();
    CombatDisplay::showSkillUsed(enemy.getName(), enemy.getSkills().at(skillIndex).name);
    enemy.useSkillEffect(skillIndex, enemy, player);
}

// https://stackoverflow.com/questions/63084831/understanding-stringfind-in-c <- used this site for item usage implementation
// checks for potion in the item name so that permanent stat boosts like the boots cant be used
// originally i had a for loop that checked for potion in the string but i wanted an easier solution so i got the .find method

bool Combat::isPotion(const string& itemName) {
    return itemName.find("Potion") != string::npos;
}

bool Combat::usePotion(const string& itemName, cPlayer& player, Inventory& inventory) {
    if(!isPotion(itemName)) {
        CombatDisplay::showCannotUseItem(itemName);
        return false;
    }

    CombatDisplay::showItemUsed(player.getName(), itemName);

    if(itemName.find("Health") != string::npos) {
        int healAmount = player.getMaxHealth() / 2;
        player.changeHp(healAmount);
        cout << player.getName() << " recovered " << healAmount << " HP!" << endl;
    } else if(itemName.find("Strength") != string::npos) {
        player.changeAtk(5);
        cout << player.getName() << "'s attack rose by 5!" << endl;
    } else if(itemName.find("Defense") != string::npos) {
        player.changeDef(5);
        cout << player.getName() << "'s defense rose by 5!" << endl;
    } else if(itemName.find("Speed") != string::npos) {
        player.changeSpd(3);
        cout << player.getName() << "'s speed rose by 3!" << endl;
    }

    inventory.removeItem(itemName);
    return true;
}

bool Combat::openInventory(cPlayer& player, Inventory& inventory) {
    const vector<Item*>& items = inventory.getItems();

    CombatDisplay::showInventoryMenu(inventory);

    int itemChoice;
    cin >> itemChoice;
    while (itemChoice < 0 || itemChoice > (int)items.size()) {
        cout << "Invalid item. Choose again: ";
        cin >> itemChoice;
    }

    if (itemChoice == 0) {
        return false;
    }

    string itemName = items.at(itemChoice - 1)->getName();
    return usePotion(itemName, player, inventory);
}