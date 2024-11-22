#include "game_manager.h"

CGameManager::CGameManager() :
	Window(sf::VideoMode(Resolution[Resolution_Index].first, Resolution[Resolution_Index].second), WINDOW_TITLE, sf::Style::Close), 
    Event(), StateManager(Window)
{
	Window.setFramerateLimit(FPS_Value);
	Window.setKeyRepeatEnabled(false);

    StateManager.set_state(StateManager.get_title_screen());
}

auto CGameManager::Run() -> void
{
    while (Window.isOpen())
    {
        float delta_time = Clock.restart().asSeconds();

        handle_events();
        render();
        update(delta_time);
        FPS.show_fps(Window);
    }
}

auto CGameManager::render() -> void
{
    Window.clear();

    StateManager.render();

    Window.display();
}

auto CGameManager::update(float delta_time) -> void
{
    StateManager.update(delta_time);
}

auto CGameManager::handle_events() -> void
{
    while (Window.pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed)    Window.close();
        configure_resolution();

        StateManager.handle_events(Event);
    }
}

auto CGameManager::configure_resolution() -> void {
    if (Event.type == sf::Event::KeyPressed) {
        switch (Event.key.code) {
        case sf::Keyboard::F2:
            if (Resolution_Index < Resolution.size() - 1) {
                Resolution_Index++;
                resize_window();
            }
            break;
        case sf::Keyboard::F1:
            if (Resolution_Index > 0) {
                Resolution_Index--;
                resize_window();
            }
            break;
        default:
            break;
        }
    }
}

auto CGameManager::resize_window() -> void
{
    auto [width, height] = Resolution.at(Resolution_Index);
    Window.setSize(sf::Vector2u(width, height));
}
