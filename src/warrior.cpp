#include "warrior.h"


CWarrior::CWarrior(sf::RenderWindow& Window) :
    CEntity(Window,
	"Warrior", 100, 100, 10, 10)
{
    init_asset();
}

auto CWarrior::init_asset() -> void
{
    mAsset.init("assets/character_assets/AnimationSheet_Character.png", true, EAnimation_Warrior::A_IDLE, EAnimation_Warrior::L_IDLE);
    mAsset.set_debug(true);
    mAsset.set_scale(3);
    mAsset.set_origin_center();
    mAsset.get_Sprite().setPosition(500, 500);
}

auto CWarrior::handle_movement(float delta_time, CInput& Input) -> void
{
    // TODO: make thos in the event loop
    float Movement_Speed = Input.get_Movement_Speed(delta_time);
    float Zero = 0.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mAsset.set_Position(Zero, -Movement_Speed); // up
        mAsset.set_animation_param(EAnimation_Warrior::A_UP, EAnimation_Warrior::L_UP);
        return;
    }
    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A))
    {
        mAsset.set_Position(-Movement_Speed, Zero); // left
        mAsset.set_animation_param(EAnimation_Warrior::A_LEFT, EAnimation_Warrior::L_LEFT);
        mAsset.set_direction(false);
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mAsset.set_Position(Zero, Movement_Speed); // down
        mAsset.set_animation_param(EAnimation_Warrior::A_DOWN, EAnimation_Warrior::L_DOWN);
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mAsset.set_Position(Movement_Speed, Zero); // right
        mAsset.set_animation_param(EAnimation_Warrior::A_RIGHT, EAnimation_Warrior::L_RIGHT);
        mAsset.set_direction(true);
        return;
    }

    mAsset.set_animation_param(EAnimation_Warrior::A_IDLE, EAnimation_Warrior::L_IDLE); // idle
}