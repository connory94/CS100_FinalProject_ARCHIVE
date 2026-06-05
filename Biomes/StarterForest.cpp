#include "StarterForest.h"


using namespace std;

StarterForest::StarterForest() {
    Pathways* path1 = new Pathways("Goblin Camp", "StarterForest", new GobGrunt());
    forestPathways.addPath(path1);
    Pathways* path2 = new Pathways("Abandoned Cabin", "StarterForest", new CabinSpirit());
    forestPathways.addPath(path2);
    vector<Item*> forestShopItems = {new HealthPotion(), new StrengthPotion(), new SpeedPotion(), new DefensePotion(), new Shield(), new Sword(), new Staff(), new Boots()};
    Pathways* path3 = new Pathways("Enchanted Grove - Shop", "StarterForest", new Shop(forestShopItems));
    forestPathways.addPath(path3);
    Pathways* path4 = new Pathways("Dark Cave", "StarterForest", new DarkGobShaman());
    forestPathways.addPath(path4);
    Pathways* path5 = new Pathways("Exit path to TremorousCaves", "StarterForest");
    forestPathways.addPath(path5);
}

string StarterForest::getName() {
    return name;
}

// checks if the main paths are visited
bool StarterForest::mainPathsVisitedWithBoss() {
    return forestPathways.mainPathsVisitedWithBoss();
}

// chcks if the main paths are visited
bool StarterForest::travelPathsVisited() {
    return forestPathways.travelPathsVisited();
}

// starts you off at the forest
void StarterForest::enterForest(Player &player, Pathways* &playerPath) {
    PathwaysDisplay display;

    Pathways* nextPath = forestPathways.userTraverse(1);
    

    if (nextPath != nullptr) {
        playerPath = nextPath;
        cout << "Welcome to the Forest! Be Prepared!" << endl;
    }
}

Pathways* StarterForest::enterBossPath() {
    return forestPathways.userTraverse(4);
}

Pathways* StarterForest::enterExitPath() {
    return forestPathways.userTraverse(5);
}

// helper function for game class
Pathways& StarterForest::getForestPathways() {
    return forestPathways;
}