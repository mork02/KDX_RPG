#pragma once
#include "Character.h"
#include "Inventory.h"
#include "Item.h"
#include <memory>
#include <iostream>
#include <vector>

class Player
{
private:
	std::string name;
	std::unique_ptr<Item> weapon_slot;
	std::unique_ptr<Item> armor_slot;


public:
	// init
	Player(std::string name, int hp, int basic_dmg, int defensive, int extra_defensive);
	Character stats;
	Inventory inventory;

	// getter
	std::string get_name();
	std::unique_ptr<Item> get_weapon_slot();
	std::unique_ptr<Item> get_armor_slot();

	// setter
	void set_weapon_slot(const Item& obj);
	void set_armor_slot(const Item& obj);

	// methods
	void use_potion();

};