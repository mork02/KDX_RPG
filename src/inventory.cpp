#include "inventory.h"

Inventory::Inventory() {}


auto Inventory::get_inventory() -> std::vector<Item*>&
{
    return inventory;
}

auto Inventory::get_inv_item(int index) -> Item*
{
    if (index >= 0 && index < static_cast<int>(inventory.size()))
    {
        return inventory[index];
    }
    return nullptr;  // Return nullptr if index is out of bounds
}


auto Inventory::add_item(Item* obj) -> void
{
    inventory.push_back(obj);
}

auto Inventory::remove_item(Item* obj) -> void
{
    auto it = std::find(inventory.begin(), inventory.end(), obj);
    if (it != inventory.end())
    {
        inventory.erase(it);
    }
    else
    {
        std::cerr << "Item not found in inventory. Cannot remove." << std::endl;
    }
}

auto Inventory::display_inventory() -> void
{
    int x = 0;
    for (const auto* item : inventory)
    {
        std::cout << "ID: " << x << std::endl;
        item->display_item();
        x++;
    }
}
