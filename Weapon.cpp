#include "Weapon.h"

// init

Weapon::Weapon(std::string name_c, int dmg_c, int extra_dmg_c, int durability_c) : name(name_c), dmg(dmg_c), extra_dmg(extra_dmg_c), durability(durability_c), Item(Category::WEAPON) {}

// getter

 // int Weapon::get_id() const { return id; }

std::string Weapon::get_name() const { return name; }

int Weapon::get_dmg() const { return dmg; }

int Weapon::get_extra_dmg() const { return extra_dmg; }

int Weapon::get_durability() const { return durability; }

// methods

void Weapon::display_item() const
{
	try
	{
		std::cout << "Name: " << name << "\nDmg: " << dmg << " + " << extra_dmg << "\nDurability: " << durability << "\n" << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "No item equiped!" << std::endl;
	}
}