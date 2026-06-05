#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <vector>
#include <iostream>
#include "Player.h"

using namespace std;

class Item{    

    public:

        virtual ~Item() {}
        virtual string getName() const = 0;
        virtual int getPrice() const = 0;
        virtual void itemDescription() const = 0;
        virtual void use(Player& Player) const = 0;
        
        
};

#endif //ITEM_H