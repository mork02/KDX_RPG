#pragma once
#include <iostream>
#include <vector>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item*> inventory;

public:
    // init
    Inventory();

    // getter
    std::vector<Item*>& get_inventory(); 
    Item* get_inv_item(int index);

    // methods
    void add_item(Item* obj);
    void remove_item(Item* obj); 
    void display_inventory();
};
