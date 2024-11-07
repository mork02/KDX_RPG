#pragma once
#include "movement.h"

class CPlayer_Movement : public CMovement
{
public:
	CPlayer_Movement();

	auto handle_movement(float delta_time) -> void override;
	auto set_direction(sf::Event& Event) -> void override;

};

