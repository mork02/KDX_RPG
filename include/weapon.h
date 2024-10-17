#pragma once
#include <iostream>
#include "item.h"

class Weapon : public Item
{
private:
    std::string mName;
    int mDMG;
    int mExtra_DMG;
    int mDurability;

public:
    Weapon(std::string Name, int DMG, int Extra_DMG, int Durability);

    auto get_name() const->std::string override;
    auto get_dmg() const -> int override;
    auto get_extra_dmg() const -> int override;
    auto get_durability() const -> int override;

    auto display_item() const -> void override;
};
