#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& Window, CInput& Input) :
    mWindow(Window), mInput(Input)
{
    mPlayer = std::make_unique<CPlayer>(Window, &Input);
    loadLevel();
    loadEntities();
}

auto Gameplay::loadEntities() -> void
{
    mShown_Entities.push_back(mPlayer.get());
}

auto Gameplay::loadLevel() -> void
{

}

auto Gameplay::handle_mouse_input(sf::Event* current_event) -> void
{

}

auto Gameplay::update() -> void
{
    float delta_time = mClock.restart().asSeconds();
    for (auto& entities : mShown_Entities)
    {
        entities->draw();
        entities->handle_movement(delta_time);
    }
}
