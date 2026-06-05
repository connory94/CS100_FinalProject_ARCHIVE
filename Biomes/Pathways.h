#ifndef PATHWAYS_H
#define PATHWAYS_H
#include <string>
#include <vector>
#include <iostream>
#include "../combatCMake/combatHeader/enemy.h"
#include "shop.h"



class Pathways {
    private:
        std::string name;
        Enemy* pathEnemy;
        Shop* pathShop;
        std::vector<Pathways*> differentPaths;
        bool visited;
        std::string areaName;
    public:
        Pathways(const std::string& name, const std::string& areaName, Shop* pathShop);
        Pathways(const std::string& name, const std::string& areaName, Enemy* pathEnemy);
        Pathways(const std::string& name, const std::string& areaName);
        Pathways();
        ~Pathways();

        void markVisited();
        bool getVisited() const;
        void addPath( Pathways* path);
        Pathways* userTraverse(const int& pathChoice);
        bool mainPathsVisitedWithBoss();
        bool travelPathsVisited();
        std::vector<Pathways*> getDifferentPaths() const;

        bool hasEnemy() const;
        Enemy* getEnemy() const;

        bool hasShop() const;
        Shop* getShop() const;

        std::string getAreaName() const;
        std::string getName() const;
};

class PathwaysDisplay {
    public:
        void showAvailablePaths(const Pathways& pathways);
};


#endif //PATHWAYS_H