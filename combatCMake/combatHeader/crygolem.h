#ifndef CRYGOLEM_H
#define CRYGOLEM_H

#include "enemy.h"
using namespace std;

class Crygolem : public Enemy {
public:                             //hp atk def spd xp gld mAtk
    Crygolem() : Enemy("Crystal Golem", 70, 8, 13, 4, 25, 20, 2) {
        skills = {
            { "Crystal Force", 1.2f, 0.0f, "It bludgeons you with its crystalized fists!", 6 },
            { "Gleaming Defenses", 0.0f, 1.0f, "Its crystals glow with a magical light!", 4 },
            { "Gemstone Smash", 1.5f, 1.0f, "It smashes you with a crystalline hammer!", 2 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif