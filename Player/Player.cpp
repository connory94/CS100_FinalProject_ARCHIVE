#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string name, int health, int defense, int attackStrength, int magicStrength, int speed) {
    this->name = name;
    this->health = health;
    this->defense = defense;
    this->attackStrength = attackStrength;
    this->magicStrength = magicStrength;
    this->speed = speed;
    xp = 0;
    playerLevel = 1;
    coinCollected = 0;

    this->maxHealth = health;
}

string Player::getName() const{
    return name;
}

int Player::getHealth() const{
    return health;
}

int Player::getMaxHealth() const{
    return maxHealth;
}

int Player::getDefense() const{
    return defense;
}

int Player::getStrength() const{
    return attackStrength;
}

int Player::getMagicStrength() const{
    return magicStrength;
}

int Player::getSpeed() const{
    return speed;
}


void Player::pickClass() {
    string chosen;
    string choice;
    cin >> chosen; 

    Player* classStats = nullptr;

    if(chosen == "KNIGHT") {
        classStats = new Knight(40, 6, 13, 3, 7);
    } else if(chosen == "ASSASSIN") {
        classStats = new Assassin(32, 4, 15, 5, 11);
    } else if(chosen == "TANK") {
        classStats = new Tank(50, 9, 10, 2, 4);
    } else if(chosen == "MAGE") {
        classStats = new Mage(30, 4, 5, 13, 10);
    } else {
        cout << "Wrong input try again." << endl;
        pickClass();
        return;
    }

    cout << " Class: " << chosen << endl;
    cout << " Health: " << classStats->getHealth() << endl;
    cout << " Defense: " << classStats->getDefense() << endl;
    cout << " Attack: " << classStats->getStrength() << endl;
    cout << " Magic: " << classStats->getMagicStrength() << endl;
    cout << " Speed: " << classStats->getSpeed() << endl;

    cout << "Chosen the class: " << chosen << "." << endl;
    cout << "Confirm choice (y/n): ";
    cin >> choice;
    if(choice == "y" || choice == "Y") {
        name = chosen;
        health = classStats->getHealth();
        maxHealth = classStats->getMaxHealth();
        defense = classStats->getDefense();
        attackStrength = classStats->getStrength();
        magicStrength = classStats->getMagicStrength();
        speed = classStats->getSpeed();
        cout << "Choice confirm." << endl;
        delete classStats;
        return;
    }
    delete classStats;
    cout << "Please Choose again." << endl;
    pickClass();
    return;
}

void Player::levelUp() {

    playerLevel++;
    cout << "Player level increase to: " << playerLevel << "." << endl;
    maxHealth += 2;
    health += 2;

    //changed numbers for difficulty scaling
    if(playerLevel % 3 == 0) {
        attackStrength += 1;
        magicStrength += 1;
    }

    if(playerLevel % 3 == 0) {
        defense += 1;
    }

    if(playerLevel % 4 == 0) {
        speed += 1;
    }

    xp -= levelCap;
    levelCap += 1;
}

void Player::checkLevelUp() {
    while(xp >= levelCap) {
        classLevelUp();
    }
}

int Player::getPlayerLevel() const{
    return playerLevel;
}

void Player::classLevelUp() {
    if(name == "KNIGHT") {
        levelUp();

        if(playerLevel % 4 == 0) {
            attackStrength += 1;
        }

        if(playerLevel % 3 == 0) {
            maxHealth += 1;
            health += 1;
        }
    } else if(name == "ASSASSIN") {
        levelUp();

        if(playerLevel % 3 == 0) {
            attackStrength += 1;
        }

        if(playerLevel % 5 == 0) {
            speed += 1;
        }
    } else if(name == "TANK") {
        levelUp();

        if(playerLevel % 3 == 0) {
            maxHealth += 2;
            health += 2;
        }

        if(playerLevel % 4 == 0) {
            defense += 1;
        }
    } else if(name == "MAGE") {
        levelUp();

        if(playerLevel % 3 == 0) {
            magicStrength += 1;
        }

        if(playerLevel % 5 == 0) {
            maxHealth += 1;
            health += 1;
        }
    } else {
        levelUp();
    }
}

void Player::takeDamage(int damage) {
    this->health -= damage;

    if(this->health < 0) {
        this->health = 0;
    }
}

void Player::addXP(int amount) {
    xp += amount;
    cout << "XP gained: " << amount << endl;
    cout << "Current XP: " << xp << "/" << levelCap << endl;
}

int Player::getXP() const {
    return xp;
}

void Player::addHealth(int addedHealth) {
    this->health += addedHealth;

    if(this->health > maxHealth) {
        this->health = maxHealth;
    }
}

void Player::setHealth(int health) {
    this->health = health;

    if(this->health > maxHealth) {
        this->health = maxHealth;
    }

    if(this->health < 0) {
        this->health = 0;
    }
}

void Player::addAtk(int amount) {
    this->attackStrength += amount;
}

void Player::addDefence(int amount) {
    this->defense += amount;
}

void Player::addMagicAtk(int amount) {
    this->magicStrength += amount;
}

void Player::addSpeed(int amount) {
    this->speed += amount;
}

void Player::removeAtkStat(int amount) {
    this->attackStrength -= amount;
}

void Player::removeDefenceStat(int amount) {
    this->defense -= amount;
}

void Player::removeMagicAtkStat(int amount) {
    this->magicStrength -= amount;
}

void Player::removeSpeedStat(int amount) {
    this->speed -= amount;
}

//added this for the intro sequence
void Player::setName(string newName){
    name = newName;
}

// all StatsUp functions are kinda redundant since i added the classLevelUp function so I commented them out -- david

Knight::Knight(int health, int defense, int attackStrength, int magicStrength, int speed) : Player("Knight", health, defense, attackStrength, magicStrength, speed) {}

// void Knight::KnightStatsUp() {
//     levelUp();
//     this->health += 20;
//     this->maxHealth += 20;
//     this->attackStrength += 20;
// }

Assassin::Assassin(int health, int defense, int attackStrength, int magicStrength, int speed) : Player("Assassin", health, defense, attackStrength, magicStrength, speed) {}

// void Assassin::AssassinStatsUp() {
//     levelUp();
//     this->attackStrength += 30;
//     this->magicStrength += 10;
// }

Tank::Tank(int health, int defense, int attackStrength, int magicStrength, int speed) : Player("Tank", health, defense, attackStrength, magicStrength, speed) {}

// void Tank::TankStatsUp() {
//     levelUp();
//     this->health += 30;
//     this->maxHealth += 30;
//     this->defense += 30;
// }

Mage::Mage(int health, int defense, int attackStrength, int magicStrength, int speed) : Player("Mage", health, defense, attackStrength, magicStrength, speed) {}

// void Mage::MageStatsUp() {
//     levelUp();
//     this->defense += 10;
//     this->magicStrength += 30;
// }
