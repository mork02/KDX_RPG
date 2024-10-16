#include "npc.h"

NPC::NPC(std::string cName, int cHP, int cMax_HP, int cBasic_Dmg, int cBasic_Defensive, Zone cZone)
    : CEntity(cName, cHP, cMax_HP, cBasic_Dmg, cBasic_Defensive), zone(cZone)
{
}


auto NPC::get_zone() -> Zone
{
    return zone;  // Return the NPC's zone
}
