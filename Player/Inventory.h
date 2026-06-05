#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Inventory {
    private: 
        vector<Item*> items = {};
        int coinCount = 0;

    public:
        void addItem(Item* item);
        void removeItem(string item);
        void useItem(string item);
        int findItem(string item);
        int getCoin();
        void setCoinCount(int count);
        void removeCoin(int count);
        void addCoin(int count);

        const vector<Item*>& getItems() const;
};

#endif //INVENTORY_H