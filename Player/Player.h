#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
    protected:
        std::string name;
        int health;
        int attackStrength;
        int magicStrength;
        int coinCollected;
        int defense;
        int speed;
        int xp;
        int playerLevel;
        int levelCap = 13;
        //david -- needed max health for combat
        int maxHealth;

    public:
        Player(std::string name, int health, int defense, int attackStrength, int magicStrength, int speed);
        virtual ~Player() {}
        std::string getName() const;
        int getHealth() const;
        int getDefense() const;
        int getStrength() const;
        int getMagicStrength() const;
        int getSpeed() const;
        void pickClass();
        void levelUp();
        void takeDamage(int damage);
        void addHealth(int amount);
        void addAtk(int amount);
        void addDefence(int amount);
        void addMagicAtk(int amount);
        void addSpeed(int amount);
        void removeAtkStat(int amount);
        void removeDefenceStat(int amount);
        void removeMagicAtkStat(int amount);
        void removeSpeedStat(int amount);

        void setName(std::string newName);
        void setHealth(int health);
        void addMaxHealth(int amount);
        int getMaxHealth() const;
        void addXP(int amount);
        int getXP() const;
        void checkLevelUp();
        void classLevelUp();
        int getPlayerLevel() const;
};

// all StatsUp functions are kinda redundant since i added the classLevelUp function so I commented them out -- david

class Knight : public Player {
    public:
        Knight(int health, int defense, int attackStrength, int magicStrength, int speed);
        //void KnightStatsUp();
};

class Assassin : public Player {
    public:
        Assassin(int health, int defense, int attackStrength, int magicStrength, int speed);
        //void AssassinStatsUp();
};

class Tank : public Player {
    public:
        Tank(int health, int defense, int attackStrength, int magicStrength, int speed);
        //void TankStatsUp();
};

class Mage : public Player {
    public:
        Mage(int health, int defense, int attackStrength, int magicStrength, int speed);
        //void MageStatsUp();
};

#endif //Player_H