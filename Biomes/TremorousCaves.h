#ifndef TREMOROUSCAVES_H
#define TREMOROUSCAVES_H
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "Pathways.h"
#include "../Player/Player.h"
#include "../combatCMake/combatHeader/enemy.h"
#include "../combatCMake/combatHeader/overbat.h"
#include "../combatCMake/combatHeader/crygolem.h"
#include "../combatCMake/combatHeader/queenspider.h"
#include "shop.h"
#include "../Player/HealthPotion.h"
#include "../Player/StrengthPotion.h"
#include "../Player/SpeedPotion.h"
#include "../Player/DefensePotion.h"
#include "../Player/Shield.h"
#include "../Player/Sword.h"
#include "../Player/Staff.h"
#include "../Player/Boots.h"
#include <random>

class TremorousCaves {
    private: 
        std::string name = "Tremorous Caves";
        Pathways tremorousPathways;

    public:
        TremorousCaves();
        std::string getName();
        void caveShake(Player &player);
        void EnterCaves(Player &player, Pathways* &playerPath);
        bool mainPathsVisitedWithBoss();
        bool travelPathsVisited();
        Pathways* enterBossPath();
        Pathways* enterExitPath();
        Pathways& getCavePathways();
};


#endif //TREMOROUSCAVES_H