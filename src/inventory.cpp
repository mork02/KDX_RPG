#include "inventory.h"

CInventory::CInventory() {}


auto CInventory::get_inventory() -> std::vector<Item*>&
{
    return mInventory;
}

auto CInventory::get_inv_item(int index) -> Item*
{
    if (index >= 0 && index < static_cast<int>(mInventory.size()))
    {
        return mInventory[index];
    }
    return nullptr;
}


auto CInventory::add_item(Item* obj) -> void
{
    mInventory.push_back(obj);
}

auto CInventory::remove_item(Item* obj) -> void
{
    auto item = std::find(mInventory.begin(), mInventory.end(), obj);
    if (item != mInventory.end())
    {
        mInventory.erase(item);
    }
    else
    {
        std::cerr << "Item not found in inventory. Cannot remove." << std::endl;
    }
}

auto CInventory::display_inventory() -> void
{
    int x = 0;
    for (const auto* item : mInventory)
    {
        std::cout << "ID: " << x << std::endl;
        item->display_item();
        x++;
    }
}
