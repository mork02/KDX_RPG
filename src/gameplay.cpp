#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& Window)
    : mWindow(Window), mCamera(Window)
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

auto Gameplay::event_mouse(sf::Event& Event) -> void
{
    // TODO: add mouse input
}

auto Gameplay::event_keyboard(sf::Event& Event) -> void
{
    mWarrior->set_direction();
    if (Event.type == sf::Event::KeyReleased)   mWarrior->stop_movement();
}

auto Gameplay::update() -> void
{
    // TODO: add collusion class to detect collusion between entities

    for (auto& entity : mEntities)
    {
        entity->get_Asset().draw();
    }
    
    mWarrior->update(mClock.restart().asSeconds());
    // mCamera.update(mWarrior.get());
}