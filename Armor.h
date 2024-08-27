#pragma once
#include <iostream>
#include "Item.h"

class Armor : public Item
{
private:
	std::string name;
	int defensive, extra_defensive;
	int durability;

public:
	// init
	Armor(std::string name, int defensive, int extra_defensive, int durability);

	// getter
	std::string get_name() const override;
	int get_defensive() const override;
	int get_extra_defensive() const override;
	int get_durability() const override;

	// methods
	void display_item() const override;
	std::unique_ptr<Item> clone() const override;
};
