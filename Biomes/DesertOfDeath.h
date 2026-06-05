#ifndef DESERTOFDEATH_H
#define DESERTOFDEATH_H
#include <string>
#include <vector>
#include <iostream>
#include "Pathways.h"
#include "../Player/Player.h"
#include "../combatCMake/combatHeader/enemy.h"
#include "../combatCMake/combatHeader/oasisguard.h"
#include "../combatCMake/combatHeader/sandworm.h"
#include "../combatCMake/combatHeader/sunkwarden.h"
#include "shop.h"
#include "../Player/HealthPotion.h"
#include "../Player/StrengthPotion.h"
#include "../Player/SpeedPotion.h"
#include "../Player/DefensePotion.h"
#include "../Player/Shield.h"
#include "../Player/Sword.h"
#include "../Player/Staff.h"
#include "../Player/Boots.h"



class DesertOfDeath {
    private: 
        std::string name = "Desert of Death";
        Pathways desertPathways;

    public:
        DesertOfDeath();
        std::string getName();
        void desertDamage(Player &player);
        void EnterDesert(Player &player, Pathways* &playerPath);
        bool mainPathsVisitedWithBoss();
        bool travelPathsVisited();
        Pathways* enterBossPath();
        Pathways* enterExitPath();
        Pathways& getDesertPathways();
};

#endif //DESERTOFDEATH_H