#include "gtest/gtest.h"
#include "../combatCMake/combatHeader/character.h"
#include "../combatCMake/combatHeader/cplayer.h"
#include "../combatCMake/combatHeader/enemy.h"
#include "../combatCMake/combatHeader/combat.h"
#include "../combatCMake/combatHeader/combatdisplay.h"
#include "../Player/Inventory.h"

using namespace std;


// CHARACTER TESTS

TEST(CharacterTests, ConstructorCheck) {
    Character character("Test Character", 100, 12, 5, 8, 4);

    EXPECT_EQ(character.getName(), "Test Character");
    EXPECT_EQ(character.getHealth(), 100);
    EXPECT_EQ(character.getMaxHealth(), 100);
    EXPECT_EQ(character.getAttackPower(), 12);
    EXPECT_EQ(character.getDefense(), 5);
    EXPECT_EQ(character.getSpeed(), 8);
    EXPECT_EQ(character.getMagicAtk(), 4);
    EXPECT_TRUE(character.isAlive());
}

TEST(CharacterTests, HealthCannotExceedMaximum) {
    Character character("Test Character", 100, 12, 5, 8, 4);

    character.changeHp(-30);
    EXPECT_EQ(character.getHealth(), 70);

    character.changeHp(50);
    EXPECT_EQ(character.getHealth(), 100);
}

TEST(CharacterTests, CharacterDiesAtZeroHP) {
    Character character("Test Character", 100, 12, 5, 8, 4);

    character.changeHp(-100);

    EXPECT_EQ(character.getHealth(), 0);
    EXPECT_FALSE(character.isAlive());
}

TEST(CharacterTests, StatsCannotBeBelowMinimum) {
    Character character("Test Character", 100, 12, 5, 8, 4);

    character.changeAtk(-100);
    character.changeDef(-100);
    character.changeSpd(-100);
    character.changeMagicAtk(-100);

    EXPECT_EQ(character.getAttackPower(), 1);
    EXPECT_EQ(character.getDefense(), 0);
    EXPECT_EQ(character.getSpeed(), 0);
    EXPECT_EQ(character.getMagicAtk(), 1);
}

TEST(CharacterTests, StatsCanIncrease) {
    Character character("Test Character", 100, 12, 5, 8, 4);

    character.changeAtk(3);
    character.changeDef(2);
    character.changeSpd(4);
    character.changeMagicAtk(5);

    EXPECT_EQ(character.getAttackPower(), 15);
    EXPECT_EQ(character.getDefense(), 7);
    EXPECT_EQ(character.getSpeed(), 12);
    EXPECT_EQ(character.getMagicAtk(), 9);
}

TEST(CharacterTests, CalculateDamageCheck) {
    Character attacker("Attacker", 100, 10, 3, 5, 6);
    Character defender("Defender", 100, 5, 7, 5, 2);
    Skill skill = {"Hybrid Skill", 1.5f, 0.5f, "Test skill", 1};

    int damage = Character::calculateDamage(attacker, skill, defender);

    EXPECT_EQ(damage, 11);
}

TEST(CharacterTests, CalculateDamageCannotBeNegative) {
    Character attacker("Attacker", 100, 2, 3, 5, 1);
    Character defender("Defender", 100, 5, 100, 5, 2);
    Skill skill = {"Weak Skill", 1.0f, 0.0f, "Test skill", 1};

    int damage = Character::calculateDamage(attacker, skill, defender);

    EXPECT_EQ(damage, 1);
}


// CPLAYER TESTS

TEST(cPlayerTests, UnlockedSkillsRemainInOrder) {
    cPlayer player("ASSASSIN", 32, 32, 13, 4, 11, 5, {0, 1, 3, 16});

    vector<Skill> skills = player.getUnlockedSkills();

    ASSERT_EQ(skills.size(), 4);
    EXPECT_EQ(skills.at(0).name, "Strike");
    EXPECT_EQ(skills.at(1).name, "Heal");
    EXPECT_EQ(skills.at(2).name, "Warm up");
    EXPECT_EQ(skills.at(3).name, "Sabotage");
}

TEST(cPlayerTests, HealRestoresQuarterMaximumHealth) {
    cPlayer player("MAGE", 20, 40, 5, 4, 7, 13, {1});
    Enemy enemy("Dummy", 100, 1, 0, 1, 0, 0, 0);

    player.useSkillEffect(0, player, enemy);

    EXPECT_EQ(player.getHealth(), 30);
}

TEST(cPlayerTests, HealCannotExceedMaximumHealth) {
    cPlayer player("MAGE", 38, 40, 5, 4, 7, 13, {1});
    Enemy enemy("Dummy", 100, 1, 0, 1, 0, 0, 0);

    player.useSkillEffect(0, player, enemy);

    EXPECT_EQ(player.getHealth(), 40);
}

TEST(cPlayerTests, WarmUpRaisesAttackAndSpeed) {
    cPlayer player("ASSASSIN", 32, 32, 13, 4, 11, 5, {3});
    Enemy enemy("Dummy", 100, 1, 0, 1, 0, 0, 0);

    player.useSkillEffect(0, player, enemy);

    EXPECT_EQ(player.getAttackPower(), 15);
    EXPECT_EQ(player.getSpeed(), 12);
}

TEST(cPlayerTests, SabotageLowersEnemyStats) {
    cPlayer player("ASSASSIN", 32, 32, 13, 4, 11, 5, {16});
    Enemy enemy("Dummy", 100, 10, 10, 10, 0, 0, 5);

    player.useSkillEffect(0, player, enemy);

    EXPECT_EQ(enemy.getAttackPower(), 9);
    EXPECT_EQ(enemy.getDefense(), 8);
    EXPECT_EQ(enemy.getSpeed(), 8);
}

TEST(cPlayerTests, ReinforceRaisesDefenseAndLowersSpeed) {
    cPlayer player("TANK", 50, 50, 7, 9, 4, 2, {8});
    Enemy enemy("Dummy", 100, 1, 0, 1, 0, 0, 0);

    player.useSkillEffect(0, player, enemy);

    EXPECT_EQ(player.getDefense(), 15);
    EXPECT_EQ(player.getSpeed(), 2);
}


// ENEMY TESTS

TEST(EnemyTests, ConstructorStoresRewards) {
    Enemy enemy("Reward Enemy", 100, 10, 5, 8, 40, 25, 3);

    EXPECT_EQ(enemy.xpReward(), 40);
    EXPECT_EQ(enemy.goldReward(), 25);
}

TEST(EnemyTests, AddedSkillsAreStored) {
    Enemy enemy("Test Enemy", 100, 10, 5, 8, 40, 25, 3);

    enemy.addSkill({"Skill One", 1.0f, 0.0f, "First skill", 5});
    enemy.addSkill({"Skill Two", 1.5f, 0.0f, "Second skill", 2});

    ASSERT_EQ(enemy.getSkills().size(), 2);
    EXPECT_EQ(enemy.getSkills().at(0).name, "Skill One");
    EXPECT_EQ(enemy.getSkills().at(1).name, "Skill Two");
}

TEST(EnemyTests, ChooseSkillReturnsValidIndex) {
    Enemy enemy("Test Enemy", 100, 10, 5, 8, 40, 25, 3);

    enemy.addSkill({"Skill One", 1.0f, 0.0f, "First skill", 5});
    enemy.addSkill({"Skill Two", 1.0f, 0.0f, "Second skill", 3});
    enemy.addSkill({"Skill Three", 1.0f, 0.0f, "Third skill", 1});

    for(int i = 0; i < 100; i++) {
        int chosenSkill = enemy.chooseSkill();

        EXPECT_GE(chosenSkill, 0);
        EXPECT_LT(chosenSkill, 3);
    }
}


// COMBAT TESTS

TEST(CombatTests, FasterGoesFirst) {
    cPlayer player("ASSASSIN", 32, 32, 13, 4, 20, 5, {0});
    Enemy enemy("Slow Enemy", 100, 10, 5, 5, 10, 10, 3);
    Inventory inventory;
    Combat combat(player, enemy, inventory);

    EXPECT_TRUE(combat.playerGoesFirst(player, enemy));
}

TEST(CombatTests, EqualSpeedPlayerGoesFirst) {
    cPlayer player("KNIGHT", 40, 40, 10, 6, 8, 3, {0});
    Enemy enemy("Equal Enemy", 100, 10, 5, 8, 10, 10, 3);
    Inventory inventory;
    Combat combat(player, enemy, inventory);

    EXPECT_TRUE(combat.playerGoesFirst(player, enemy));
}

TEST(CombatTests, SlowerPlayerDoesNotGoFirst) {
    cPlayer player("TANK", 50, 50, 7, 9, 4, 2, {0});
    Enemy enemy("Fast Enemy", 100, 10, 5, 10, 10, 10, 3);
    Inventory inventory;
    Combat combat(player, enemy, inventory);

    EXPECT_FALSE(combat.playerGoesFirst(player, enemy));
}

TEST(CombatTests, PlayerNotWonWhileEnemyAlive) {
    cPlayer player("KNIGHT", 40, 40, 10, 6, 8, 3, {0});
    Enemy enemy("Enemy", 100, 10, 5, 8, 10, 10, 3);
    Inventory inventory;
    Combat combat(player, enemy, inventory);

    EXPECT_FALSE(combat.playerWon());
}

TEST(CombatTests, PlayerWinsAfterEnemyDies) {
    cPlayer player("KNIGHT", 40, 40, 10, 6, 8, 3, {0});
    Enemy enemy("Enemy", 100, 10, 5, 8, 10, 10, 3);
    Inventory inventory;
    Combat combat(player, enemy, inventory);

    enemy.changeHp(-enemy.getMaxHealth());

    EXPECT_TRUE(combat.playerWon());
}