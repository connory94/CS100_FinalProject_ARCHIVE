#ifndef GATEKEEPER_H
#define GATEKEEPER_H

#include "enemy.h"
using namespace std;

class GateKeeper : public Enemy {
public:                                //hp atk def spd xp gld mAtk
    GateKeeper() : Enemy("Gate Keeper", 115, 13, 18, 6, 65, 45, 3) {
        skills = {
            { "Halberd Thrust", 1.2f, 0.0f, "The Gate Keeper thrusts forward with a halberd!", 5 },
            { "Shield Bash", 1.0f, 0.0f, "The Gate Keeper slams you with its shield!", 3 },
            { "Defensive Stance", 0.0f, 0.0f, "The Gate Keeper braces behind its armor!", 3 },
            { "Gate Crash", 1.7f, 0.0f, "The Gate Keeper crashes down on you!", 1 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif