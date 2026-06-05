#include "../combatHeader/oasisguard.h"
#include <iostream>

void OasisGuard::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Guardian Strike
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Healing Waters
        {
            user.changeHp(15);
            cout << skills.at(index).description << endl;
            cout << user.getName() << " restored 15 HP!" << endl;
            break;
        }
        case 2: // Sand Shield
        {            
            user.changeDef(2);
            cout << skills.at(index).description << endl;
            cout << user.getName() << "'s defense rose by 2!" << endl;
            break;
        }
        default:
            cout << user.getName() << " did nothing!" << endl;
            break;
    }
}