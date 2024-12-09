#include "gameplay_state.h"
#include "debug_manager.h"
#include "player.h"

CGameplay::CGameplay(sf::RenderWindow& Window)
    : mWindow(Window), mCamera(Window), MenuManager(Window)

{
    EntityManager.prepare_vec(mWindow);
    load_Level();
}

auto CGameplay::load_Level() -> void
{
    if (!tmx.LoadFromFile("assets/map/x.tmx")) {
        std::cout << "Error: Cant load map!" << std::endl;
    }
}

auto CGameplay::handle_events(sf::Event& Event, CStateManager& StateManager) -> void
{
    if (!mPause)
    {
        EntityManager.handle_events(mWindow, Event);
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
    EntityManager.render();
    MenuManager.render();
}

auto CGameplay::update(float delta_time) -> void
{
    if (!mPause)
    {
        EntityManager.update(delta_time);
    }
    mPause = MenuManager.update(delta_time);
}

auto CGameplay::set_debugging(bool Value) -> void
{
    mDebugging = Value;
}
