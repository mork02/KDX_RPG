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
}

auto CWarrior::handle_animations() -> void
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mAsset.set_animation_param(EAnimation_Warrior::A_UP, EAnimation_Warrior::L_UP);
        return;
    }

    if (sf::Keyboard::isKeyPressed (sf::Keyboard::A))    
    {
        mAsset.set_animation_param(EAnimation_Warrior::A_LEFT, EAnimation_Warrior::L_LEFT);
        mAsset.set_direction(false);
        return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mAsset.set_animation_param(EAnimation_Warrior::A_DOWN, EAnimation_Warrior::L_DOWN);
        return;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mAsset.set_animation_param(EAnimation_Warrior::A_RIGHT, EAnimation_Warrior::L_RIGHT);
        mAsset.set_direction(true);
        return;
    }

    mAsset.set_animation_param(EAnimation_Warrior::A_IDLE, EAnimation_Warrior::L_IDLE);
}

auto CWarrior::update(float dt) -> void
{
    handle_animations();
    handle_movement(dt);
    mAsset.set_Position(mPosition.x, mPosition.y);
    mAsset.draw();
}
