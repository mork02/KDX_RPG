#include "player.h"

Player::Player() : name("Adventurer"), Entitie(100, 0, 0)
{
}

// Getter //

auto Player::get_name() -> std::string
{
    return name;
}

auto Player::get_inventory() -> Inventory&
{
    return inventory;
}

auto Player::get_weapon_slot() -> Item*
{
    return weapon_slot;
}

auto Player::get_armor_slot() -> Item*
{
    return armor_slot;
}

// Setter //

auto Player::set_name(std::string new_name) -> void
{
    name = new_name;
}

auto Player::set_weapon_slot(int index) -> void
{
    if (index >= 0 && index < static_cast<int>(inventory.get_inventory().size()))
    {
        weapon_slot = inventory.get_inventory()[index];
        inventory.remove_item(weapon_slot);
    }
    else
    {
        std::cerr << "Invalid index. Cannot equip item." << std::endl;
    }
}

auto Player::set_armor_slot(int index) -> void
{
    if (index >= 0 && index < static_cast<int>(inventory.get_inventory().size()))
    {
        armor_slot = inventory.get_inventory()[index];
        inventory.remove_item(armor_slot);
    }
    else
    {
        std::cerr << "Invalid index. Cannot equip item." << std::endl;
    }
}

// Methods //

auto Player::display_weapon_slot() -> void
{
    if (weapon_slot)
    {
        weapon_slot->display_item();
    }
    else
    {
        std::cout << "No Item\n";
    }
}

auto Player::display_armor_slot() -> void
{
    if (armor_slot)
    {
        armor_slot->display_item();
    }
    else
    {
        std::cout << "No Item\n";
    }
}
