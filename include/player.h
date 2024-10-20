#pragma once
#include <iostream>
#include "entity.h"
#include "inventory.h"
#include "input.h"

class CPlayer : public CEntity, public CInventory
{
private:
    CInput* mInput;

public:
    CPlayer(sf::RenderWindow& Window, CInput* Input);

    auto handle_movement(float delta_time) -> void override;
};
