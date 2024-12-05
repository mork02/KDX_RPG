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
    mAsset.init_animation("./assets/entities/goblin_idle.png", 1, 8);
    mAsset.set_origin_center();
    mAsset.get_Sprite().setPosition(700, 500);
}

auto CGoblin::render() -> void
{
    mAsset.render();
}

auto CGoblin::handle_events(sf::RenderWindow& Window, sf::Event& Event) -> void
{
}

auto CGoblin::update(float delta_time) -> void
{
    mAsset.update();
}
