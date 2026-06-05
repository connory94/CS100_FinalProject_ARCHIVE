#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
using namespace std;

class Enemy : public Character {
public:
    Enemy(string name, int maxhp, int atk, int def, int spd, int xp, int gold, int magicAtk);

    int xpReward()   const;
    int goldReward() const;
    int chooseSkill() const; // weighted random, returns skill index

    void useSkillEffect(int index, Character& user, Character& opponent) override;
    virtual void updatePhase(); // for bosses

    virtual ~Enemy() {}

private:
    int xp;
    int gold;
};

#endif