#ifndef BOOTS_H
#define BOOTS_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class Boots : public Item {    

    public:
        string getName() const override{
            return "Boots";
        }

        int getPrice() const override{
            return 65;
        }

        void itemDescription() const override{
            std::cout << "Boots that increases speed. Effects apply permanently upon purchase." << endl;
        }

        void use(Player& Player) const override{
            Player.addSpeed(2);
        }
};

#endif //BOOTS_H