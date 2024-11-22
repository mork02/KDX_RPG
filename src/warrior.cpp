#include "warrior.h"
#include "enums.h"

CWarrior::CWarrior(sf::RenderWindow& Window) :
    CEntity(Window, "Warrior", 100, 100, 10, 10),
    Player_Movement()
{
    init_asset();
}

auto CWarrior::init_asset() -> void
{
    mAsset.init_animation("./assets/entities/AnimationSheet_Character.png", EAnimation_Warrior::A_IDLE, EAnimation_Warrior::L_IDLE);
    mAsset.set_origin_center();
}


auto CWarrior::render() -> void
{
    mAsset.render();
}

auto CWarrior::handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void
{
    Player_Movement.handle_events(Window, Event);
}

auto CWarrior::update(float delta_time) -> void
{
    Player_Movement.update(delta_time, mAsset);
    mAsset.get_Sprite().setPosition(Player_Movement.get_position());
}
