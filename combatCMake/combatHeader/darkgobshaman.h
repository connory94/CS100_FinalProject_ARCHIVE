#ifndef DARKGOBSHAMAN_H
#define DARKGOBSHAMAN_H
#include "enemy.h"
using namespace std;

class DarkGobShaman : public Enemy {
public:                                       //hp atk def spd xp gld mAtk
    DarkGobShaman() : Enemy("Dark Goblin Shaman", 60, 5, 8, 10, 35, 30, 8) {
        phaseTwo = false;
        skills = {
            { "Harming Totem", 0.0f, 1.0f, "The Dark Goblin Shaman summons a harming totem!", 4 },
            { "Empowering Totem", 0.0f, 0.0f, "The Dark Goblin Shaman summons an empowering totem!", 2 },
            { "Cursing Totem", 0.0f, 0.0f, "The Dark Goblin Shaman summons a cursing totem!", 2 },
            { "Draining Totem", 0.0f, 0.5f, "The Dark Goblin Shaman summons a draining totem!", 1 },
        };
    }

    void updatePhase() override;
    void useSkillEffect(int index, Character& user, Character& opponent) override;

private:
    bool phaseTwo;
};

#endif