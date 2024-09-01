#pragma once
#include <iostream>
#include "Item.h"

class Weapon : public Item
{
private:
    // int id;
    std::string name;
    int dmg, extra_dmg;
    int durability;

public:
    // Constructor with category parameter
    Weapon(std::string name, int dmg, int extra_dmg, int durability);

    // Getter
    // int get_id() const override;
    std::string get_name() const override;
    int get_dmg() const override;
    int get_extra_dmg() const override;
    int get_durability() const override;

    // Methods
    void display_item() const override;
};
