#include "warrior.h"

CWarrior::CWarrior(sf::RenderWindow& Window, std::string Asset_Path, bool Is_Animated, bool Debug_Mode)
	: CEntity(Window, Asset_Path, Is_Animated, Debug_Mode,
		"Warrior", 100, 100, 10, 10)
{}

auto CWarrior::handle_movement(float delta_time, CInput& Input) -> void
{
    float mMovement_Speed = Input.get_Movement_Speed() * delta_time;
    float mZero = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        set_Position(mZero, -mMovement_Speed); // up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        set_Position(-mMovement_Speed, mZero); // left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        set_Position(mZero, mMovement_Speed); // down
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        set_Position(mMovement_Speed, mZero); // right
    }
}
