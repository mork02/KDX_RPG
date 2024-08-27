#pragma once
#include <iostream>
#include "Item.h"

class Weapon : public Item
{
private:
	std::string name;
	int dmg, extra_dmg;
	int durability;


public:
	// init
	Weapon(std::string name, int dmg, int extra_dmg, int durability);

	// getter
	int get_id() const override;
	std::string get_name() const override;
	int get_dmg() const override;
	int get_extra_dmg() const override;
	int get_durability() const override;

	// methods
	void display_item() const override;
	std::unique_ptr<Item> clone() const override;

};

