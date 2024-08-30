#include "Armor.h"

// init

Armor::Armor(std::string name_c, int defensive_c, int extra_defensive_c, int durability_c) : name(name_c), defensive(defensive_c), extra_defensive(extra_defensive_c), durability(durability_c) {}

// getter

std::string Armor::get_name() const { return name; }

int Armor::get_defensive() const { return defensive; }

int Armor::get_extra_defensive() const { return extra_defensive; }

int Armor::get_durability() const { return durability; }


// methods

void Armor::display_item() const
{
	try
	{
		std::cout << "Name: " << name << "\nDefensive: " << defensive << " + " << extra_defensive << "\nDurability: " << durability << "\n" << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << "No item equiped!" << std::endl;
	}
}
