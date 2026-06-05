#include "TremorousCaves.h"


using namespace std;

TremorousCaves::TremorousCaves() {
    Pathways* path1 = new Pathways("Echoing Chamber", "TremorousCaves", new Overbat());
    tremorousPathways.addPath(path1);
    Pathways* path2 = new Pathways("Crystal Cavern", "TremorousCaves", new Crygolem());
    tremorousPathways.addPath(path2);
    vector<Item*> tremorousShopItems = {new HealthPotion(), new StrengthPotion(), new SpeedPotion(), new DefensePotion(), new Shield(), new Sword(), new Staff(), new Boots()};
    Pathways* path3 = new Pathways("Underground Lake - Shop", "TremorousCaves", new Shop(tremorousShopItems));
    tremorousPathways.addPath(path3);
    Pathways* path4 = new Pathways("Spider Nest", "TremorousCaves", new QueenSpider());
    tremorousPathways.addPath(path4);
    Pathways* path5 = new Pathways("exit path to Desert of Death", "TremorousCaves");
    tremorousPathways.addPath(path5);
}

string TremorousCaves::getName() {
    return name;
}

// emulates cave shakes so that the player takes dam sometimes, uses a real random with a clock and seed random
void TremorousCaves::caveShake(Player &player) {
    srand(time(0));
    int eventChance = rand() % 100;
    // cout << "Roll: " << eventChance << endl;
    if (eventChance < 80) {
        player.takeDamage(5);
        std::cout << "The cave shakes violently. You fell and take 5 damage!" << std::endl;
    } else {
        std::cout << "The cave shakes but nothing happens." << std::endl;
    }
}

void TremorousCaves::EnterCaves(Player &player, Pathways* &playerPath) {
    PathwaysDisplay display;

    caveShake(player);

    Pathways* nextPath = tremorousPathways.userTraverse(1);

    if (nextPath != nullptr) {
        playerPath = nextPath;
        cout << "Welcome to the Tremorous Caves! Be Prepared!" << endl;
    }
}

bool TremorousCaves::mainPathsVisitedWithBoss() {
    return tremorousPathways.mainPathsVisitedWithBoss();
}

bool TremorousCaves::travelPathsVisited() {
    return tremorousPathways.travelPathsVisited();
}

Pathways* TremorousCaves::enterBossPath() {
    return tremorousPathways.userTraverse(4);
}

Pathways* TremorousCaves::enterExitPath() {
    return tremorousPathways.userTraverse(5);
}

Pathways& TremorousCaves::getCavePathways() {
    return tremorousPathways;
}