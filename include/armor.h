#pragma once
#include <iostream>
#include "item.h"

class Armor : public Item
{
private:
    std::string name;
    int defensive;
    int extra_defensive;
    int durability;

public:
    // Constructor with category parameter
    Armor(std::string name, int defensive, int extra_defensive, int durability);

    // Getter
    auto get_name() const->std::string override;
    auto get_defensive() const -> int override;
    auto get_extra_defensive() const -> int override;
    auto get_durability() const -> int override;

    // Methods
    auto display_item() const -> void override;
};
