#include "armor.h"

Armor::Armor(std::string Name, int DEF, int Extra_DEF, int Durability)
    : mName(Name), mDEF(DEF), mExtra_DEF(Extra_DEF), mDurability(Durability), Item(Category::ARMOR) {}

auto Armor::get_name() const -> std::string
{
    return mName;
}

auto Armor::get_defensive() const -> int
{
    return mDEF;
}

auto Armor::get_extra_defensive() const -> int
{
    return mExtra_DEF;
}

auto Armor::get_durability() const -> int
{
    return mDurability;
}

auto Armor::display_item() const -> void
{
    try
    {
        std::cout << "Name: " << mName << "\nDefensive: " << mDEF << " + " << mExtra_DEF
            << "\nDurability: " << mDurability << "\n" << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "No item equipped!" << std::endl;
    }
}
