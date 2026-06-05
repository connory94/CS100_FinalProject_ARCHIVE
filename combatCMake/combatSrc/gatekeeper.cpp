#include "../combatHeader/gatekeeper.h"
#include <iostream>

void GateKeeper::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Halberd Thrust
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Shield Bash
        {
            cout << user.getName() << ": \"Back off!\"" << endl;
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            opponent.changeSpd(-1);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << opponent.getName() << "'s speed fell by 1!" << endl;
            break;
        }
        case 2: // Defensive Stance
        {
            user.changeDef(3);
            cout << skills.at(index).description << endl;
            cout << user.getName() << "'s defense rose by 3!" << endl;
            break;
        }
        case 3: // Gate Crash
        {
            cout << user.getName() << ": \"You asked for it!\"" << endl;
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