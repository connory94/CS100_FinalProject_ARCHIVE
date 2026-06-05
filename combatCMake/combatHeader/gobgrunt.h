#ifndef GOBGRUNT_H
#define GOBGRUNT_H
#include "enemy.h"
using namespace std;

class GobGrunt : public Enemy {
public:                             //hp atk def spd xp gld mAtk
    GobGrunt() : Enemy("Goblin Grunt", 22, 5, 4, 5, 5, 10, 2) {
        skills = {
            { "Club Swing",   1.0f, 0.0f, "It swings its club at you!",                       5 },
            { "Cheap Shot",  0.5f, 0.5f, "It goes for a dirty strike, reducing your defense!",    2 },
            { "Sharpen", 0.0f, 0.0f, "It sharpens its knife, increasing its attack!",           3 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif