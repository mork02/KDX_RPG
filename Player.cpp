#include "Player.h"

Player::Player(std::string name_c, int hp_c, int basic_dmg_c, int defensive_c, int extra_defensive_c)
	: name(name_c), weapon_slot(), armor_slot(), stats(hp_c, basic_dmg_c, defensive_c, extra_defensive_c)
{
	std::cout << name << " is created!" << std::endl;
}

// getter

std::string Player::get_name() { return name; }

std::unique_ptr<Item> Player::get_weapon_slot()
{
	if (weapon_slot) {
		return std::move(weapon_slot);
	}
	return nullptr;
}

std::unique_ptr<Item> Player::get_armor_slot()
{
	if (armor_slot) {
		return std::move(armor_slot); 
	}
	return nullptr;
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