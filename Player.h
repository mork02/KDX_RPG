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
	Character stats_player;
	Inventory inventory;


public:
	// init
	Player(std::string name, int hp, int basic_dmg, int basic_defensive);

	// getter
	std::string get_name();
	Item* get_weapon_slot() const;
	int get_DMG_player();
	Item* get_armor_slot() const;
	int get_DEFENSIVE_player();
	Character stats();
	Inventory get_inventory();

	// setter
	void set_weapon_slot(const Item& obj);
	void set_armor_slot(const Item& obj);

	// methods
	void use_potion();

};