#ifndef DEFENSEPOTION_H
#define DEFENSEPOTION_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class DefensePotion : public Item {    

    public:
        string getName() const override{
            return "Defense Potion";
        }

        int getPrice() const override{
            return 40;
        }

        void itemDescription() const override{
            std::cout << "A  Potion that greatly increases defense. Only usable in battle with a temporary Defense boost." << endl;
        }

        void use(Player& Player) const override{
            Player.addDefence(5);
        }
};

#endif //DEFENSEPOTION_H