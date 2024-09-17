#include "entitie.h"

Entitie::Entitie(int hp_c, int basic_dmg_c, int basic_defensive_c) : hp(hp_c), max_hp(hp_c), basic_dmg(basic_dmg_c), basic_defensive(basic_defensive_c) {}

// Getter

int Entitie::get_hp() const { return hp; }

int Entitie::get_max_hp() const { return max_hp; }

int Entitie::get_basic_dmg() const { return basic_dmg; }

int Entitie::get_basic_defensive() const { return basic_defensive; }


// Setter

void Entitie::set_hp(int amount)
{
	hp = hp + amount;
	if (hp > max_hp) 
	{
		hp = max_hp;
	}
}

void Entitie::set_max_hp(int amount)
{
	max_hp = amount;
}

void Entitie::set_basic_dmg(int amount)
{
	basic_dmg = amount;
}

void Entitie::set_basic_defensive(int amount)
{
	basic_defensive = amount;
}

// methods
