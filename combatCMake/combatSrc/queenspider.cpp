#include "../combatHeader/queenspider.h"
#include <iostream>

void QueenSpider::updatePhase() {
    if (!phaseTwo && getHealth() <= getMaxHealth() / 2) {
        phaseTwo = true;
        cout << "Backed in a corner, the Spider Queen spews its webs across the battlefield!" << endl;
        cout << "The Spider Queen begins to shed its exoskeleton, beginning to molt!" << endl;
        cout << "The renewed Spider Queen emerges from its shedded skin, revealing a more aggressive but vulnerable form!" << endl;
        changeSpd(9);
        changeDef(-7);
        changeAtk(2);
        cout << getName() << "'s speed rose by 9!" << endl;
        cout << getName() << "'s defense fell by 7!" << endl;
        cout << getName() << "'s attack rose by 2!" << endl;

        skills = {
            { "Renewed Fang", 1.3f, 0.0f, "The renewed Spider Queen lunges at you!", 5},
            { "Renewed Claw", 1.0f, 0.0f, "The renewed Spider Queen lashes out with its renewed claws!", 3 },
            { "Renewed Cry", 0.0f, 0.0f, "The renewed Spider Queen lets out a piercing screech!", 2 },
            { "Renewed Hunger", 0.0f, 0.0f, "The renewed Spider Queen feeds on its shedded exoskeleton!", 1 },
        };
    }
}

void QueenSpider::useSkillEffect(int index, Character& user, Character& opponent) {

    if(!phaseTwo) {
        switch (index) { //phase 1 skills
            case 0: // Corrosive Bite
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                opponent.changeDef(-1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s defense fell by 1!" << endl;
                break;
            }
            case 1: // Shredding Legs
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                opponent.changeDef(-1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s defense fell by 1!" << endl;
                break;
            }
            case 2: // Binding Webs
            {
                opponent.changeSpd(-3);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << "'s speed fell by 3!" << endl;
                break;
            }
            case 3: // Arachnid Defense
            {
                user.changeDef(2);
                cout << skills.at(index).description << endl;
                cout << user.getName() << "'s defense rose by 2!" << endl;
                break;
            }
        }
    } else {
        switch (index) { //phase 2 skills
            case 0: // Renewed Fang
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                user.changeAtk(+1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << user.getName() << "'s attack rose by 1!" << endl;
                break;
            }
            case 1: // Renewed Claw
            {
                int damage = Character::calculateDamage(user, skills.at(index), opponent);
                damage = Character::rollCritical(damage);
                opponent.changeHp(-damage);
                opponent.changeDef(-1);
                user.changeAtk(+1);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << " took " << damage << " damage!" << endl;
                cout << opponent.getName() << "'s defense fell by 1!" << endl;
                cout << user.getName() << "'s attack rose by 1!" << endl;
                break;
            }
            case 2: // Renewed Cry
            {
                opponent.changeDef(-1);
                opponent.changeSpd(-1);
                user.changeAtk(+2);
                cout << skills.at(index).description << endl;
                cout << opponent.getName() << "'s defense fell by 1!" << endl;
                cout << opponent.getName() << "'s speed fell by 1!" << endl;
                cout << user.getName() << "'s attack rose by 2!" << endl;
                break;
            }
            case 3: // Renewed Hunger
            {
                user.changeHp(10);
                user.changeAtk(+2);
                cout << skills.at(index).description << endl;
                cout << user.getName() << " restored 10 HP!" << endl;
                cout << user.getName() << "'s attack rose by 2!" << endl;
                break;
            }
        }
    }
}