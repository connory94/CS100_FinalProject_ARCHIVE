#include "KingsLand.h"


using namespace std;

KingsLand::KingsLand() {
    Pathways* path1 = new Pathways("The Grand Gates", "KingsLand", new GateKeeper());
    kingsPathways.addPath(path1);
    Pathways* path2 = new Pathways("The Poor Village", "KingsLand", new VillCultist());
    kingsPathways.addPath(path2);
    vector<Item*> kingsShopItems = {new HealthPotion(), new StrengthPotion(), new SpeedPotion(), new DefensePotion(), new Shield(), new Sword(), new Staff(), new Boots()};
    Pathways* path3 = new Pathways("The King's Keeps - Shop", "KingsLand" , new Shop(kingsShopItems));
    kingsPathways.addPath(path3);
    Pathways* path4 = new Pathways("The Grand Throne Room", "KingsLand", new MadKing());
    kingsPathways.addPath(path4);
    Pathways* path5 = new Pathways("exit path to end game", "KingsLand");
    kingsPathways.addPath(path5);
}


string KingsLand::getName() {
    return name;
}

// crosses from desert to kings land
void KingsLand::EnterKingsLand(Player &player, Pathways* &playerPath) {
    PathwaysDisplay display;


    Pathways* nextPath = kingsPathways.userTraverse(1);
    

    if (nextPath != nullptr) {
        playerPath = nextPath;
        cout << "Welcome to the Kings Land! Be Prepared!" << endl;
    }
}

bool KingsLand::mainPathsVisitedWithBoss() {
    return kingsPathways.mainPathsVisitedWithBoss();
}

bool KingsLand::travelPathsVisited() {
    return kingsPathways.travelPathsVisited();
}

Pathways* KingsLand::enterBossPath() {
    return kingsPathways.userTraverse(4);
}

Pathways* KingsLand::enterExitPath() {
    return kingsPathways.userTraverse(5);
}

Pathways& KingsLand::getKingPathways() {
    return kingsPathways;
}