#include "entity.h"
#include "player_movement.h"
#include "enums.h"

#pragma once
class CWarrior : public CEntity, public CPlayer_Movement
{
private:
	auto init_asset() -> void override;
	auto handle_animations() -> void override;

public:
	CWarrior(sf::RenderWindow& Window);

	auto render() -> void override;
	auto update(float delta_time) -> void override;
};

