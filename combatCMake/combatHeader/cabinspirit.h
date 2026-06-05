#ifndef CABINSPIRIT_H
#define CABINSPIRIT_H
#include "enemy.h"

using namespace std;

class CabinSpirit : public Enemy {
public:                                //hp atk def spd xp gld mAtk
    CabinSpirit() : Enemy("Cabin Spirit", 36, 3, 4, 4, 10, 15, 6) {
        skills = { 
            { "Haunting Touch", 0.0f, 1.2f, "The entity reaches out at you with a chilling touch.", 5 },
            { "Dark Curse", 0.0f, 0.0f, "The entity curses you and weakens your defense and power!", 3 },
            { "Tortured Screech", 0.0f, 1.5f, "The entity screeches, damaging you and increasing its magic attack!", 2 } 
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif