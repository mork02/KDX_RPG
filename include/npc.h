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

class CNPC : public CEntity
{
private:
    Zone mZone;

public:
    CNPC
    (sf::RenderWindow& Window, std::string Path, bool IsAnimated,
        std::string Name, int HP, int MaxHP, int BasicDMG, int BasicDEF,
        Zone Zone
    );

    auto get_zone() -> Zone;
};
