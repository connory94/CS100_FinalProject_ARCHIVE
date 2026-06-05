#ifndef SANDWORM_H
#define SANDWORM_H

#include "enemy.h"
using namespace std;

class SandWorm : public Enemy {
public:                             //hp atk def spd xp gld mAtk
    SandWorm() : Enemy("Sand Worm", 100, 11, 5, 10, 45, 30, 3) {
        skills = {
            { "Burrowed Shockwaves", 1.2f, 0.0f, "It slams its tail from beneath the sand!", 5 },
            { "Sand Spray", 0.0f, 0.0f, "It sprays abrasive sand into the air!", 3 },
            { "Crushing Bite", 1.7f, 0.0f, "It surfaces and bites with its layered teeth!", 2 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif