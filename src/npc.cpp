#include "npc.h"

CNPC::CNPC(sf::RenderWindow& Window, std::string Name, int HP, int MaxHP, int BasicDMG, int BasicDEF, Zone Zone) :
    CEntity(Window, Name, HP, MaxHP, BasicDMG, BasicDEF),
    mZone(Zone) {}


auto CNPC::get_zone() -> Zone
{
    return mZone;
}
