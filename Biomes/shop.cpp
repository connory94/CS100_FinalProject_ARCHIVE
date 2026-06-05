#include "shop.h"

using namespace std;

Shop::Shop(vector<Item*> items) {
    this->items = items;
}

vector<Item*> Shop::getItems() const {
    return items;
}

// checks coins and checks price, makes sure that you can buy it and if you can it adds the item to inventory, bool for error checking but functions as a void
bool Shop::purchaseItem(int itemNum, Inventory& playerInv, Player& player) {
    int realItemNum = itemNum - 1;

    if (realItemNum < 0 || realItemNum >= items.size()) {
        cout << "Invalid item number. Please try again." << endl;
        return false;
    }

    int itemPrice = items[realItemNum]->getPrice();
    // added checks for the item name so that non consumables are "used" immediately since you cant access them in battle -- david
    string itemName = items[realItemNum]->getName();

    if (playerInv.getCoin() >= itemPrice) {
        playerInv.removeCoin(itemPrice);

        if (itemName.find("Potion") != string::npos) {
            playerInv.addItem(items[realItemNum]);
        } else {
            items[realItemNum]->use(player);
        }

        cout << "You have purchased " << itemName << "!" << endl;
        return true;
    } else {
        cout << "You don't have enough coins to purchase " << itemName << "." << endl;
        return false;
    }
}

// seperate display class that displays the shop item descriptiosn
void ShopDisplay::displayDescription(const Shop& shop, int itemNum) {
    vector<Item*> shopItems = shop.getItems();

    int realItemNum = itemNum - 1;

    if (realItemNum < 0 || realItemNum >= shopItems.size()) {
        cout << "Invalid item number. Please try again." << endl;
        return;
    }

    shopItems[realItemNum]->itemDescription();
}

// seperate display class function that displays items
void ShopDisplay::displayItems(const Shop& shop) {
    vector<Item*> shopItems = shop.getItems();

    cout << "Welcome to our shop! Here is what you can buy:" << endl;
    for (size_t i = 0; i < shopItems.size(); i++) {
        cout << i + 1 << ". " << shopItems[i]->getName() << " - " << shopItems[i]->getPrice() << " coins" << endl;
    }
}

Shop::~Shop() {
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
}