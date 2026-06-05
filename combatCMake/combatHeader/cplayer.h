#ifndef CPLAYER_H
#define CPLAYER_H
#include "character.h"
#include <vector>
using namespace std;

class cPlayer : public Character {
public:
    // unlockedIndices passes in the indices of skills that are gained outside of combat
    // determined by exploration, leveling etc
    cPlayer(string name, int hp, int maxhp, int atk, int def, int spd, int magicAtk, vector<int> unlockedIndices);

    void useSkillEffect(int index, Character& user, Character& opponent) override;
    vector<Skill> getUnlockedSkills() const;

private:
    // database of all unlockable skills to be called during combat, works with unlockedIndices to determine what the player can use
    vector<Skill> allSkills;

    // Set once at construction
    vector<int> unlockedIndices;
};

#endif