#include "npc.h"

CNPC::CNPC(sf::RenderWindow& Window, std::string Path, bool IsAnimated, bool Debug_Mode, std::string Name, int HP, int MaxHP, int BasicDMG, int BasicDEF, Zone Zone)
    : CEntity(Window, Path, IsAnimated, Debug_Mode, Name, HP, MaxHP, BasicDMG, BasicDEF),
    mZone(Zone) {}


auto CNPC::get_zone() -> Zone
{
    return mZone;
}
