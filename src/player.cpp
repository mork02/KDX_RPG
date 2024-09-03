#include "player.h"

Player::Player() : name("Advaturer"), stats(100, 0, 0)
{
}

// Getter //

std::string Player::get_name() { return name; }

Character& Player::get_stats() { return stats; }

Inventory& Player::get_inventory() { return inventory; }

Item* Player::get_weapon_slot() { return weapon_slot; }

Item* Player::get_armor_slot() { return armor_slot; }
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

void Player::set_armor_slot(int index)
{
    if (index >= 0 && index < inventory.get_inventory().size())
    {
        armor_slot = inventory.get_inventory()[index];
        inventory.remove_item(this->armor_slot);
    }
    else
    {
        std::cerr << "Invalid index. Cannot equip item." << std::endl;
    }
}

//

// Methods

void Player::display_weapon_slot()
{
    Item* item = get_weapon_slot();
    if (item)
    {
        item->display_item();
    }
    else
    {
        std::cout << "No Item\n";
    }
}

void Player::display_armor_slot()
{
    Item* item = get_armor_slot();
    if (item)
    {
        item->display_item();
    }
    else
    {
        std::cout << "No Item\n";
    }
}