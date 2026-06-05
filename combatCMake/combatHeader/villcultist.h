#ifndef VILLCULTIST_H
#define VILLCULTIST_H

#include "enemy.h"
using namespace std;

class VillCultist : public Enemy {
public:                                     //hp atk def spd xp gld mAtk
    VillCultist() : Enemy("Villager Cultist", 125, 10, 16, 10, 70, 50, 12) {
        skills = {
            { "Ritual Dagger", 1.0f, 0.5f, "The Villager Cultist slashes you with a ritual dagger!", 5 },
            { "Mad Chant", 0.0f, 0.0f, "The Villager Cultist chants praises to the Mad King!", 3 },
            { "Cursed Offering", 0.0f, 1.5f, "The Villager Cultist offers its pain to dark magic!", 2 },
            { "Fanatic Frenzy", 1.6f, 0.0f, "The Villager Cultist attacks with fanatical frenzy!", 1 },
        };
    }

    void useSkillEffect(int index, Character& user, Character& opponent) override;
};

#endif