#ifndef STAFF_H
#define STAFF_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class Staff : public Item {    

    public:
        string getName() const override{
            return "Staff";
        }

        int getPrice() const override{
            return 80;
        }

        void itemDescription() const override{
            std::cout << "A  Staff that increases magic damage. Effects apply permanently upon purchase." << endl;
        }

        void use(Player& Player) const override{
            Player.addMagicAtk(4);
        }
};

#endif //STAFF_H