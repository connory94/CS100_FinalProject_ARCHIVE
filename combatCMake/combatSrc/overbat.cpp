#include "../combatHeader/overbat.h"
#include <iostream>

void Overbat::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Swoop
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Screech
        {
            opponent.changeDef(-2);
            opponent.changeSpd(-1);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << "'s defense fell by 2!" << endl;
            cout << opponent.getName() << "'s speed fell by 1!" << endl;
            break;
        }
        case 2: // Diving Slash
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        default:
            cout << user.getName() << " did nothing!" << endl;
            break;
    }
}