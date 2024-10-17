#pragma once
#include <iostream>
#include "item.h"

class Armor : public Item
{
private:
    std::string mName;
    int mDEF;
    int mExtra_DEF;
    int mDurability;

public:
    // Constructor with category parameter
    Armor(std::string Name, int DEF, int Extra_DEF, int Durability);

    // Getter
    auto get_name() const->std::string override;
    auto get_defensive() const -> int override;
    auto get_extra_defensive() const -> int override;
    auto get_durability() const -> int override;

    // Methods
    auto display_item() const -> void override;
};
