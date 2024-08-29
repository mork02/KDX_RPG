#include "Inventory.h"

Inventory::Inventory() {}

// getter

const std::vector<std::unique_ptr<Item>>& Inventory::get_inventory() const {
    return inventory;
}

// methods

void Inventory::add_item(const Item& obj)
{
    inventory.push_back(obj.clone());
}

void Inventory::remove_item(const Item& obj)
{
    
}

void Inventory::display_inventory()
{
    for (const auto& item : inventory)
    {
        item->display_item();
    }
}
