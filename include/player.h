#pragma once
#include "entity.h"
#include "inventory.h"
#include "asset_loader.h"
#include <iostream>

class CPlayer : public CEntity, public CInventory
{
private:

public:
    CPlayer(sf::RenderWindow& Window);
};
