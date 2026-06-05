#include "../combatHeader/slime.h"
#include <iostream>
using namespace std;

void Slime::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Tackle — deals damage to opponent
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Corrode — debuffs opponent's defense and deals damage
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            opponent.changeDef(-2);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << "'s defense fell by 2!" << endl;
            break;
        }
        case 2: // Solidify — buffs user's defense, lowers user's speed 
        {
            user.changeDef(+2);
            user.changeSpd(-1);
            cout << skills.at(index).description << endl;
            cout << user.getName() << "'s defense rose by 2 and speed fell by 1!" << endl;
            break;
        }
        default:
            cout << user.getName() << " did nothing!" << endl;
            break;
    }
}