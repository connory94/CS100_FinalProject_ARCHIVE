#include <string>
#include <iostream>
#include <vector>
#include "Inventory.h"

using namespace std;

const vector<Item*>& Inventory::getItems() const {
    return items;
}

void Inventory::addItem(Item* item) {
    items.push_back(item);
}

void Inventory::removeItem(string item) {
    int found = findItem(item);

    if(found == -1) {
        cout << "Item not found" << endl;
        return;
    }

    for(size_t j = found; j < items.size()-1; j++) {
        items[j] = items[j + 1];
    }

    items.pop_back();
    cout << item << " has been removed from inventory." << endl;

}

void Inventory::useItem(string item) {
    int found = findItem(item);
    if(found == -1) {
        cout << "Item not found" << endl;
        return;
    }
    items[found]->itemDescription();
    removeItem(item);
}


int Inventory::findItem(string item) {
    int i = 0;
    while(i < items.size()) {
        if(items[i]->getName() == item) {
            return i;
        }
        i++;
    }
    return -1;
}

int Inventory::getCoin() {
    return coinCount;
}

void Inventory::setCoinCount(int count) {
    coinCount = count;
    cout << "Coins have: " << coinCount << endl;
}

void Inventory::removeCoin(int count) {
    int coinRemove = count;
    cout << "Coins removed: " << coinRemove << endl;
    coinCount -= coinRemove;
    cout << "Coins current have: " << coinCount << endl;
}

void Inventory::addCoin(int count) {
    int coinAdd = count;
    cout << "Coins added: " << coinAdd << endl;
    coinCount += coinAdd;
    cout << "Coins current have: " << coinCount << endl;
}