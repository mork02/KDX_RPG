#pragma once
#include "SFML/Graphics.hpp"

class CMovement
{
protected:
	float mMove_Speed = 5.f;
	sf::Vector2f mPosition = { 0.f, 0.f };
	sf::Vector2f mDirection = { 0.f, 0.f };

public:
	virtual ~CMovement() {}

	virtual auto handle_movement(float dt) -> void = 0;
	virtual auto set_direction() -> void = 0;
	auto stop_movement() -> void { mDirection = sf::Vector2f(0.f, 0.f);}
	virtual auto update() -> void = 0;
};

