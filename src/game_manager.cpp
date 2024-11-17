#include "game_manager.h"

CGameManager::CGameManager() :
	Window(sf::VideoMode(Resolution[Resolution_Index].first, Resolution[Resolution_Index].second), WINDOW_TITLE, sf::Style::Close), Event(),
    Title_Screen(Window), Gameplay(Window)
{
	Window.setFramerateLimit(FPS_Value);
	Window.setKeyRepeatEnabled(false);
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

    switch (GameState)
    {
    case EGameState::TITLE_SCREEN:
        Title_Screen.render();
        break;
    case EGameState::GAMEPLAY:
        Gameplay.render();
        break;
    case EGameState::GAME_OVER:
        break;
    }

    Window.display();
}

auto CGameManager::update(float delta_time) -> void
{
    if (GameState == EGameState::TITLE_SCREEN) Title_Screen.update();
    if (GameState == EGameState::GAMEPLAY) Gameplay.update(delta_time);
}

auto CGameManager::set_GameState(EGameState NewGameState) -> void
{
    GameState = NewGameState;
}

auto CGameManager::handle_events() -> void
{
    while (Window.pollEvent(Event))
    {
        if (Event.type == sf::Event::Closed)    Window.close();
        configure_resolution();

        switch (GameState)
        {
        case EGameState::TITLE_SCREEN:
            Title_Screen.handle_events(this, &Event);
            break;
        case EGameState::GAMEPLAY:
            Gameplay.handle_events(this, &Event);
            break;
        case EGameState::GAME_OVER:
            break;
        default:
            break;
        }
    }
}

auto CGameManager::configure_resolution() -> void {
    if (Event.type == sf::Event::KeyPressed) {
        switch (Event.key.code) {
        case sf::Keyboard::Add:
            if (Resolution_Index < Resolution.size() - 1) {
                Resolution_Index++;
                auto [width, height] = Resolution.at(Resolution_Index);
                Window.setSize(sf::Vector2u(width, height));
            }
            break;
        case sf::Keyboard::Subtract:
            if (Resolution_Index > 0) {
                Resolution_Index--;
                auto [width, height] = Resolution.at(Resolution_Index);
                Window.setSize(sf::Vector2u(width, height));
            }
            break;
        default:
            break;
        }
    }
}
