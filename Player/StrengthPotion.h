#ifndef STRENGTHPOTION_H
#define STRENGTHPOTION_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class StrengthPotion : public Item {    

    public:
        string getName() const override{
            return "Strength Potion";
        }

        int getPrice() const override{
            return 50;
        }

        void itemDescription() const override{
            std::cout << "A  potion that greatly increases attack damage. Only usable in battle with a temporary Attack boost." << endl;
        }

        void use(Player& Player) const override{
            Player.addAtk(3);
        }
};

#endif //STRENGTHPOTION_H