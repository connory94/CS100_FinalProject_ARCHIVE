#include "../combatHeader/character.h"
#include <iostream>
Character::Character(string name, int maxhp, int atk, int def, int spd, int magicAtk) {
    this->name = name;
    this->maxHp = maxhp;
    this->hp = maxhp;
    this->atkPwr = atk;
    this->def = def;
    this->magicAtk = magicAtk;
    this->spd = spd;
    this->alive = true;
}

string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return hp;
}

int Character::getMaxHealth() const {
    return maxHp;
}

int Character::getAttackPower() const {
    return atkPwr;
}

int Character::getDefense() const {
    return def;
}

int Character::getSpeed() const {
    return spd;
}

int Character::getMagicAtk() const {
    return magicAtk;
}

bool Character::isAlive() const {
    return alive;
}

void Character::addSkill(const Skill& skill) {
    skills.push_back(skill);
}

const vector<Skill>& Character::getSkills() const {
    return skills;
}

void Character::changeHp(int amount) {
    hp += amount;

    if (hp > maxHp) {
        hp = maxHp;
    }

    if (hp <= 0) {
        hp = 0;
        alive = false;
    }
}

void Character::changeAtk(int amount) {
    atkPwr += amount;

    if (atkPwr < 1) {
        atkPwr = 1; // attack power should not drop below 1 to prevent combat loops where neither side can damage the other
    }
}

void Character::changeMagicAtk(int amount) {
    magicAtk += amount;

    if (magicAtk < 1) {
        magicAtk = 1; // magic attack should not drop below 1
    }
}

void Character::changeDef(int amount) {
    def += amount;

    if (def < 0) {
        def = 0;
    }
}

void Character::changeSpd(int amount) {
    spd += amount;

    if (spd < 0) {
        spd = 0;
    }
}

void Character::changeAlive(bool status) {
    alive = status;
}

// Base implementation as a backup in case subclasses dont override
void Character::useSkillEffect(int index, Character& user, Character& opponent) {
    std::cout << user.getName() << " used " << user.getSkills().at(index).name
         << ", but nothing happened!" << std::endl;
}

int Character::calculateDamage(const Character& user, const Skill& skill, const Character& opponent) {
    int damage = (int)(user.getAttackPower() * skill.atkMultiplier) + (int)(user.getMagicAtk() * skill.magicMultiplier) - opponent.getDefense();
    if (damage < 1) damage = 1;
    return damage;
}

int Character::rollCritical(int damage) {
    if (rand() % 10 == 0) { //always 10% chance to crit
        std::cout << "Critical Hit!" << std::endl;
        if ( (int)(damage * 1.25f) == damage) { // if damage is too low, guarantee at least 1 extra damage on crit
            return damage + 1;
        }
        return (int)(damage * 1.25f);
    }
    return damage;
}
