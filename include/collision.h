#pragma once
#include "entity.h"

class CCollision
{
public:
	static auto entity_check(CEntity* x, CEntity* y) -> bool; 
	// TODO: add collision between tilemap and player
};

