#include "weapon.h"

Weapon::Weapon(std::string Name, int DMG, int Extra_DMG, int Durability)
    : mName(Name), mDMG(DMG), mExtra_DMG(Extra_DMG), mDurability(Durability),
    Item(Category::WEAPON)
{}

auto Weapon::get_name() const -> std::string
{
    return mName;
}

auto Weapon::get_dmg() const -> int
{
    return mDMG;
}

auto Weapon::get_extra_dmg() const -> int
{
    return mExtra_DMG;
}

auto Weapon::get_durability() const -> int
{
    return mDurability;
}

auto Weapon::display_item() const -> void
{
    try
    {
        std::cout << "Name: " << mName << "\nDmg: " << mDMG << " + " << mExtra_DMG << "\nDurability: " << mDurability << "\n" << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "No item equipped!" << std::endl;
    }
}
