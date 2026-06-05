#include "gtest/gtest.h"
#include "StarterForest.h"
#include "TremorousCaves.h"
#include "DesertOfDeath.h"
#include "KingsLand.h"
#include "Pathways.h"

TEST(ShopTests, DisplayDescription) {
    vector<Item*> shopItems = {new HealthPotion()};

    Shop starterShop(shopItems);
    ShopDisplay display;

    EXPECT_NO_THROW(display.displayDescription(starterShop, 1));
}

TEST(ShopTests, PurchaseItemEnoughCoins) {
    Inventory exampleInventory;
    Player examplePlayer("John", 100, 10, 5, 20, 15);
    exampleInventory.addCoin(100);

    vector<Item*> shopItems = {new HealthPotion()};

    Shop starterShop(shopItems);

    EXPECT_TRUE(starterShop.purchaseItem(1, exampleInventory, examplePlayer));
}

TEST(ShopTests, PurchaseItemNotEnoughCoins) {
    Inventory exampleInventory;
    Player examplePlayer("John", 100, 10, 5, 20, 15);
    exampleInventory.addCoin(0);

    vector<Item*> shopItems = {new HealthPotion()};

    Shop starterShop(shopItems);

    EXPECT_FALSE(starterShop.purchaseItem(1, exampleInventory, examplePlayer));
}


// STARTING PATHWAYS TESTS Starting now

TEST (PathwaysTests, DefaultConstructorCheck) {
    Pathways defaultPath;

    EXPECT_EQ(defaultPath.getName(), "none");
    EXPECT_EQ(defaultPath.getAreaName(), "none");
    EXPECT_FALSE(defaultPath.hasEnemy());
    EXPECT_FALSE(defaultPath.hasShop());
    EXPECT_EQ(defaultPath.getEnemy(), nullptr);
    EXPECT_EQ(defaultPath.getShop(), nullptr);
}

TEST (PathwaysTests, EnemyConstructorCheck) {
    Enemy* exampleEnemy = new Enemy("Goblin", 30, 5, 2, 10, 20, 5, 0);
    Pathways enemyPath("Enemy Pathway", "Example Area", exampleEnemy);

    EXPECT_EQ(enemyPath.getName(), "Enemy Pathway");
    EXPECT_EQ(enemyPath.getAreaName(), "Example Area");
    EXPECT_TRUE(enemyPath.hasEnemy());
    EXPECT_FALSE(enemyPath.hasShop());
    EXPECT_EQ(enemyPath.getEnemy(), exampleEnemy);
    EXPECT_EQ(enemyPath.getShop(), nullptr);
}

TEST(PathwaysTests, ShopConstructorCheck) {
    vector<Item*> shopItems = {new HealthPotion()};

    Shop* exampleShop = new Shop(shopItems);
    Pathways shopPath("Shop Pathway","test center area", exampleShop);

    EXPECT_EQ(shopPath.getName(), "Shop Pathway");
    EXPECT_FALSE(shopPath.hasEnemy());
    EXPECT_TRUE(shopPath.hasShop());
    EXPECT_EQ(shopPath.getEnemy(), nullptr);
    EXPECT_EQ(shopPath.getShop(), exampleShop);
}

TEST (PathwaysTests, NameConstructorCheck) {
    Pathways namePath("Name Only Pathway", "Example Area");

    EXPECT_EQ(namePath.getName(), "Name Only Pathway");
    EXPECT_EQ(namePath.getAreaName(), "Example Area");
    EXPECT_FALSE(namePath.hasEnemy());
    EXPECT_FALSE(namePath.hasShop());
    EXPECT_EQ(namePath.getEnemy(), nullptr);
    EXPECT_EQ(namePath.getShop(), nullptr);
}

TEST (PathwaysTests, UserTraverseCheck) {
    Pathways currentPaths;
    int pathChoice = 1;

    Pathways* path1 = new Pathways("Pathway 1", "Example Area");
    currentPaths.addPath(path1);
    Pathways* path2 = new Pathways("Pathway 2", "Example Area");
    currentPaths.addPath(path2);
    Pathways* path3 = new Pathways("Pathway 3", "Example Area");
    currentPaths.addPath(path3);

    EXPECT_EQ(currentPaths.userTraverse(pathChoice), path1);
}

TEST (PathwaysTests, TraverseInvalidChoiceCheck) {
    Pathways currentPaths;
    int pathChoice = 4;
    int pathChoice2 = -1;

    Pathways* path1 = new Pathways("Pathway 1", "Example Area");
    currentPaths.addPath(path1);
    Pathways* path2 = new Pathways("Pathway 2", "Example Area");
    currentPaths.addPath(path2);
    Pathways* path3 = new Pathways("Pathway 3", "Example Area");
    currentPaths.addPath(path3);

    EXPECT_EQ(currentPaths.userTraverse(pathChoice), nullptr);
    EXPECT_EQ(currentPaths.userTraverse(pathChoice2), nullptr);
}

// STARTING DESERT TESTS NOW Starting now

TEST (DesertTests, DesertOfDeathNameCheck) {
    DesertOfDeath desert;

    EXPECT_EQ(desert.getName(), "Desert of Death");
}


TEST (DesertTests, DesertDamageTest) {
    Inventory exampleInventory;
    Player examplePlayer("John", 100, 10, 5, 20, 15);
    DesertOfDeath desert;

    desert.desertDamage(examplePlayer);

    EXPECT_EQ(examplePlayer.getHealth(), 95);
}

//STARTING CAVES TESTS starting now

TEST (TremorousCavesTests, TremorousCavesNameCheck) {
    TremorousCaves caves;

    EXPECT_EQ(caves.getName(), "Tremorous Caves");
}


TEST (TremorousCavesTests, CaveShakeTest) {
    Inventory exampleInventory;
    Player examplePlayer("John", 100, 10, 5, 20, 15);
    TremorousCaves caves;

    caves.caveShake(examplePlayer);
    // should happen every 30% if the time
    EXPECT_EQ(examplePlayer.getHealth(), 95);
}


// STARTING KINGS TESTS starting now

TEST (KingsLandTests, KingsLandNameCheck) {
    KingsLand kingsLand;

    EXPECT_EQ(kingsLand.getName(), "Kings Land");
}

TEST(AreaTravelTests, DesertToKingsLand) {
    Player player("John", 100, 10, 5, 20, 15);

    DesertOfDeath desert;
    KingsLand kingsLand;

    Pathways* playerPath = nullptr;

    desert.EnterDesert(player, playerPath);
    EXPECT_EQ(playerPath->getName(), "Oasis");

    kingsLand.EnterKingsLand(player, playerPath);

    EXPECT_EQ(playerPath->getName(), "The Grand Gates");
}

TEST(AreaTravelTests, CavesToDesert) {
    Player player("John", 100, 10, 5, 20, 15);

    TremorousCaves caves;
    DesertOfDeath desert;

    Pathways* playerPath = nullptr;

    caves.EnterCaves(player, playerPath);
    EXPECT_EQ(playerPath->getName(), "Echoing Chamber"); // replace with your first cave path

    desert.EnterDesert(player, playerPath);

    EXPECT_EQ(playerPath->getName(), "Oasis"); // replace with the same cave path
}
