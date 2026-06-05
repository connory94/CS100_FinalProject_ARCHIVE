#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include "skill.h"

using namespace std;

class Character {
public:
    Character(string name, int maxhp, int atk, int def, int spd, int magicAtk);
    string getName() const;
    int getHealth() const;
    int getMaxHealth() const;
    int getAttackPower() const;
    int getMagicAtk() const;
    int getDefense() const;
    int getSpeed() const;
    bool isAlive() const;

    void addSkill(const Skill& skill);
    const vector<Skill>& getSkills() const; // each character has a vector of skills they can use in combat
    // user  = the one using the skill (this enemy)
    // opponent = the one receiving it (the player)
    virtual void useSkillEffect(int index, Character& user, Character& opponent);

    void changeHp(int amount); // change HP by a certain amount
    void changeAtk(int amount); // change attack power by a certain amount
    void changeDef(int amount); // change defense by a certain amount
    void changeSpd(int amount); // change speed by a certain amount
    void changeAlive(bool status); // change alive status
    void changeMagicAtk(int amount); // change magic attack by a certain amount

    static int calculateDamage(const Character& user, const Skill& skill, const Character& opponent);
    static int rollCritical(int damage);

private:    
    string name;
    int maxHp;
    int hp;
    int atkPwr;
    int magicAtk;
    int def;
    int spd;
    bool alive;

protected:
    vector<Skill> skills;
};

#endif