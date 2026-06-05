#ifndef SPEEDPOTION_H
#define SPEEDPOTION_H
#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class SpeedPotion : public Item {    

    public:
        string getName() const override{
            return "Speed Potion";
        }

        int getPrice() const override{
            return 55;
        }

        void itemDescription() const override{
            std::cout << "Potion that greatly increases speed. Only usable in battle with a temporary Speed boost." << endl;
        }

        void use(Player& Player) const override{
            Player.addSpeed(5);
        }
};

#endif //SPEEDPOTION_H