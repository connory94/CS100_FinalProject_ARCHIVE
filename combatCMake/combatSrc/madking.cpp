#include "../combatHeader/madking.h"
#include <iostream>

void MadKing::updatePhase() {
    if (!phaseTwo && getHealth() <= getMaxHealth() / 2) {
        phaseTwo = true;
        cout << getName() << ": \"No!\"" << endl;
        cout << "The Mad Tyrant clutches his head and lets out a broken scream!" << endl;
        cout << "His thoughts collapse under the weight of the cursed crown." << endl;
        cout << "The crown glows with a terrible light, taking control of his empty body!" << endl;
        cout << "Now a vessel for the cursed crown, the Hollow King towers above you." << endl;

        changeAtk(2);
        changeMagicAtk(5);
        changeSpd(3);
        changeDef(-5);

        cout << getName() << "'s attack rose by 2!" << endl;
        cout << getName() << "'s magic attack rose by 5!" << endl;
        cout << getName() << "'s speed rose by 3!" << endl;
        cout << getName() << "'s defense fell by 5!" << endl;

        skills = {
            { "Decree of Violence", 1.0f, 1.5f, "The crown imposes its will upon you with a command!", 5 },
            { "Decree of Lethargy", 0.0f, 0.3f, "The crown imposes its will upon you with a command!", 3 },
            { "Decree of Despair", 0.0f, 2.2f, "The crown imposes its will upon you with a command!", 2 },
            { "Decree of Final Judgment", 1.5f, 2.5f, "The crown imposes its will upon you with a command!", 1 },
        };
    }
}

void MadKing::useSkillEffect(int index, Character& user, Character& opponent) {

    if(!phaseTwo) {
        switch (index) { //phase 1 skills
            case 0: // Royal Cleave
            {
                cout << user.getName() << ": \"Out of my sight!\"" << endl;
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                break;
            }
            case 1: // Mad Decree
            {
                cout << user.getName() << ": \"I declare that you must kneel!\"" << endl;
                opponent.changeAtk(-2);
                opponent.changeSpd(-1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << "'s attack fell by 2!" << endl;
                cout << opponent.getName() << "'s speed fell by 1!" << endl;
                break;
            }
            case 2: // Cursed Crown
            {
                cout << user.getName() << ": \"Silence... the crown whispers...\"" << endl;
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                opponent.changeDef(-2);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s defense fell by 2!" << endl;
                break;
            }
            case 3: // Tyrant's Judgment
            {
                cout << user.getName() << ": \"You dare cross me?!?\"" << endl;
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                user.changeDef(3);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << user.getName() << "'s defense rose by 3!" << endl;
                break;
            }
            default:
                cout << user.getName() << " did nothing!" << endl;
                break;
        }
    } else {
        switch (index) { //phase 2 skills
            case 0: // Decree of Violence
            {
                cout << user.getName() << ": \"THIS ONE DECLARES YOUR INJURY.\"" << endl;
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                break;
            }
            case 1: // Decree of Lethargy
            {
                cout << user.getName() << ": \"THIS ONE DECLARES YOUR CRIPPLING.\"" << endl;
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
            case 2: // Decree of Despair
            {
                cout << user.getName() << ": \"THIS ONE DECLARES YOUR DESPAIR.\"" << endl;
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                opponent.changeAtk(-3);
                opponent.changeMagicAtk(-3);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s attack fell by 3!" << endl;
                cout << opponent.getName() << "'s magic attack fell by 3!" << endl;
                break;
            }
            case 3: // Decree of Final Judgment
            {
                cout << user.getName() << ": \"THIS ONE DECLARES YOUR CONCLUSION.\"" << endl;
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
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
}