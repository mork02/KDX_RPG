#pragma once
#include "SFML/Graphics.hpp"

class CMovement
{
protected:
	float mMove_Speed = 250.f;
	sf::Vector2f mPosition = { 0.f, 0.f };
	sf::Vector2f mDirection = { 0.f, 0.f };

public:
	virtual ~CMovement() {}

	auto get_Position() -> sf::Vector2f& { return mPosition; }
	auto get_Direction() -> sf::Vector2f& { return mDirection; }

	virtual auto handle_movement(float delta_time) -> void = 0;
	virtual auto set_direction(sf::Event& Event) -> void = 0;

};

