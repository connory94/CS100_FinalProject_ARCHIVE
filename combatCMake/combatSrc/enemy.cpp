#include "../combatHeader/enemy.h"
#include <iostream>
#include <cstdlib> // rand()
#include <cassert> // assert()
using namespace std;

Enemy::Enemy(string name, int maxhp, int atk, int def, int spd, int xp, int gold, int magicAtk)
    : Character(name, maxhp, atk, def, spd, magicAtk), xp(xp), gold(gold) {}

int Enemy::xpReward()   const { return xp; }
int Enemy::goldReward() const { return gold; }

int Enemy::chooseSkill() const {
    const vector<Skill>& skills = getSkills();

    // Source - https://stackoverflow.com/a/1761646
    // Posted by Will, modified by community. See post 'Timeline' for change history
    // Retrieved 2026-05-20, License - CC BY-SA 3.0
    // weighted random selection of skill index based on the weight of the skill to emulate "ai"
    int sum_of_weight = 0;
    for (int i = 0; i < (int)skills.size(); i++)
        sum_of_weight += skills.at(i).weight;

    int rnd = rand() % sum_of_weight;

    for (int i = 0; i < (int)skills.size(); i++) {
        if (rnd < skills.at(i).weight)
            return i;
        rnd -= skills.at(i).weight;
    }

    assert(!"should never get here");
    return 0;
}

//this function shouldnt ever be called
void Enemy::useSkillEffect(int index, Character& user, Character& opponent) {
        cout << user.getName() << " fumbles!" << endl;
    }

void Enemy::updatePhase() {}