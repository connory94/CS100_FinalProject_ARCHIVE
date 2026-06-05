#ifndef SUNKWARDEN_H
#define SUNKWARDEN_H
#include "enemy.h"
using namespace std;

class Sunkwarden : public Enemy {
public:                                     //hp atk def spd xp gld mAtk
    Sunkwarden() : Enemy("Ravine's Remnant", 120, 12, 20, 8, 80, 60, 7) {
        phaseTwo = false;
        skills = {
            { "Rusted Slash", 1.3f, 0.0f, "The Kingdom's Remnant slashes with its rusted blade!", 5 },
            { "Shield of Bones", 0.0f, 0.0f, "The Kingdom's Remnant raises a shield made of ancient bones!", 3 },
            { "Grave Pressure", 0.0f, 0.0f, "The Kingdom's Remnant weakens your fighting spirit!", 3 },
            { "Ravine Cleave", 1.7f, 0.0f, "The Kingdom's Remnant cleaves at you with the weight of a buried kingdom!", 2 },
        };
    }

    void updatePhase() override;
    void useSkillEffect(int index, Character& user, Character& opponent) override;

private:
    bool phaseTwo;
};

#endif