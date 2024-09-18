#pragma once
#include <iostream>
#include <vector>
#include "item.h"

class Inventory
{
private:
    std::vector<Item*> inventory;

public:
    // Constructor
    Inventory();

    // Getter
    auto get_inventory() -> std::vector<Item*>&;
    auto get_inv_item(int index) -> Item*;

    // Methods
    auto add_item(Item* obj) -> void;
    auto remove_item(Item* obj) -> void;
    auto display_inventory() -> void;
};
