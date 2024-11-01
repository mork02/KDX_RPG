#pragma once
#include "movement.h"

class CPlayer_Movement : public CMovement
{
public:
	CPlayer_Movement();

	auto handle_movement(float dt) -> void override;
	auto set_direction() -> void override;
	auto update() -> void override;

};

