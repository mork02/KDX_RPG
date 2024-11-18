#include "goblin.h"


CGoblin::CGoblin(sf::RenderWindow& Window) : 
    CEntity(Window, "Goblin", 15, 15, 3, 1)
{
    init_asset();
}

auto CGoblin::init_asset() -> void
{
    // TODO: add different spawn system
    // TODO: add goblin texture
    // TODO: add ai movement
    mAsset.init_animation("./assets/entities/goblin_idle.png", 1, 8, 64, 64);
    mAsset.set_debug(true);
    mAsset.set_origin_center();
    mAsset.get_Sprite().setPosition(500, 500);
}

auto CGoblin::render() -> void
{
    mAsset.draw();
}

auto CGoblin::handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void
{
}

auto CGoblin::update(float delta_time) -> void
{
}
