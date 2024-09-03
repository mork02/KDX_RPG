#pragma once
#include "character.h"
#include "inventory.h"
#include "item.h"
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
    Item* armor_slot;

public:
    Player();

    // Getter 
    std::string get_name();
    Character& get_stats();
    Inventory& get_inventory(); 
    Item* get_weapon_slot();
    Item* get_armor_slot();

    // Setter 
    void set_name(std::string new_name);
    void set_weapon_slot(int id);
    void set_armor_slot(int id);

    // Methods
    void display_weapon_slot();
    void display_armor_slot();
};
