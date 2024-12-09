#include "player.h"
#include "enums.h"

CPlayer::CPlayer(sf::RenderWindow& Window) :
    CEntity(Window, "User", 100, 100, 10, 10),
    Player_Movement()
{
    init_asset();
}

auto CPlayer::init_asset() -> void
{
    mAsset.init_animation("./assets/entities/AnimationSheet_Character.png", EAnimation_Warrior::A_IDLE, EAnimation_Warrior::L_IDLE);
    mAsset.set_origin_center();
}


auto CPlayer::render() -> void
{
    mAsset.render();
}

auto CPlayer::handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void
{
    Player_Movement.handle_events(Window, Event);
}

auto CPlayer::update(float delta_time) -> void
{
    mAsset.update();
    Player_Movement.update(delta_time, mAsset);
    mAsset.get_Sprite().setPosition(Player_Movement.get_position());
}
