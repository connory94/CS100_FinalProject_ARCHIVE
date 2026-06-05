#ifndef KINGSLAND_H
#define KINGSLAND_H
#include <string>
#include <vector>
#include <iostream>
#include "Pathways.h"
#include "../Player/Player.h"
#include "../combatCMake/combatHeader/enemy.h"
#include "../combatCMake/combatHeader/gatekeeper.h"
#include "../combatCMake/combatHeader/villcultist.h"
#include "../combatCMake/combatHeader/madking.h"
#include "shop.h"
#include "../Player/HealthPotion.h"
#include "../Player/StrengthPotion.h"
#include "../Player/SpeedPotion.h"
#include "../Player/DefensePotion.h"
#include "../Player/Shield.h"
#include "../Player/Sword.h"
#include "../Player/Staff.h"
#include "../Player/Boots.h"


class KingsLand {
    private: 
        std::string name = "Kings Land";
        Pathways kingsPathways;

    public:
        KingsLand();
        std::string getName();
        void EnterKingsLand(Player &player, Pathways* &playerPath);
        bool mainPathsVisitedWithBoss();
        bool travelPathsVisited();
        Pathways* enterBossPath();
        Pathways* enterExitPath();
        Pathways& getKingPathways();
};


#endif //KINGSLAND_HPP 