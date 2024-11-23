#include "gameplay_state.h"
#include "debug_manager.h"

CGameplay::CGameplay(sf::RenderWindow& Window)
    : mWindow(Window), mCamera(Window), MenuManager(Window)

{
    load_Entities();
}

auto CGameplay::load_Level() -> void
{
    sf::Color color1 = sf::Color(190, 190, 190);
    sf::Color color2 = sf::Color(100, 100, 100);

    for (unsigned y = 0; y < mWindow.getSize().y; y += 96)
    {
        for (unsigned x = 0; x < mWindow.getSize().x; x += 96)
        {
            sf::RectangleShape rect(sf::Vector2f(96, 96));
            rect.setPosition(static_cast<float>(x), static_cast<float>(y));

            if ((x / 96 + y / 96) % 2 == 0)
            {
                rect.setFillColor(color1);
            }
            else
            {
                rect.setFillColor(color2);
            }

            mWindow.draw(rect);
        }
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
    for (auto& entity : mEntities)
    {
        entity->handle_events(mWindow, Event);
    }
    MenuManager.handle_events(Event, &StateManager);
    if (Event.type == sf::Event::KeyPressed)
    {
        if (Event.key.code == sf::Keyboard::F10)
        {
            set_debugging(!mDebugging);
        }
    }
}

auto CGameplay::render() -> void
{
    load_Level();
    for (auto& entity : mEntities)
    {
        entity->render();
        if (mDebugging) CDebugManager::render(mWindow, entity.get());
    }

    MenuManager.render();
}

auto CGameplay::update(float delta_time) -> void
{

    for (auto& entity : mEntities)
    {
        entity->update(delta_time);
    }

    
    // TODO: add collusion class to detect collusion between entities
}

auto CGameplay::set_debugging(bool Value) -> void
{
    mDebugging = Value;
}
