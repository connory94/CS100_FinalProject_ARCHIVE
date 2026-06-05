#ifndef SWORD_H
#define SWORD_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class Sword : public Item {    

    public:
        string getName() const override{
            return "Sword";
        }

        int getPrice() const override{
            return 80;
        }

        void itemDescription() const override{
            std::cout << "A  blade that increases attack damage. Effects apply permanently upon purchase." << endl;
        }

        void use(Player& Player) const override{
            Player.addAtk(3);
        }
};

#endif //SWORD_H