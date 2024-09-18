#pragma once
#include <iostream>
#include "item.h"

class Weapon : public Item
{
private:
    std::string name;
    int dmg;
    int extra_dmg;
    int durability;

public:
    // Constructor with category parameter
    Weapon(std::string name, int dmg, int extra_dmg, int durability);

    // Getter
    auto get_name() const->std::string override;
    auto get_dmg() const -> int override;
    auto get_extra_dmg() const -> int override;
    auto get_durability() const -> int override;

    // Methods
    auto display_item() const -> void override;
};
