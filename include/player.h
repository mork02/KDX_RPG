#include "entity.h"
#include "player_movement.h"

#pragma once
class CPlayer : public CEntity
{
private:
	CPlayer_Movement Player_Movement;
	auto init_asset() -> void override;

public:
	CPlayer(sf::RenderWindow& Window);

	auto render() -> void override;
	auto handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void override;
	auto update(float delta_time) -> void override;
};

