#pragma once
#include <iostream>
#include "item.h"

class Armor : public Item
{
private:
    std::string name;
    int defensive, extra_defensive;
    int durability;

public:
    // Constructor with category parameter
    Armor(std::string name, int defensive, int extra_defensive, int durability);

    // Getter
    std::string get_name() const override;
    int get_defensive() const override;
    int get_extra_defensive() const override;
    int get_durability() const override;

    // Methods
    void display_item() const override;
};