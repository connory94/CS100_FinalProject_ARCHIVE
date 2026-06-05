#ifndef SLIME_H
#define SLIME_H
#include "enemy.h"
using namespace std;

class Slime : public Enemy {
public:                   //hp atk def spd xp gold magicAtk
    Slime() : Enemy("Slime", 15, 5, 3, 5, 5, 10, 2) {
        skills = {
            { "Tackle",   1.0f, 0.0f, "It slams into you with its gelatinous body!",                    3 },
            { "Corrode",  0.0f, 1.0f, "It corrodes your armor, reducing your defense by 2!",            2 },
            { "Solidify", 0.0f, 0.0f, "It hardens itself, raising its defense but slowing it down!",    5 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif