#include "panel.h"

CPanel::CPanel(sf::RenderWindow& Window)
    : mWindow(Window),
    mTitle_Screen(Window),
    mGameplay(Window)
{}

auto CPanel::update(float delta_time) -> void
{
    switch (mCurrent_Scene)
    {
    case ESceneType::TITLE_SCREEN:
        mTitle_Screen.draw();
        break;
    case ESceneType::GAMEPLAY:
        mGameplay.update(delta_time);
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

auto CPanel::handle_events(sf::Event& Event) -> void
{
    if (Event.type == sf::Event::Closed)   event_close(Event);
    if (Event.type == sf::Event::KeyPressed)
    {
        if (mCurrent_Scene == ESceneType::GAMEPLAY) mGameplay.event_keyboard(Event);
        handle_window_resolution();
    }
    event_mouse(Event);
}

auto CPanel::event_close(sf::Event& Event) -> void
{
    if (Event.type == sf::Event::Closed)    mWindow.close();
}

auto CPanel::event_mouse(sf::Event& Event) -> void
{
    if (Event.type == sf::Event::MouseButtonPressed)
    {
        if (Event.mouseButton.button == sf::Mouse::Left)
        {
            if (mCurrent_Scene == ESceneType::TITLE_SCREEN) mTitle_Screen.handle_click_event(*this);
            if (mCurrent_Scene == ESceneType::GAMEPLAY) mGameplay.event_mouse(Event, this);
        }
    }

}

auto CPanel::handle_window_resolution() -> void
{
    // handle keyboard input for changing Window Resolution
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))   mWindow.setSize(sf::Vector2u(1280, 720));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2))   mWindow.setSize(sf::Vector2u(1366, 768));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))   mWindow.setSize(sf::Vector2u(1920, 1080));
}