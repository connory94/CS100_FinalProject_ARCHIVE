#include "DesertOfDeath.h"

using namespace std;

DesertOfDeath::DesertOfDeath() {
    Pathways* path1 = new Pathways("Oasis", "DesertOfDeath", new OasisGuard());
    desertPathways.addPath(path1);
    Pathways* path2 = new Pathways("Sand Dunes", "DesertOfDeath", new SandWorm());
    desertPathways.addPath(path2);
    vector<Item*> desertShopItems = {new HealthPotion(), new StrengthPotion(), new SpeedPotion(), new DefensePotion(), new Shield(), new Sword(), new Staff(), new Boots()};
    Pathways* path3 = new Pathways("Ancient Ruins - Shop", "DesertOfDeath", new Shop(desertShopItems));
    desertPathways.addPath(path3);
    Pathways* path4 = new Pathways("Ravine Kingdom Keep", "DesertOfDeath", new Sunkwarden());
    desertPathways.addPath(path4);
    Pathways* path5 = new Pathways("exit path to Kings Land", "DesertOfDeath");
    desertPathways.addPath(path5);
}

string DesertOfDeath::getName() {
    return name;
}

void DesertOfDeath::desertDamage(Player &player) {
    player.takeDamage(5);
}

// crosses from caves to Desert
void DesertOfDeath::EnterDesert(Player &player, Pathways* &playerPath) {
    PathwaysDisplay display;

    desertDamage(player);


    Pathways* nextPath = desertPathways.userTraverse(1);

    if (nextPath != nullptr) {
        playerPath = nextPath;
        cout << "Welcome to the Desert of Death! Be Prepared!" << endl;
    }
}

bool DesertOfDeath::mainPathsVisitedWithBoss() {
    return desertPathways.mainPathsVisitedWithBoss();
}

bool DesertOfDeath::travelPathsVisited() {
    return desertPathways.travelPathsVisited();
}

Pathways* DesertOfDeath::enterBossPath() {
    return desertPathways.userTraverse(4);
}

Pathways* DesertOfDeath::enterExitPath() {
    return desertPathways.userTraverse(5);
}

Pathways& DesertOfDeath::getDesertPathways() {
    return desertPathways;
}