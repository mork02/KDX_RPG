#include "panel.h"

CPanel::CPanel(sf::RenderWindow& Window, sf::Event& Event)
    : mWindow(Window), mEvent(Event),
    mTitle_Screen(Window),
    mGameplay(Window)
{}

auto CPanel::update() -> void
{
    switch (mCurrent_Scene)
    {
    case ESceneType::TITLE_SCREEN:
        mTitle_Screen.draw();
        break;
    case ESceneType::GAMEPLAY:
        mGameplay.update();
        break;
    case ESceneType::GAME_OVER:
        break;
    }
}

auto CPanel::get_gameplay() -> CGameplay&
{
    return mGameplay;
}

auto CPanel::set_scene(ESceneType new_scene) -> void
{
    mCurrent_Scene = new_scene;
}

// events // 

auto CPanel::handle_events() -> void
{
    switch (mEvent.type)
    {
        case sf::Event::Closed:
            event_close();
            break;

        case sf::Event::KeyPressed:
            event_keyboard();
            break;

        case sf::Event::KeyReleased:
            break;

        case sf::Event::MouseButtonPressed:
            event_mouse();
            break;

        case sf::Event::MouseButtonReleased:
            break;

        default:
            break;
        }
}

auto CPanel::event_close() -> void
{
    if (mEvent.type == sf::Event::Closed)
    {
        mWindow.close();
    }
}

auto CPanel::event_mouse() -> void
{
    if (mEvent.mouseButton.button == sf::Mouse::Left)
    {
        if (mCurrent_Scene == ESceneType::TITLE_SCREEN)
        {
            // handle left click on Titlescreen //
            mTitle_Screen.handle_click_event(*this);
        }
        if (mCurrent_Scene == ESceneType::GAMEPLAY)
        {
            // handle left click on Gameplay //
            mGameplay.event_mouse(mEvent, this);
        }
    }
    if (mEvent.mouseButton.button == sf::Mouse::Right)
    {
        // handle right clicks //
    }

}

auto CPanel::event_keyboard() -> void
{
    if (mCurrent_Scene == ESceneType::GAMEPLAY)
    {
        mGameplay.event_keyboard(mEvent);
    }
    handle_window_resolution();
}

auto CPanel::handle_window_resolution() -> void
{
    // handle keyboard input for changing Window Resolution
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))   mWindow.setSize(sf::Vector2u(1280, 720));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))   mWindow.setSize(sf::Vector2u(1366, 768));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))   mWindow.setSize(sf::Vector2u(1920, 1080));
}