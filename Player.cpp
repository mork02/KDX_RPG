#include "Player.h"

Player::Player() : stats(100, 0, 0) 
{
}

// Getter //

std::string Player::get_name() { return name; }

Character Player::get_stats() { return stats; }

Inventory& Player::get_inventory() { return inventory; }

Item* Player::get_weapon_slot()
{
    if (weapon_slot) {
        return weapon_slot;
    }
    else {
        std::cerr << "No weapon equipped." << std::endl;
        return nullptr; 
    }
}
//

// Setter //

void Player::set_name(std::string new_name) { name = new_name; }

void Player::set_weapon_slot(int index)
{
    if (index >= 0 && index < inventory.get_inventory().size())
    {
        weapon_slot = inventory.get_inventory()[index];
        inventory.remove_item(this->weapon_slot);
    }
    else
    {
        std::cerr << "Invalid index. Cannot equip item." << std::endl;
    }
}

//

// Methods
