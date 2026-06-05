#ifndef OVERBAT_H
#define OVERBAT_H

#include "enemy.h"
using namespace std;

class Overbat : public Enemy {
public:                             //hp atk def spd xp gld mAtk
    Overbat() : Enemy("Overgrown Bat", 45, 7, 3, 14, 20, 15, 3) {
        skills = {
            { "Swoop",   1.0f, 0.0f, "It swoops down to strike you!",        6 },
            { "Screech",  0.0f, 1.0f, "It screeches loudly, dazing you!",    3 },
            { "Diving Slash", 1.5f, 0.0f, "It dives down with its claws!",   3 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif