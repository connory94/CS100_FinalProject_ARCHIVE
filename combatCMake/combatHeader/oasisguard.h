#ifndef OASISGUARD_H
#define OASISGUARD_H

#include "enemy.h"
using namespace std;

class OasisGuard : public Enemy {
public:                                 //hp atk def spd xp gld mAtk
    OasisGuard() : Enemy("Oasis Guardian", 80, 7, 15, 6, 35, 25, 6) {
        skills = {
            { "Guardian Strike", 1.1f, 0.0f, "It strikes with ancient force!", 5 },
            { "Healing Waters", 0.0f, 0.0f, "It draws strength from the oasis!", 2 },
            { "Sand Shield", 0.0f, 0.0f, "Sand gathers around the Oasis Guardian!", 3 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif