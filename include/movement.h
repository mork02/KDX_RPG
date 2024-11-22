#pragma once
#include "SFML/Graphics.hpp"
#include "asset_loader.h"
#include "enums.h"

class CMovement
{
protected:
	float mMovement_Speed = 96 * 4.f;
	sf::Vector2f mPosition = { 48.f, 48.f };
	bool mMoving = false;

	virtual auto handle_movement(float delta_time, CAsset_loader& Asset) -> void = 0;

public:
	virtual ~CMovement() {}

	auto get_position() -> sf::Vector2f& { return mPosition; }
	virtual auto update(float delta_time, CAsset_loader& Asset) -> void = 0;
};

