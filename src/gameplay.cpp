#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& Window, CInput& Input)
    : mWindow(Window), mInput(Input), mCamera(Window)
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
    mEntities.push_back(std::move(std::make_unique<CGoblin>(mWindow)));
}

auto Gameplay::handle_mouse_input() -> void
{
    // TODO: add mouse input
}

auto Gameplay::update() -> void
{
    // add collusion class to detect collusion between entities
    float delta_time = mClock.restart().asSeconds();

    for (auto& entity : mEntities)
    {
        entity->get_Asset().draw();
    }
    mWarrior->handle_movement(delta_time, mInput);
    mWarrior->get_Asset().draw();
    mCamera.update(mWarrior.get());
}