#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& Window, CInput& Input)
    : mWindow(Window), mInput(Input)
{
    mWarrior = std::make_unique<CWarrior>(Window);
    loadEntities();
}

auto Gameplay::loadLevel() -> void
{
    // TODO: load level
}

auto Gameplay::loadEntities() -> void
{
    mEntities.reserve(10);
    mEntities.push_back(mWarrior.get());
}

auto Gameplay::handle_mouse_input() -> void
{
    // TODO: add mouse input
}

auto Gameplay::update() -> void
{
    float delta_time = mClock.restart().asSeconds();

    for (auto& entity : mEntities)
    {
        entity->handle_movement(delta_time, mInput);
        entity->get_Asset().draw();
    }
}