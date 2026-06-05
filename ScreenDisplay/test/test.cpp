#include "gtest/gtest.h"
#include "../header/ReadScreenFile.h"
#include "../header/ScreenDisplay.h"
#include "../header/Hotbar.h"
//#include "../../gmock/gmock.h"

using namespace std;

/* this is only here as a reminder of the test case format
TEST(HailstoneTests, zeroGivesFalse){
    bool subject = sequence::satisfiesHailstone(0);
    EXPECT_EQ(false, subject);
}
*/

//====================
// read file tests
//====================
//test that this class initializes to empty string
TEST(ReadTests, constructorTest){
    ReadScreenFile reader;
    EXPECT_EQ(reader.getReadText(), "");
}

//test that nonsense filename returns false
TEST(ReadTests, badReadGivesFalse){
    ReadScreenFile reader;
    bool isValid = reader.readFile("invalid", 0);
    EXPECT_FALSE(isValid);
}

//test that nonsense filename writes error to string
TEST(ReadTests, badReadWritesError){
    ReadScreenFile reader;
    bool isValid = reader.readFile("invalid", 0);
    EXPECT_EQ(reader.getReadText(), "failed to read invalid\n");
}

//test that a real txt file returns true
TEST(ReadTests, goodReadGivesTrue){
    ReadScreenFile reader;
    bool isValid = reader.readFile("ScreenDisplay/txtfiles/intro.txt", 0);
    EXPECT_TRUE(isValid);
}

//====================
// screen display tests
//====================
//test that ScreenDisplay initialized correctly
TEST(DisplayTests, displayInitialize){
    ScreenDisplay display;
    EXPECT_EQ(display.getScreen(), "");
}

//====================
// hotbar tests
//====================
//test that hotbar initializes to title screen
TEST(HotbarTests, hotbarInit){
    Hotbar hbar;
    EXPECT_EQ(hbar.getOptions(), "Press 1 to Start!");
}

//go through example sequence of intro, make sure we get expected output
TEST(HotbarTests, hotbarIntro){
    Hotbar hbar;

    hbar.displayIntro(1);
    EXPECT_EQ(hbar.getOptions(), "Pick your Class! (input 1-4)\n");

    hbar.displayIntro(2);
    EXPECT_EQ(hbar.getOptions(), "Are you ready to embark? \n1) Let The Adventure Begin! \n2) Return to Class Select\n");
}

//hotbar can display outside information
TEST(HotbarTests, hotbarInputDisplay){
    Hotbar hbar;

    hbar.displayHotbar("Welcome to the Lakeshore Forest!", false);
    EXPECT_EQ(hbar.getOptions(), "Welcome to the Lakeshore Forest!");
}

//====================
// enemy Display Tests
//====================

//test that function correctly takes in the right parameter
TEST(enemyDisplayTests, displaySlime){
    ScreenDisplay display;
    ReadScreenFile reader;
    reader.readFile("ScreenDisplay/txtfiles/monsters.txt", 0);
    display.displayEnemy("ScreenDisplay/txtfiles/monsters.txt", "Slime");

    EXPECT_EQ(display.getScreen(), reader.getReadText());
}