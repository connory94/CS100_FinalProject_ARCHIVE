#include "../combatHeader/darkgobshaman.h"
#include <iostream>
void DarkGobShaman::updatePhase() {
    if (!phaseTwo && getHealth() <= getMaxHealth() / 2) {
        phaseTwo = true;
        cout << "With its staff destroyed, The Dark Goblin Shaman is enraged!" << endl;
        cout << "The Dark Goblin Shaman tears off its garbs, revealing a glowing spirit tattoo!" << endl;
        cout << "The enraged Shaman can now critically strike!" << endl;
        changeDef(-2);
        changeAtk(3);
        changeMagicAtk(-4);
        cout << "The enraged Shaman's attack rose by 3!" << endl;
        cout << "The enraged Shaman's magic attack fell by 4!" << endl;
        cout << "The enraged Shaman's defense fell by 2!" << endl; 

        skills = {
            { "Frenzied Rush", 1.5f, 0.5f, "The enraged Shaman charges with ferocity!", 4},
            { "Spirit Surge", 0.5f, 0.5f, "The enraged Shaman surges with spiritual power!", 2 },
            { "Cursed Eye", 0.0f, 0.5f, "The enraged Shaman glares at you with its cursed eye!", 2 },
            { "Vengeful Roar", 0.0f, 0.5f, "The enraged Shaman lets out a vengeful roar!", 1 },
        };
    }
}

void DarkGobShaman::useSkillEffect(int index, Character& user, Character& opponent) {

    if(!phaseTwo) {
        switch (index) { //phase 1 skills
            case 0: // Harming Totem
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                opponent.changeHp(-damage);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                break;
            }
            case 1: // Empowering Totem
            {
                user.changeMagicAtk(1);
                cout << skills.at(index).description << endl;
                cout << user.getName() << "'s magic attack rose by 1!" << endl;
                break;
            }
            case 2: // Cursing Totem
            {
                opponent.changeDef(-2);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << "'s defense fell by 2!" << endl;
                break;
            }
            case 3: // Draining Totem
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                opponent.changeHp(-damage);
                opponent.changeMagicAtk(-2);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s magic attack fell by 2!" << endl;
                break;
            }
            default:
                cout << user.getName() << " did nothing!" << endl;
                break;
        }
    } else {
        switch (index) { //phase 2 skills
            case 0: // Frenzied Rush
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                user.changeDef(-1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << user.getName() << "'s defense fell by 1!" << endl;
                break;
            }
            case 1: // Spirit Surge
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                user.changeAtk(1);
                user.changeDef(-1);
                user.changeMagicAtk(1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << user.getName() << "'s attack rose by 1!" << endl;
                cout << user.getName() << "'s magic attack rose by 1!" << endl;
                cout << user.getName() << "'s defense fell by 1!" << endl;
                break;
            }
            case 2: // Cursed Eye
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                opponent.changeAtk(-1);
                opponent.changeMagicAtk(-1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s attack fell by 1!" << endl;
                cout << opponent.getName() << "'s magic attack fell by 1!" << endl;
                break;
            }
            case 3: // Vengeful Roar
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                opponent.changeDef(-2);
                opponent.changeSpd(-2);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s defense fell by 2!" << endl;
                cout << opponent.getName() << "'s speed fell by 2!" << endl;
                break;
            }
            default:
                cout << user.getName() << " did nothing!" << endl;
                break;
        }
    }
}