#include "entity.h"
#include "player_movement.h"

#pragma once
class CWarrior : public CEntity
{
private:
	CPlayer_Movement Player_Movement;
	auto init_asset() -> void override;

public:
	CWarrior(sf::RenderWindow& Window);

	auto render() -> void override;
	auto handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void override;
	auto update(float delta_time) -> void override;
};

