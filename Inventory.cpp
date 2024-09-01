#include "Inventory.h"

Inventory::Inventory() {}

// getter

std::vector<Item*>& Inventory::get_inventory() { return inventory; }

Item* Inventory::get_inv_item(int index)
{
    return inventory[index];
}

// methods

void Inventory::add_item(Item* obj)
{
    inventory.push_back(obj);
}

void Inventory::remove_item(Item* obj)
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

void Inventory::display_inventory()
{
    int x = 0;
    for (const auto* item : inventory)
    {
        std::cout << "ID: " << x << std::endl;
        item->display_item();
        x++;
    }
}
