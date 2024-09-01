#include "Character.h"

Character::Character(int hp_c, int basic_dmg_c, int basic_defensive_c) : hp(hp_c), max_hp(hp_c), basic_dmg(basic_dmg_c), basic_defensive(basic_defensive_c) {}

// Getter

int Character::get_hp() const { return hp; }

int Character::get_max_hp() const { return max_hp; }

int Character::get_basic_dmg() const { return basic_dmg; }

int Character::get_basic_defensive() const { return basic_defensive; }


// Setter

void Character::set_hp(int amount)
{
	hp = hp + amount;
	if (hp > max_hp) 
	{
		hp = max_hp;
	}
}

void Character::set_max_hp(int amount)
{
	max_hp = amount;
}

void Character::set_basic_dmg(int amount)
{
	basic_dmg = amount;
}

void Character::set_basic_defensive(int amount)
{
	basic_defensive = amount;
}

// methods
