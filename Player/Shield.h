#ifndef SHIELD_H
#define SHIELD_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class Shield : public Item {    

    public:
        string getName() const override{
            return "Shield";
        }

        int getPrice() const override{
            return 70;
        }

        void itemDescription() const override{
            std::cout << "A  Shield that increases defense. Effects apply permanently upon purchase." << endl;
        }

        void use(Player& Player) const override{
            Player.addDefence(3);
        }
};

#endif //SHIELD_H