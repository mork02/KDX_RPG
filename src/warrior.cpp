#include "warrior.h"


CWarrior::CWarrior(sf::RenderWindow& Window) :
    CEntity(Window,
	"Warrior", 100, 100, 10, 10)
{
    init_Asset();
}

auto CWarrior::init_Asset() -> void
{
    mAsset.init("assets/character_assets/AnimationSheet_Character.png", true, EAnimation::A_IDLE, EAnimation::L_IDLE);
    mAsset.set_debug(true);
    mAsset.set_scale(6);
    mAsset.set_origin_center();
    mAsset.get_Sprite().setPosition(500, 500);
}

auto CWarrior::handle_movement(float delta_time, CInput& Input) -> void
{
    float Movement_Speed = Input.get_Movement_Speed(delta_time);
    float Zero = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mAsset.set_Position(Zero, -Movement_Speed); // up
        mAsset.set_animation_param(EAnimation::A_UP, EAnimation::L_UP);
        return;
    }
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A))
    {
        mAsset.set_Position(-Movement_Speed, Zero); // left
        mAsset.set_animation_param(EAnimation::A_LEFT, EAnimation::L_LEFT);
        mAsset.set_direction(false);
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mAsset.set_Position(Zero, Movement_Speed); // down
        mAsset.set_animation_param(EAnimation::A_DOWN, EAnimation::L_DOWN);
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mAsset.set_Position(Movement_Speed, Zero); // right
        mAsset.set_animation_param(EAnimation::A_RIGHT, EAnimation::L_RIGHT);
        mAsset.set_direction(true);
        return;
    }

    mAsset.set_animation_param(EAnimation::A_IDLE, EAnimation::L_IDLE); // idle
}