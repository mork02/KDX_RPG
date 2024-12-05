#include "gameplay_state.h"
#include "debug_manager.h"

CGameplay::CGameplay(sf::RenderWindow& Window)
    : mWindow(Window), mCamera(Window), MenuManager(Window)

{
    load_Entities();
    load_Level();
}

auto CGameplay::load_Level() -> void
{
    if (!tmx.LoadFromFile("assets/map/x.tmx")) {
        std::cout << "Error: Cant load map!" << std::endl;
    }
}

auto CGameplay::load_Entities() -> void
{
    mEntities.reserve(10);
    mEntities.push_back(std::move(std::make_unique<CGoblin>(mWindow)));
    mEntities.push_back(std::move(std::make_unique<CWarrior>(mWindow)));
}

auto CGameplay::handle_events(sf::Event& Event, CStateManager& StateManager) -> void
{
    if (!mPause)
    {
        for (auto& entity : mEntities)
        {
            entity->handle_events(mWindow, Event);
        }
    }
    MenuManager.handle_events(Event, &StateManager);
    if (Event.type == sf::Event::KeyPressed)
    {
        if (Event.key.code == sf::Keyboard::F10)
        {
            set_debugging(!mDebugging);
            mPause = !mPause;
        }
    }
}

auto CGameplay::render() -> void
{
    tmx.render(mWindow);
    for (auto& entity : mEntities)
    {
        entity->render();
        if (mDebugging)
        {
            CDebugManager::render(mWindow, entity.get());
            mCamera.reset();
        }
        else
        {
            mCamera.update(mEntities[1].get());
        }
    }

    MenuManager.render();
}

auto CGameplay::update(float delta_time) -> void
{
    if (!mPause)
    {
        for (auto& entity : mEntities)
        {
            entity->update(delta_time);
        }
    }

    
    // TODO: add collusion class to detect collusion between entities
}

auto CGameplay::set_debugging(bool Value) -> void
{
    mDebugging = Value;
}
