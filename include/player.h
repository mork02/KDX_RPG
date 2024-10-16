#pragma once
#include "entity.h"
#include "inventory.h"
#include <iostream>

class CPlayer : public CEntity, public Inventory
{
private:

public:
    CPlayer();
};
