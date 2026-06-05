#include "../combatHeader/villcultist.h"
#include <iostream>

void VillCultist::useSkillEffect(int index, Character& user, Character& opponent) {
    switch (index) {
        case 0: // Ritual Dagger
        {
            cout << user.getName() << ": \"Give me your blood!\"" << endl;
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            opponent.changeDef(-1);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << opponent.getName() << "'s defense fell by 1!" << endl;
            break;
        }
        case 1: // Mad Chant
        {
            cout << user.getName() << ": \"Praise be, o' King!\"" << endl;
            user.changeAtk(2);
            cout << skills.at(index).description << endl;
            cout << user.getName() << "'s attack rose by 2!" << endl;
            break;
        }
        case 2: // Cursed Offering
        {
            cout << user.getName() << ": \"In exchange of my blood, maim my enemies!\"" << endl;
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeHp(-10);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << " took 10 damage!" << endl;
            break;
        }
        case 3: // Fanatic Frenzy
        {
            cout << user.getName() << ": \"Ha ha ha ha!\"" << endl;
            int damage = Character::calculateDamage(user, skills.at(index), opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeAtk(1);
            user.changeDef(-1);
            cout << skills.at(index).description << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s attack rose by 1!" << endl;
            cout << user.getName() << "'s defense fell by 1!" << endl;
            break;
        }
        default:
            cout << user.getName() << " did nothing!" << endl;
            break;
    }
}