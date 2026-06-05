#ifndef MADKING_H
#define MADKING_H
#include "enemy.h"
using namespace std;

class MadKing : public Enemy {
public:                                  //hp atk def spd xp gld mAtk
    MadKing() : Enemy("The Mad Tyrant", 200, 16, 25, 10, 150, 120, 14) {
        phaseTwo = false;
        skills = {
            { "Royal Cleave", 1.4f, 0.0f, "The Mad Tyrant cleaves with a royal madness!", 5 },
            { "Mad Decree", 0.0f, 0.5f, "The Mad Tyrant issues a terrifying decree!", 3 },
            { "Cursed Crown", 0.0f, 1.6f, "The Mad Tyrant's crown releases cursed magic!", 3 },
            { "Tyrant's Judgment", 2.0f, 0.5f, "The Mad Tyrant judges you with overwhelming force!", 1 },
        };
    }

    void updatePhase() override;
    void useSkillEffect(int index, Character& user, Character& opponent) override;

private:
    bool phaseTwo;
};

#endif