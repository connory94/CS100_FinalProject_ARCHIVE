#include "../combatHeader/crygolem.h"
#include <iostream>

void Crygolem::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Crystal Force
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Gleaming Defenses
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            user.changeDef(1);
            opponent.changeHp(-damage);
            opponent.changeSpd(-1);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << opponent.getName() << "'s speed fell by 1!" << endl;
            cout << user.getName() << "'s defense rose by 1!" << endl;
            break;
        }
        case 2: // Gemstone Smash
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