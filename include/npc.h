#pragma once
#include <iostream>
#include "entity.h"

enum class Zone
{
    FIRST_ZONE,
    SECOND_ZONE,
    THIRD_ZONE,
    FOURTH_ZONE,
    FIFTH_ZONE
};

class NPC : public CEntity
{
private:
    Zone zone;

public:
    NPC(std::string name, int hp, int max_hp, int basic_dmg, int basic_defensive, Zone zone);

    auto get_zone() -> Zone;
};
