#include "player_movement.h"
#include <iostream>

CPlayer_Movement::CPlayer_Movement()
{
}

auto CPlayer_Movement::handle_movement(float dt) -> void
{
	mPosition += mDirection * mMove_Speed * dt;
}

auto CPlayer_Movement::set_direction() -> void
{
	// TODO: fix movement maybe new one idk
	mDirection = sf::Vector2f(0.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))	mDirection.y = -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))	mDirection.x = -1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))	mDirection.y = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))	mDirection.x = 1;

	if (mDirection.x != 0.f || mDirection.y != 0.f)
	{
		float length = std::sqrt(mDirection.x * mDirection.x + mDirection.y * mDirection.y);
		mDirection.x /= length;
		mDirection.y /= length;
	}

}

auto CPlayer_Movement::update() -> void
{
	
}
