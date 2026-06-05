#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

//was missing apparently, was breaking tests.
string Game::getCurrentArea(){
    return currArea;
}
Game::Game(Player player, Inventory inventory, Pathways* playerPath) : player(player), playerInventory(inventory), playerPath(playerPath) {}

//gave player class a setName function, using that in my intro sequence now.
void Game::introSequence(Player &player){
    string userInput = "";
    screenDisplay.display("../ScreenDisplay/txtfiles/intro.txt", 0, "Enter your name to continue!\n", false);
    cin >> userInput;
    player.setName(userInput);
    userInput = "";
    
    screenDisplay.display("../ScreenDisplay/txtfiles/intro.txt", 1, "Pick a class to play as!\n", true);
    player.pickClass(); //has some cout calls of its own

    //no class getter? using speed to identify class b/c it's unique between them all.. 
    if(player.getSpeed() == 7){
        screenDisplay.display("../ScreenDisplay/txtfiles/intro.txt", 2, "You picked the Knight! \nEnter anything to embark on your adventure\n", false);
    }
    else if(player.getSpeed() == 11){
        screenDisplay.display("../ScreenDisplay/txtfiles/intro.txt", 3, "You picked the Assassin! \nEnter anything to embark on your adventure\n", false);
    }
    else if(player.getSpeed() == 4){
        screenDisplay.display("../ScreenDisplay/txtfiles/intro.txt", 4, "You picked the Tank! \nEnter anything to embark on your adventure\n", false);
    }
    else if(player.getSpeed() == 10){
        screenDisplay.display("../ScreenDisplay/txtfiles/intro.txt", 5, "You picked the Mage! \nEnter anything to embark on your adventure\n", false);
    }

    cin >> userInput;
}

void Game::areaTraversal(Player &player, Inventory &playerInventory, Pathways* &playerPath) {
    if (currArea == "Starter Forest") {
        screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 0, "Welcome to the Starter Forest! Be prepared for the dense foliage & hidden dangers! \n", true);

        cout << "Lets begin!" << endl;
        cout << "This is the list of the journey ahead of you: " << endl << endl;
        forest.enterForest(player, playerPath);
        

        userPathChoice(player, playerInventory, playerPath, forest.getForestPathways());

        if (forest.travelPathsVisited()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 2, "Congratulations! You have explored all the paths in the Starter Forest! \nBe Prepared! The Boss is waiting! \n", false);
            playerPath = forest.enterBossPath();

            vector<int> unlockedSkills = getUnlockedSkillsForPlayer(player);
            cPlayer combatPlayer(player.getName(), player.getHealth(), player.getMaxHealth(), player.getStrength(), player.getDefense(), player.getSpeed(), player.getMagicStrength(), unlockedSkills);

            //shows you the enemy you're facing, david's classes can handle the rest of output
            screenDisplay.displayEnemy("../ScreenDisplay/txtfiles/monsters.txt", playerPath->getEnemy()->getName());

            Combat combat(combatPlayer, *playerPath->getEnemy(), playerInventory);
            combat.startCombat();

            player.setHealth(combatPlayer.getHealth());

            if (combat.playerWon()) {
                player.addXP(playerPath->getEnemy()->xpReward());
                cout << "You defeated the " << playerPath->getEnemy()->getName() << " and gained " << playerPath->getEnemy()->xpReward() << " XP!" << endl;
                playerInventory.addCoin(playerPath->getEnemy()->goldReward());
                cout << "You also gained " << playerPath->getEnemy()->goldReward() << " gold." << endl;
                player.checkLevelUp();
                playerPath->markVisited();
            }

            if (!combatPlayer.isAlive()) {
                cout << "You have been defeated by the " << playerPath->getEnemy()->getName() << "!" << endl;
                gameOver = true;
                return;
            }
        }

        if (forest.mainPathsVisitedWithBoss()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 3, "Congratulations! You have defeated the boss of the Starter Forest! \nYou are now moving onto the next area: The Tremorous Caves!\n", false);
            playerPath = forest.enterExitPath();
            currArea = "Tremorous Caves";
        }
    } else if (currArea == "Tremorous Caves") {
        screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 4, "Welcome to the Tremorous Caves! Be prepared for the caves violent shaking! It can make you take damage, and even spawn cave spiders! Be Prepared! \n", true);
        cout << "Lets begin!" << endl;
        cout << "This is the list of the journey ahead of you: " << endl << endl;
        caves.EnterCaves(player, playerPath);
        

        userPathChoice(player, playerInventory, playerPath, caves.getCavePathways());

        if (caves.travelPathsVisited()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 5, "Congratulations! You have explored all the paths in the Tremorous Caves! \nBe Prepared! The Boss is waiting!\n", false);
            playerPath = caves.enterBossPath();

            
            vector<int> unlockedSkills = getUnlockedSkillsForPlayer(player);
            cPlayer combatPlayer(player.getName(), player.getHealth(), player.getMaxHealth(), player.getStrength(), player.getDefense(), player.getSpeed(), player.getMagicStrength(), unlockedSkills);

            //shows you the enemy you're facing, david's classes can handle the rest of output
            screenDisplay.displayEnemy("../ScreenDisplay/txtfiles/monsters.txt", playerPath->getEnemy()->getName());

            Combat combat(combatPlayer, *playerPath->getEnemy(), playerInventory);
            combat.startCombat();

            player.setHealth(combatPlayer.getHealth());

            if (combat.playerWon()) {
                player.addXP(playerPath->getEnemy()->xpReward());
                cout << "You defeated the " << playerPath->getEnemy()->getName() << " and gained " << playerPath->getEnemy()->xpReward() << " XP!" << endl;
                playerInventory.addCoin(playerPath->getEnemy()->goldReward());
                cout << "You also gained " << playerPath->getEnemy()->goldReward() << " gold." << endl << endl;
                player.checkLevelUp();
                playerPath->markVisited();
            }

            if (!combatPlayer.isAlive()) {
                cout << "You have been defeated by the " << playerPath->getEnemy()->getName() << "!" << endl;
                gameOver = true;
                return;
            }
        }
        if (caves.mainPathsVisitedWithBoss()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 6, "Congratulations! You have defeated the boss of the Tremorous Caves! \n You are now moving on to the next area: The Desert of Death!\n", false);
            playerPath = caves.enterExitPath();
            currArea = "Desert of Death";
        }
    } else if (currArea == "Desert of Death") {
        screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 7, "Welcome to the Desert of Death! The heat is so intense that each time you move you take 5 damage due to the scorching sun. \n", true);
        cout << "Lets begin!" << endl;
        cout << "This is the list of the journey ahead of you: " << endl << endl;
        desert.EnterDesert(player, playerPath);
        

        userPathChoice(player, playerInventory, playerPath, desert.getDesertPathways());

        if (desert.travelPathsVisited()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 8, "Congratulations! You have explored all the paths in the Desert of Death! \nBe Prepared! The Boss is waiting!\n", false);
            playerPath = desert.enterBossPath();
            
            vector<int> unlockedSkills = getUnlockedSkillsForPlayer(player);
            cPlayer combatPlayer(player.getName(), player.getHealth(), player.getMaxHealth(), player.getStrength(), player.getDefense(), player.getSpeed(), player.getMagicStrength(), unlockedSkills);

            //shows you the enemy you're facing, david's classes can handle the rest of output
            screenDisplay.displayEnemy("../ScreenDisplay/txtfiles/monsters.txt", playerPath->getEnemy()->getName());

            Combat combat(combatPlayer, *playerPath->getEnemy(), playerInventory);
            combat.startCombat();

            player.setHealth(combatPlayer.getHealth());

            if (combat.playerWon()) {
                player.addXP(playerPath->getEnemy()->xpReward());
                cout << "You defeated the " << playerPath->getEnemy()->getName() << " and gained " << playerPath->getEnemy()->xpReward() << " XP!" << endl;
                playerInventory.addCoin(playerPath->getEnemy()->goldReward());
                cout << "You also gained " << playerPath->getEnemy()->goldReward() << " gold." << endl << endl;
                player.checkLevelUp();
                playerPath->markVisited();
            }

            if (!combatPlayer.isAlive()) {
                cout << "You have been defeated by the " << playerPath->getEnemy()->getName() << "!" << endl;
                gameOver = true;
                return;
            }
        }
        if (desert.mainPathsVisitedWithBoss()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 9, "Congratulations! You have defeated the boss of the Desert of Death! \nYou are now moving on to the next area: The Kings Land! \n", false);
            playerPath = desert.enterExitPath();
            currArea = "Kings Land";
        }
    } else if (currArea == "Kings Land") {
        screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 10, "Welcome to the Kings Land! Be prepared to face the King's Guard, King's Servant, King's Jester, and the Royal Knight!\n", true);
        cout << "Lets begin!" << endl;
        cout << "This is the list of the journey ahead of you: " << endl << endl;

        kingsLand.EnterKingsLand(player, playerPath);
        

        userPathChoice(player, playerInventory, playerPath, kingsLand.getKingPathways());

        if (kingsLand.travelPathsVisited()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 11, "Congratulations! You have explored all the paths in the Kings Land! \nBe Prepared! The Boss is waiting!\n", false);
            playerPath = kingsLand.enterBossPath();
            
            vector<int> unlockedSkills = getUnlockedSkillsForPlayer(player);
            cPlayer combatPlayer(player.getName(), player.getHealth(), player.getMaxHealth(), player.getStrength(), player.getDefense(), player.getSpeed(), player.getMagicStrength(), unlockedSkills);

            //shows you the enemy you're facing, david's classes can handle the rest of output
            screenDisplay.displayEnemy("../ScreenDisplay/txtfiles/monsters.txt", playerPath->getEnemy()->getName());

            Combat combat(combatPlayer, *playerPath->getEnemy(), playerInventory);
            combat.startCombat();

            player.setHealth(combatPlayer.getHealth());

            if (combat.playerWon()) {
                player.addXP(playerPath->getEnemy()->xpReward());
                cout << "You defeated the " << playerPath->getEnemy()->getName() << " and gained " << playerPath->getEnemy()->xpReward() << " XP!" << endl;
                playerInventory.addCoin(playerPath->getEnemy()->goldReward());
                cout << "You also gained " << playerPath->getEnemy()->goldReward() << " gold." << endl << endl;
                player.checkLevelUp();
                playerPath->markVisited();
            }

            if (!combatPlayer.isAlive()) {
                cout << "You have been defeated by the " << playerPath->getEnemy()->getName() << "!" << endl;
                gameOver = true;
                return;
            }
        }
        if (kingsLand.mainPathsVisitedWithBoss()) {
            screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 12, "Congratulations! You have defeated the boss of the Kings Land! \nYou have completed the game!\n", false);
            gameOver = true;
        }
    }
}

bool Game::getGameOver() const {
    return gameOver;
}

Pathways* Game::choosePath(Pathways& areaPaths) {
    PathwaysDisplay display;

    display.showAvailablePaths(areaPaths);

    int userchoice;
    cout << "Choose a path to travel to: " << endl;
    cin >> userchoice;

    return areaPaths.userTraverse(userchoice);
}

void Game::userPathChoice(Player& player, Inventory& playerInventory, Pathways* &playerPath, Pathways& areaPaths) {
    while (!areaPaths.travelPathsVisited()) {
            playerPath = choosePath(areaPaths);

            if (playerPath != nullptr && playerPath->hasEnemy()) {

                vector<int> unlockedSkills = getUnlockedSkillsForPlayer(player);
                cPlayer combatPlayer(player.getName(), player.getHealth(), player.getMaxHealth(), player.getStrength(), player.getDefense(), player.getSpeed(), player.getMagicStrength(), unlockedSkills);

                //shows you the enemy you're facing, david's classes can handle the rest of output
                screenDisplay.displayEnemy("../ScreenDisplay/txtfiles/monsters.txt", playerPath->getEnemy()->getName());

                Combat combat(combatPlayer, *playerPath->getEnemy(), playerInventory);
                combat.startCombat();

                player.setHealth(combatPlayer.getHealth());

                if (!combatPlayer.isAlive()) {
                    cout << "You have been defeated by the " << playerPath->getEnemy()->getName() << "!" << endl;
                    gameOver = true;
                    return;
                } else if (!playerPath->getEnemy()->isAlive()) {
                    player.addXP(playerPath->getEnemy()->xpReward());
                    playerInventory.addCoin(playerPath->getEnemy()->goldReward());
                    player.checkLevelUp();
                    playerPath->markVisited();
                } else {
                    cout << "You escaped from the " << playerPath->getEnemy()->getName() << "." << endl;
                    return;
                }
            }

            if (playerPath != nullptr && playerPath->hasShop()) {
                screenDisplay.display("../ScreenDisplay/txtfiles/map.txt", 13, "Entering a shop...\n", true);

                ShopDisplay display;
                display.displayItems(*playerPath->getShop()); 
                int userChoice = 0;
                while (userChoice != 3) {
                    cout << "You have " << playerInventory.getCoin() << " gold." << endl;
                    cout << "Press 1 if you would like to see item descriptions, or 2 if you'd like to purchase an item, or 3 if you'd like to leave the shop: " << endl << endl;
                    cin >> userChoice;

                    if (userChoice == 1) {
                        int itemChoice;
                        cout << "Enter the number of the item you'd like to see the description of: " << endl;
                        cin >> itemChoice;
                        display.displayDescription(*playerPath->getShop(), itemChoice);
                    } else if (userChoice == 2) {
                        int itemChoice;
                        cout << "Enter the number of the item you'd like to purchase: " << endl;
                        cin >> itemChoice;
                        playerPath->getShop()->purchaseItem(itemChoice, playerInventory, player);
                    } else if (userChoice == 3) {
                        cout << "You have left the shop." << endl << endl;
                        playerPath->markVisited();
                        return;
                    }
                }
            }
        }
}


//helper function for combat, checks unlocked skills so that it works with all the classes
vector<int> Game::getUnlockedSkillsForPlayer(const Player& player) {
    vector<int> unlockedSkills;
    int level = player.getPlayerLevel();

    unlockedSkills.push_back(0); // strike
    unlockedSkills.push_back(1); // heal

    if(level >= 2) {
        if(player.getName() == "MAGE") {
            unlockedSkills.push_back(5); // flame spark
        } else {
            unlockedSkills.push_back(2); // power tackle
        }
    }

    if(level >= 4) {
        if(player.getName() == "KNIGHT") {
            unlockedSkills.push_back(10); // knight's precision
        } else if(player.getName() == "ASSASSIN") {
            unlockedSkills.push_back(16); // sabotage
        } else if(player.getName() == "TANK") {
            unlockedSkills.push_back(4); // war cry
        } else if(player.getName() == "MAGE") {
            unlockedSkills.push_back(6); // ice shard
        }
    }

    if(level >= 7) {
        if(player.getName() == "KNIGHT") {
            unlockedSkills.push_back(4); // war cry
        } else if(player.getName() == "ASSASSIN") {
            unlockedSkills.push_back(3); // warmup
        } else if(player.getName() == "TANK") {
            unlockedSkills.push_back(8); // reinforce
        } else if(player.getName() == "MAGE") {
            unlockedSkills.push_back(7); // recall wisdom
        }
    }

    if(level >= 12) {
        if(player.getName() == "KNIGHT") {
            unlockedSkills.push_back(18); // knight's dance
        } else if(player.getName() == "ASSASSIN") {
            unlockedSkills.push_back(21); // retreating rush
        } else if(player.getName() == "TANK") {
            unlockedSkills.push_back(11); // armored tackle
        } else if(player.getName() == "MAGE") {
            unlockedSkills.push_back(19); // arcane drain
        }
    }

    if(level >= 15) {
        if(player.getName() == "KNIGHT") {
            unlockedSkills.push_back(20); // knight's strength
        } else if(player.getName() == "ASSASSIN") {
            unlockedSkills.push_back(9); // all-out blitz
        } else if(player.getName() == "TANK") {
            unlockedSkills.push_back(17); // brute force
        } else if(player.getName() == "MAGE") {
            unlockedSkills.push_back(22); // arcane surge
        }
    }

    if(level >= 20) {
        if(player.getName() == "KNIGHT") {
            unlockedSkills.push_back(13); // the peak of swordsmanship
        } else if(player.getName() == "ASSASSIN") {
            unlockedSkills.push_back(15); // desperate measures
        } else if(player.getName() == "TANK") {
            unlockedSkills.push_back(14); // the greatest offense
        } else if(player.getName() == "MAGE") {
            unlockedSkills.push_back(12); // pinnacle of magic
        }
    }

    return unlockedSkills;
}
