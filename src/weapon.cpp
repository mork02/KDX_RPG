#include "weapon.h"

// Constructor

Weapon::Weapon(std::string name_c, int dmg_c, int extra_dmg_c, int durability_c)
    : name(name_c), dmg(dmg_c), extra_dmg(extra_dmg_c), durability(durability_c), Item(Category::WEAPON) {}

// Getter

auto Weapon::get_name() const -> std::string
{
    return name;
}

auto Weapon::get_dmg() const -> int
{
    return dmg;
}

auto Weapon::get_extra_dmg() const -> int
{
    return extra_dmg;
}

auto Weapon::get_durability() const -> int
{
    return durability;
}

// Methods

auto Weapon::display_item() const -> void
{
    try
    {
        std::cout << "Name: " << name << "\nDmg: " << dmg << " + " << extra_dmg << "\nDurability: " << durability << "\n" << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "No item equipped!" << std::endl;
    }
}
