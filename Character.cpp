#include "Character.h"

Character::Character(int hp_c, int basic_dmg_c, int defensive_c, int extra_defensive_c) : hp(hp_c), max_hp(hp_c), basic_dmg(basic_dmg_c), defensive(defensive_c), extra_defensive(extra_defensive_c) {}

// Getter

int Character::get_hp()
{
	return hp;
}

int Character::get_max_hp()
{
	return max_hp;
}

int Character::get_basic_dmg()
{
	return basic_dmg;
}

int Character::get_defensive()
{
	return defensive;
}

int Character::get_extra_defensive()
{
	return extra_defensive;
}


// Setter

void Character::set_hp(int amount)
{
	hp = amount;
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

void Character::set_defensive(int amount)
{
	defensive = amount;
}

void Character::set_extra_defensive(int amount)
{
	extra_defensive = amount;
}


// methods
bool Character::check_death() 
{
	if (hp <= 0)
	{
		return true;
	}
	return false;
}