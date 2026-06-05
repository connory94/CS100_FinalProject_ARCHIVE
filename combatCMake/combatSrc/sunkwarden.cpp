#include "../combatHeader/sunkwarden.h"
#include <iostream>

void Sunkwarden::updatePhase() {
    if (!phaseTwo && getHealth() <= getMaxHealth() / 2) {
        phaseTwo = true;
        cout << "The Remnant's armor shatters and dissolves into the sand, revealing its full skeletal form!" << endl;
        cout << "A cursed flame burns from inside its ribcage, enveloping its entire body!" << endl;
        cout << "Freed from its prison of armor, the unleashed Remnant cackles in delight!" << endl;

        changeDef(-5);
        changeAtk(3);
        changeSpd(4);
        changeMagicAtk(2);

        cout << getName() << "'s defense fell by 5!" << endl;
        cout << getName() << "'s attack rose by 3!" << endl;
        cout << getName() << "'s speed rose by 4!" << endl;
        cout << getName() << "'s magic attack rose by 2!" << endl;

        skills = {
            { "Cursed Blade", 1.5f, 0.5f, "The unleashed Remnant attacks with a blade covered in cursed flame!", 5 },
            { "Bone Rush", 1.8f, 0.0f, "The unleashed Remnant rushes forward with unnatural speed!", 3 },
            { "Deathless Rage", 0.0f, 0.0f, "The unleashed Remnant's cursed spirit grows stronger!", 2 },
            { "Burial Sentence", 2.3f, 0.5f, "The unleashed Remnant marks you for burial beneath the sand!", 1 },
        };
    }
}

void Sunkwarden::useSkillEffect(int index, Character& user, Character& opponent) {

    if(!phaseTwo) {
        switch (index) { //phase 1 skills
            case 0: // Rusted Slash
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                opponent.changeHp(-damage);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                break;
            }
            case 1: // Shield of Bones
            {
                user.changeDef(2);
                cout << skills.at(index).description << endl;
                cout << user.getName() << "'s defense rose by 2!" << endl;
                break;
            }
            case 2: // Grave Pressure
            {
                opponent.changeAtk(-1);
                opponent.changeMagicAtk(-1);
                opponent.changeDef(-1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << "'s attack fell by 1!" << endl;
                cout << opponent.getName() << "'s magic attack fell by 1!" << endl;
                cout << opponent.getName() << "'s defense fell by 1!" << endl;
                break;
            }
            case 3: // Ravine Cleave
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                opponent.changeHp(-damage);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                break;
            }
            default:
                cout << user.getName() << " did nothing!" << endl;
                break;
        }
    } else {
        switch (index) { //phase 2 skills
            case 0: // Cursed Blade
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                break;
            }
            case 1: // Bone Rush
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                user.changeSpd(1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << user.getName() << "'s speed rose by 1!" << endl;
                break;
            }
            case 2: // Deathless Rage
            {
                user.changeAtk(1);
                user.changeDef(-1);
                user.changeMagicAtk(1);
                cout << skills.at(index).description << endl;
                cout << user.getName() << "'s attack rose by 1!" << endl;
                cout << user.getName() << "'s defense fell by 1!" << endl;
                cout << user.getName() << "'s magic attack rose by 1!" << endl;
                break;
            }
            case 3: // Burial Sentence
            {
                int reboundDamage = Character::calculateDamage(user, skills.at(index), opponent) / 2;
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                opponent.changeHp(-damage);
                opponent.changeSpd(-3);
                user.changeHp(-reboundDamage);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s speed fell by 3!" << endl;
                cout << user.getName() << " took " << reboundDamage << " damage from the cursed backlash!" << endl;
                break;
            }
            default:
                cout << user.getName() << " did nothing!" << endl;
                break;
        }
    }
}