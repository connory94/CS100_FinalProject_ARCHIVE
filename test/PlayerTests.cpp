#include "gtest/gtest.h"
#include "Boots.h"
#include "DefensePotion.h"
#include "HealthPotion.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"
#include "Shield.h"
#include "SpeedPotion.h"
#include "Staff.h"
#include "StrengthPotion.h"
#include "Item.h"

TEST(PlayerTests, CharacterDescription) {
    Player player("John", 50, 15, 10, 15, 5);

    EXPECT_EQ(player.getName(), "John");
    EXPECT_EQ(player.getHealth(), 50);
    EXPECT_EQ(player.getDefense(), 15);
    EXPECT_EQ(player.getStrength(), 10);
    EXPECT_EQ(player.getMagicStrength(), 15);
    EXPECT_EQ(player.getSpeed(), 5);
}

TEST(PlayerTests, CharacterTakeDamage) {
    Player player("John", 50, 15, 10, 15, 5);

    player.takeDamage(20);

    EXPECT_EQ(player.getHealth(), 30);

    player.takeDamage(40);

    EXPECT_EQ(player.getHealth(), 0);
}

TEST(PlayerTests, CharacterAddHealth) {
    Player player("John", 50, 15, 10, 15, 5);

    player.addHealth(10);

    EXPECT_EQ(player.getHealth(), 60);
}

TEST(PlayerTests, CharacterATK) {
    Player player("John", 50, 15, 10, 15, 5);

    player.addAtk(10);

    EXPECT_EQ(player.getStrength(), 20);

    player.removeAtkStat(10);

    EXPECT_EQ(player.getStrength(), 10);
}

TEST(PlayerTests, CharacterDefence) {
    Player player("John", 50, 15, 10, 15, 5);

    player.addDefence(5);

    EXPECT_EQ(player.getDefense(), 20);

    player.removeDefenceStat(5);

    EXPECT_EQ(player.getDefense(), 15);
}

TEST(PlayerTests, CharacterMagicAtk) {
    Player player("John", 50, 15, 10, 15, 5);

    player.addMagicAtk(10);

    EXPECT_EQ(player.getMagicStrength(), 25);

    player.removeMagicAtkStat(5);

    EXPECT_EQ(player.getMagicStrength(), 20);
}

TEST(PlayerTests, CharacterSpeed) {
    Player player("John", 50, 15, 10, 15, 5);

    player.addSpeed(5);

    EXPECT_EQ(player.getSpeed(), 10);

    player.removeSpeedStat(5);

    EXPECT_EQ(player.getSpeed(), 5);
}

TEST(PlayerTests, CharacterXP) {

    Player player("John", 50, 15, 10, 15, 5);

    player.addXP(50);

    EXPECT_EQ(player.getXP(), 50);
}


// STARTING Item TESTS Starting now

TEST(ItemTests, BootsNameAndPrice) {

    Item* Boots;

    EXPECT_EQ(Boots->getName(), "Boots");
    EXPECT_EQ(Boots->getPrice(), 25);
}

TEST(ItemTests, DefensePotionNameAndPrice) {

    Item* DefensePotion;

    EXPECT_EQ(DefensePotion->getName(), "Defense potion");
    EXPECT_EQ(DefensePotion->getPrice(), 35);
}

TEST(ItemTests, HealthPotionNameAndPrice) {

    Item* healthPotion;

    EXPECT_EQ(healthPotion->getName(), "Health potion");
    EXPECT_EQ(healthPotion->getPrice(), 35);
}

TEST(ItemTests, ShieldNameAndPrice) {

    Item* shield;

    EXPECT_EQ(shield->getName(), "Shield");
    EXPECT_EQ(shield->getPrice(), 20);
}

TEST(ItemTests, SpeedPotionNameAndPrice) {

    Item* SpeedPotion;

    EXPECT_EQ(SpeedPotion->getName(), "Speed potion");
    EXPECT_EQ(SpeedPotion->getPrice(), 55);
}

TEST(ItemTests, StaffNameAndPrice) {

    Item* Staff;

    EXPECT_EQ(Staff->getName(), "Staff");
    EXPECT_EQ(Staff->getPrice(), 15);
}

TEST(ItemTests, StrengthPotionNameAndPrice) {

    Item* StrengthPotion;

    EXPECT_EQ(StrengthPotion->getName(), "Strength potion");
    EXPECT_EQ(StrengthPotion->getPrice(), 50);
}

TEST(ItemTests, SwordNameAndPrice) {

    Item* Sword;

    EXPECT_EQ(Sword->getName(), "Sword");
    EXPECT_EQ(Sword->getPrice(), 20);
}



// STARTING Inventory Starting now

TEST (InventoryTests, InventoryDefault) {
    Inventory inventory;

    EXPECT_EQ(inventory.getCoin(), 0);
    EXPECT_TRUE(inventory.getCoin() == 0);
}

TEST (InventoryTests, InventoryCoinCounts) {
    Inventory inventory;

    inventory.addCoin(100);
    EXPECT_EQ(inventory.getCoin(), 100);

    inventory.removeCoin(20);
    EXPECT_EQ(inventory.getCoin(), 80);
}

TEST(InventoryTests, SetCoinCount) {

    Inventory inventory;

    inventory.setCoinCount(50);
    EXPECT_EQ(inventory.getCoin(), 50);
}

TEST(InventoryTests, InventoryAddItem) {

    Inventory inventory;
    Item* potion = new DefensePotion();

    inventory.addItem(potion);
    EXPECT_EQ(inventory.getItems().size(), 1);
}

TEST(InventoryTests, InventoryFindItem) {

    Inventory inventory;
    Item* potion = new HealthPotion();

    inventory.addItem(potion);
    EXPECT_EQ(inventory.findItem(potion->getName()), 0);
}

TEST(InventoryTests, InventoryRemoveItem) {

    Inventory inventory;
    Item* potion = new HealthPotion();

    inventory.addItem(potion);
    inventory.removeItem(potion->getName());
    EXPECT_TRUE(inventory.getItems().empty());
}