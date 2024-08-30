#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include <memory>
#include <iostream>
#include <vector>

class Player
{
private:
    std::string name;
    Character stats;
    Inventory inventory;

    Item* weapon_slot;

public:
    Player();

    // Getter 
    std::string get_name();
    Character get_stats();
    Inventory& get_inventory(); 
    Item* get_weapon_slot();

    // Setter 
    void set_name(std::string new_name);
    void set_weapon_slot(int id);

    // Methods
    bool check_empty();
};
