#include "entity.h"
#include "player_movement.h"

enum EAnimation_Warrior
{
	A_IDLE = 1,
	L_IDLE = 2,

	A_UP = 3,
	L_UP = 4,

	A_RIGHT = 3,
	L_RIGHT = 4,

	A_DOWN = 3,
	L_DOWN = 4,

	A_LEFT = 3,
	L_LEFT = 4
};

#pragma once
class CWarrior : public CEntity, public CPlayer_Movement
{
private:
	auto init_asset() -> void override;

public:
	CWarrior(sf::RenderWindow& Window);

	auto handle_animations() -> void override;
	auto update(float dt) -> void override;
};

