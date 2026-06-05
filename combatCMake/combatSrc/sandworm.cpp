#include "../combatHeader/sandworm.h"
#include <iostream>

void SandWorm::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Burrowed Shockwaves
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Sand Spray
        {
            opponent.changeSpd(-2);
            opponent.changeDef(-2);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << "'s speed fell by 2!" << endl;
            cout << opponent.getName() << "'s defense fell by 2!" << endl;
            break;
        }
        case 2: // Crushing Bite
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeDef(-2);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s defense fell by 2!" << endl;
            break;
        }
        default:
            cout << user.getName() << " did nothing!" << endl;
            break;
    }
}