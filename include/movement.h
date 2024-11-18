#pragma once
#include "SFML/Graphics.hpp"
#include "asset_loader.h"
#include "enums.h"

class CMovement
{
protected:
	float mMovement_Speed = 250.f;
	sf::Vector2f mPosition = { 0.f, 0.f };

	virtual auto handle_movement(float delta_time, CAsset_loader& Asset) -> void = 0;

public:
	virtual ~CMovement() {}

	auto get_position() -> sf::Vector2f& { return mPosition; }
	virtual auto update(float delta_time, CAsset_loader& Asset) -> void = 0;
};

