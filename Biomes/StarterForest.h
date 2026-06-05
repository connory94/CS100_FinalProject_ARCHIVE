#ifndef STARTERFOREST_H
#define STARTERFOREST_H
#include <string>
#include <vector>
#include <iostream>
#include "Pathways.h"
#include "../Player/Player.h"
#include "../combatCMake/combatHeader/enemy.h"
#include "../combatCMake/combatHeader/gobgrunt.h"
#include "../combatCMake/combatHeader/cabinspirit.h"
#include "../combatCMake/combatHeader/darkgobshaman.h"
#include "shop.h"
#include "../Player/HealthPotion.h"
#include "../Player/StrengthPotion.h"
#include "../Player/SpeedPotion.h"
#include "../Player/DefensePotion.h"
#include "../Player/Shield.h"
#include "../Player/Sword.h"
#include "../Player/Staff.h"
#include "../Player/Boots.h"

class StarterForest {
    private: 
        std::string name = "Starter Forest";
        Pathways forestPathways;

    public:
        StarterForest();
        std::string getName();
        void enterForest(Player &player, Pathways* &playerPath);
        bool mainPathsVisitedWithBoss();
        bool travelPathsVisited();
        Pathways* enterBossPath();
        Pathways* enterExitPath();
        Pathways& getForestPathways();
};


#endif //STARTERFOREST_H