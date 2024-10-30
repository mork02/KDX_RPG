#include "warrior.h"

CWarrior::CWarrior(sf::RenderWindow& Window) : 
    CEntity(Window,
	"Warrior", 100, 100, 10, 10)
{
    mAsset.init("assets/character_assets/AnimationSheet_Character.png", true, 1, 2);
    mAsset.set_Position(0, 0);
    mAsset.set_scale(6);
}

auto CWarrior::handle_movement(float delta_time, CInput& Input) -> void
{
    float mMovement_Speed = Input.get_Movement_Speed(delta_time);
    float mZero = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mAsset.set_Position(mZero, -mMovement_Speed); // up
    }
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A))
    {
        mAsset.set_Position(-mMovement_Speed, mZero); // left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mAsset.set_Position(mZero, mMovement_Speed); // down
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mAsset.set_Position(mMovement_Speed, mZero); // right
    }
}
