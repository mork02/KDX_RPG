#include "npc.h"

CNPC::CNPC(sf::RenderWindow& Window, std::string Path, bool IsAnimated, unsigned Row, unsigned Frame_Length, std::string Name, int HP, int MaxHP, int BasicDMG, int BasicDEF, Zone Zone)
    : CEntity(Window, Path, IsAnimated, Row, Frame_Length, Name, HP, MaxHP, BasicDMG, BasicDEF),
    mZone(Zone) {}


auto CNPC::get_zone() -> Zone
{
    return mZone;
}
