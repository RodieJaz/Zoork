//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_CHARACTER_H
#define ZOORK_CHARACTER_H

#include "GameObject.h"
#include "Item.h"
#include <vector>
#include <string>
#include <memory>

class Character : public GameObject {
public:
    Character(const std::string &, const std::string &);

protected:
    std::vector<std::shared_ptr<Item>> inventory;
    std::vector<std::string> tags;
    int health;
    int attack;
    int move;
    int initiative;
};

#endif //ZOORK_CHARACTER_H
