#include "Player.h"

Player::Player(std::string name_c, int hp_c, int basic_dmg_c, int basic_defensive_c)
	: name(name_c), weapon_slot(), armor_slot(), stats_player(hp_c, basic_dmg_c, basic_defensive_c)
{
	std::cout << name << " is created!" << std::endl;
}

// getter

std::string Player::get_name() { return name; }

Item* Player::get_weapon_slot() const { return weapon_slot.get(); }

int Player::get_DMG_player() {
	auto weapon = get_weapon_slot();

	if (weapon) {
		return stats().get_basic_dmg() + weapon->get_dmg();
	}

	return stats().get_basic_dmg();
}

Item* Player::get_armor_slot() const { return armor_slot.get();  }

int Player::get_DEFENSIVE_player()
{
	auto armor = get_armor_slot();

	if (armor) {
		return stats().get_basic_defensive() + armor->get_dmg();
	}

	return stats().get_basic_defensive();
}

Character Player::stats()
{
	return stats_player;
}

Inventory Player::get_inventory()
{
	return inventory;
}

// setter

void Player::set_weapon_slot(const Item& obj)
{
	weapon_slot = obj.clone();
}

void Player::set_armor_slot(const Item& obj)
{
	armor_slot = obj.clone();
}


// methods

void Player::use_potion() 
{
	
}