#pragma once
#include <iostream>
#include <vector>
#include "Item.h"

#pragma once
class Inventory
{
private:
	std::vector<std::unique_ptr<Item>> inventory;

public:
	//init
	Inventory();

	//getter
	const std::vector<std::unique_ptr<Item>>& get_inventory() const;

	// methods
	void add_item(const Item& obj);
	void remove_item(const Item& obj);
	void display_inventory();
};

