#include "player.h"

CPlayer::CPlayer(sf::RenderWindow& Window, CInput* Input) 
	: CEntity(Window, "assets/character_assets/test.png", true, true, "Advanturer", 100, 100, 0, 0), mInput(Input), CInventory()
{}

auto CPlayer::handle_movement(float delta_time) -> void
{
    float mMovement_Speed = mInput->get_Movement_Speed() * delta_time;
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
