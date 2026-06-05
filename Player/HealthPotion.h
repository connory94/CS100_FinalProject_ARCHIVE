#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class HealthPotion : public Item {    

    public:
        string getName() const override{
            return "Health Potion";
        }

        int getPrice() const override{
            return 35;
        }

        void itemDescription() const override{
            std::cout << "Potion that greatly increases Health. Only usable in battle." << endl;
        }

        void use(Player& Player) const override{
            Player.addHealth(40);
        }
};

#endif //HEALTHPOTION_H