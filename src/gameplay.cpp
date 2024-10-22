#include "gameplay.h"

Gameplay::Gameplay(sf::RenderWindow& Window, CInput& Input) :
    mWindow(Window), mInput(Input)
{
    mPlayer = std::make_unique<CPlayer>(Window);
    mWarrior = std::make_unique<CWarrior>(Window);
    loadLevel();
    loadEntities();
}

auto Gameplay::loadEntities() -> void
{
    // mShown_Entities.push_back(mPlayer.get());
    mShown_Entities.push_back(mWarrior.get());
}

auto Gameplay::loadLevel() -> void
{

}

auto Gameplay::handle_mouse_input() -> void
{

}

auto Gameplay::update() -> void
{
    float delta_time = mClock.restart().asSeconds();
    for (auto& entities : mShown_Entities)
    {
        entities->draw();
        entities->handle_movement(delta_time, mInput);
    }
}
