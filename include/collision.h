#pragma once
#include "entity.h"


class CCollision
{
public:
	static auto check_collision(CEntity* x, CEntity* y) -> bool; 
};

