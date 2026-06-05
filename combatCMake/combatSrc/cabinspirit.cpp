#include "../combatHeader/cabinspirit.h"
#include <iostream>


void CabinSpirit::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Haunting Touch
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Dark Curse
        {
            opponent.changeDef(-1);
            opponent.changeAtk(-1);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << "'s defense and attack fell by 1!" << endl;
            break;
        }
        case 2: // Tortured Screech
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeMagicAtk(+2);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s magic attack rose by 2!" << endl;
            break;
        }
        default:
            cout << user.getName() << " did nothing!" << endl;
            break;
    }
}