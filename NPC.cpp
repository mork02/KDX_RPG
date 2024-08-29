#include "NPC.h"

NPC::NPC(std::string name_c, int hp_c, int basic_dmg_c, int basic_defensive_c, Zone zone_c) : name(name_c), zone(zone_c), stats(hp_c, basic_dmg_c, basic_defensive_c)
{
}

// getter

std::string NPC::get_name()
{
	return std::string();
}

Zone NPC::get_zone()
{
	return Zone();
}

// methods

