#ifndef SKILL_H
#define SKILL_H
#include <string>
using namespace std;

struct Skill {
    string name;
    float  atkMultiplier;   // multiplied against user's atkPwr for physical damage
    float  magicMultiplier; // multiplied against user's magicAtk for magic damage
    string description; //description of skill effect, for players it describes the skill from their perspective e.g. "you charge into them"
    //for enemies, the description describes the skill from the player's perspective e.g. "it hits you six sevenuinely"
    int weight = 1; // skill weight for random selection, default is 1
};

#endif