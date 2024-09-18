#include "armor.h"

// Constructor

Armor::Armor(std::string name_c, int defensive_c, int extra_defensive_c, int durability_c)
    : name(name_c), defensive(defensive_c), extra_defensive(extra_defensive_c), durability(durability_c), Item(Category::ARMOR) {}

// Getter

auto Armor::get_name() const -> std::string
{
    return name;
}

auto Armor::get_defensive() const -> int
{
    return defensive;
}

auto Armor::get_extra_defensive() const -> int
{
    return extra_defensive;
}

auto Armor::get_durability() const -> int
{
    return durability;
}

// Methods

auto Armor::display_item() const -> void
{
    try
    {
        std::cout << "Name: " << name << "\nDefensive: " << defensive << " + " << extra_defensive
            << "\nDurability: " << durability << "\n" << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "No item equipped!" << std::endl;
    }
}
