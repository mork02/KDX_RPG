#pragma once
#include "entitie.h"
#include "inventory.h"
#include "item.h"
#include <memory>
#include <iostream>
#include <vector>

class Player : public Entitie
{
private:
    std::string name;
    Inventory inventory;

    Item* weapon_slot = nullptr;
    Item* armor_slot = nullptr;

public:
    Player();

    // Getter
    auto get_name() -> std::string;
    auto get_inventory() -> Inventory&;
    auto get_weapon_slot() -> Item*;
    auto get_armor_slot() -> Item*;

    // Setter
    auto set_name(std::string new_name) -> void;
    auto set_weapon_slot(int id) -> void;
    auto set_armor_slot(int id) -> void;

    // Methods
    auto display_weapon_slot() -> void;
    auto display_armor_slot() -> void;
};
