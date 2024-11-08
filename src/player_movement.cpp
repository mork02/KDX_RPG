#include "player_movement.h"
#include <iostream>

CPlayer_Movement::CPlayer_Movement() :
	CMovement()
{
	set_Position(250.f, 250.f);
}

auto CPlayer_Movement::handle_movement(float delta_time) -> void
{
	if (mDirection.x != 0 || mDirection.y != 0)
	{
		float magnitude = std::sqrt(mDirection.x * mDirection.x + mDirection.y * mDirection.y);
		mDirection.x /= magnitude;
		mDirection.y /= magnitude;
	}

	mPosition += mDirection * mMove_Speed * delta_time;

	//std::cout << "Position: " << mPosition.x << " | " << mPosition.y << std::endl;
	//std::cout << "Direction: " << mDirection.x << " | " << mDirection.y << std::endl;
}

auto CPlayer_Movement::set_direction(sf::Event& Event) -> void
{

	if (Event.type == sf::Event::KeyPressed)
	{
		if (Event.key.code == sf::Keyboard::W) mDirection.y = -1;
		if (Event.key.code == sf::Keyboard::A) mDirection.x = -1;
		if (Event.key.code == sf::Keyboard::S) mDirection.y = 1;
		if (Event.key.code == sf::Keyboard::D) mDirection.x = 1;
	}

	if (Event.type == sf::Event::KeyReleased)
	{
		if (Event.key.code == sf::Keyboard::W) mDirection.y = 0;
		if (Event.key.code == sf::Keyboard::A) mDirection.x = 0;
		if (Event.key.code == sf::Keyboard::S) mDirection.y = 0;
		if (Event.key.code == sf::Keyboard::D) mDirection.x = 0;
	}
}
