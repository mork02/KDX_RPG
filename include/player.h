#pragma once
#include <iostream>
#include "entity.h"
#include "inventory.h"
#include "input.h"

class CPlayer : public CEntity, public CInventory
{
private:

public:
    CPlayer(sf::RenderWindow& Window);

    auto handle_movement(float delta_time, CInput& Input) -> void override;
};
