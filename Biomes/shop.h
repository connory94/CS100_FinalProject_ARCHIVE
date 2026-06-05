#ifndef SHOP_H
#define SHOP_H
#include <string>
#include <vector>
#include "../Player/Player.h"
#include "../Player/Inventory.h"
#include "../Player/Item.h"
#include "../Player/Boots.h"
#include "../Player/DefensePotion.h"
#include "../Player/HealthPotion.h"
#include "../Player/Shield.h"
#include "../Player/Staff.h"
#include "../Player/SpeedPotion.h"
#include "../Player/StrengthPotion.h"
#include "../Player/Sword.h"
#include <iostream>
#include <random>

class Shop {
    private:
        std::vector<Item*> items;
    public:
        Shop(std::vector<Item*> items);

        bool purchaseItem(int itemNum, Inventory& playerInv, Player& player);

        std::vector<Item*> getItems() const;

        ~Shop();
};

class ShopDisplay {
    public:
        void displayItems(const Shop& shop);
        void displayDescription(const Shop& shop, int itemNum);
};

#endif //SHOP_H