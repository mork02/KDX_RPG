#include "entity.h"

enum EAnimation_Goblin
{
	A_SIT_FRONT = 1,
	L_SIT_FRONT = 3
};

#pragma once
class CGoblin : public CEntity
{
private:
	auto init_asset() -> void override;

public:
	CGoblin(sf::RenderWindow& Window);
};

