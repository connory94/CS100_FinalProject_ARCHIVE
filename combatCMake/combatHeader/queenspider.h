#ifndef QUEENSPIDER_H
#define QUEENSPIDER_H
#include "enemy.h"
using namespace std;

class QueenSpider : public Enemy {
public:                                  //hp atk def spd xp gld mAtk
    QueenSpider() : Enemy("Spider Queen", 90, 8, 17, 5, 55, 45, 5) {
        phaseTwo = false;
        skills = {
            { "Corrosive Bite", 0.0f, 1.0f, "The Spider Queen bites you with its corrosive fangs!", 4 },
            { "Shredding Legs", 0.8f, 0.0f, "The Spider Queen rends at you and your defenses!", 2 },
            { "Binding Webs", 0.0f, 0.0f, "The Spider Queen wraps you in sticky webs!", 2 },
            { "Arachnid Defense", 0.0f, 0.0f, "The Spider Queen defends itself with its eight legs!", 1 },
        };
    }

    void updatePhase() override;
    void useSkillEffect(int index, Character& user, Character& opponent) override;

private:
    bool phaseTwo;
};

#endif