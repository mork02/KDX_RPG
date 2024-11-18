#pragma once
#include "movement.h"

class CPlayer_Movement : public CMovement
{
protected:
	sf::Vector2f mTargeted_Position = { 0.f, 0.f };
	
	auto handle_movement(float delta_time, CAsset_loader& Asset) -> void override;

public:
	CPlayer_Movement();

	auto handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void;
	auto update(float delta_time, CAsset_loader& Asset) -> void override;
};

