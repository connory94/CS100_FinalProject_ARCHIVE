#include "../combatHeader/gobgrunt.h"
#include <iostream>

void GobGrunt::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Club Swing
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Cheap Shot
        {
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            opponent.changeDef(-2);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << opponent.getName() << "'s defense fell by 2!" << endl;
            break;
        }
        case 2: // Sharpen
        {
            user.changeAtk(+1);
            cout << skills.at(index).description << endl;
            cout << user.getName() << "'s attack rose by 1!" << endl;
            break;
        }
        default:
            cout << user.getName() << " did nothing!" << endl;
            break;
    }
}