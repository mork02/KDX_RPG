#include "npc.h"

NPC::NPC(std::string name_c, int hp_c, int basic_dmg_c, int basic_defensive_c, Zone zone_c)
    : name(name_c), zone(zone_c), Entitie(hp_c, basic_dmg_c, basic_defensive_c)
{
}

// Getter

auto NPC::get_name() -> std::string
{
    return name;  // Return the NPC's name
}

auto NPC::get_zone() -> Zone
{
    return zone;  // Return the NPC's zone
}
